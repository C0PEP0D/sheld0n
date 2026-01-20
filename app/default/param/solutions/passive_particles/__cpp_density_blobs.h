#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// lib includes
#include "pl0f/density_field.h"

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"

#include "param/parameters.h"
#include "param/run/parameters.h"

// FLAG: DYNAMIC

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned int StateSize = 2 * DIM + 2 * DIM * DIM + 1; // (x, v), (s, ds), q WARNING: order is important here !
	inline static const double Rigidity = 1e2;
	inline static const double Friction = 2e-1;
	inline static const double Density0 = 1.0;

	// resolution
	inline static const double Dx = 1.0e-2;

	// init
	static const bool HasInit = true;
	inline static const tSpaceVector InitX = tSpaceVector::Zero();
	inline static const double InitC = 1.0;
	inline static const tSpaceMatrix InitS = tSpaceVector({1.0e-1, 1.0e-1}).asDiagonal();

	// periodicity
	inline static const tSpaceVector periodCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector periodSize = EnvParameters::cDomainSize;
	inline static const std::array<bool, DIM> isAxisPeriodic = EnvParameters::cDomainIsAxisPeriodic;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	// scalar field
	using DensityField = pl0f::DensityField<DIM, tSpaceVector, tSpaceMatrix, tView>;
	inline static DensityField densityField = DensityField(Dx, false, periodCenter, periodSize, isAxisPeriodic); // false for testing

	// added scalar
	inline static std::mutex _addedQMutex;
	inline static std::vector<double> _addedQ;

	// variable

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;

			// ---------------- CUSTOM CONSTRAIN START

			tView<tSpaceVector> x(pState);
			x = sp0ce::xPeriodic<tSpaceVector>(x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());

			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	struct tGroupVariable : public d0t::VariableGroupDynamic<tMemberVariable> {
		using tBase = d0t::VariableGroupDynamic<tMemberVariable>;

		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int stateIndex) {
			tBase::_constrain(stateArray, t, stateIndex);
			// input
			std::vector<double>& _state = stateArray[stateIndex];

			// ---------------- CUSTOM CONSTRAIN START

			// physics

			if (not _addedQ.empty()) { // addQ
				_addedQMutex.lock();

				_state.insert(_state.end(), _addedQ.begin(), _addedQ.end());
				_addedQ.clear();
				
				_addedQMutex.unlock();
			}

			// ---------------- CUSTOM CONSTRAIN END
		}

		static void addQ(const double* pPosition, const double* pS, const double dQ) {
			// input
			const tView<const tSpaceVector> position(pPosition);
			const tView<const tSpaceMatrix> s(pS);
			// q
			if(dQ != 0.0) {
				_addedQMutex.lock();

				tBase::pushBackMember(_addedQ);

				// set initial state
				double* pNewState = tBase::state(_addedQ.data(), tBase::groupSize(_addedQ.size()) - 1);
				
				tView<tSpaceVector> newX(pNewState);
				tView<tSpaceVector> newV(pNewState + DIM);
				tView<tSpaceMatrix> newS(pNewState + 2 * DIM);
				tView<tSpaceMatrix> newDS(pNewState + 2 * DIM + DIM * DIM);
				double& newQ = pNewState[2 * (DIM + DIM * DIM)];
				
				// // set
				newX = position;
				newV = tSpaceVector::Zero();
				newS = s;
				newDS = tSpaceMatrix::Zero();
				newQ = dQ;

				_addedQMutex.unlock();
			}
		}

		static double density(const double* pState, const unsigned int stateSize, const double* pX) {
			return densityField.getDensity(tBase::cState(pState, 0), tBase::groupSize(stateSize), pX);
		}

		static tSpaceVector densityGradient(const double* pState, const unsigned int stateSize, const double* pX) {
			return densityField.getGradient(tBase::cState(pState, 0), tBase::groupSize(stateSize), pX);
		}

		static tSpaceVector velocity(const double* pState, const unsigned int stateSize, const double* pX) {
			return densityField.getVelocity(tBase::cState(pState, 0), tBase::groupSize(stateSize), pX);
		}
	};
	using tVariable = tGroupVariable;

	// equation

	struct tMemberEquation : public d0t::Equation<tMemberVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// ---------------- CUSTOM PREPARATION START
			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);
			Flow::prepareVelocityGradients(cX.data(), t);
			// ---------------- CUSTOM PREPARATION END
		}
	
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, const unsigned int memberIndex) {
			// static input
			const unsigned int groupStateSize = pStateSize[StateIndex];
			const double* pGroupState = pStateArray[StateIndex];
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[StateIndex], memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// advection
			// // input
			const tView<const tSpaceVector> x(pState);
			const tView<const tSpaceVector> v(pState + DIM);
			const tView<const tSpaceMatrix> s(pState + 2 * DIM);
			const tView<const tSpaceMatrix> ds(pState + 2 * DIM + DIM * DIM);
			const double q = pState[2 * (DIM + DIM * DIM)];
			// // // flow
			// const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// const tSpaceMatrix j = Flow::getVelocityGradients(x.data(), t);
			// // density
			const double density = tGroupVariable::density(pGroupState, groupStateSize, x.data());
			const tSpaceVector densityGradient = tGroupVariable::densityGradient(pGroupState, groupStateSize, x.data());
			const tSpaceVector velocity = tGroupVariable::velocity(pGroupState, groupStateSize, x.data());
			// // output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceVector> dV(dState.data() + DIM);
			tView<tSpaceMatrix> dS(dState.data() + 2 * DIM);
			tView<tSpaceMatrix> dDS(dState.data() + 2 * DIM + DIM * DIM);
			double& dQ = dState[2 * (DIM + DIM * DIM)];

			dX = v;
			dV = Rigidity * (Density0 - density) * densityGradient + Friction * (velocity - 2.0 * v); // TODO: integrals ?
			dS = ds;
			dDS = tSpaceMatrix::Zero();
			dQ = 0.0;

			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}

	};
	struct tGroupEquation : public d0t::EquationGroupDynamic<tVariable, tMemberEquation> {
		using tBase = d0t::EquationGroupDynamic<tVariable, tMemberEquation>;
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			tBase::prepare(pState, stateSize, t);

			// ---------------- CUSTOM PREPARATION START
			
			densityField.prepare(tGroupVariable::cState(pState, 0), tGroupVariable::groupSize(stateSize));

			// ---------------- CUSTOM PREPARATION END
		}
	};
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START
	
	// ---------------- CUSTOM INIT PARAMETERS END

	static void init(std::vector<double>& state) {
		// ---------------- CUSTOM INIT START

		if (HasInit) {
			{ // 0
				tGroupVariable::pushBackMember(state);
				// set initial state
				double* pState = tGroupVariable::state(state.data(), tGroupVariable::groupSize(state.size()) - 1);
				// define
				tView<tSpaceVector> x(pState);
				tView<tSpaceVector> v(pState + DIM);
				tView<tSpaceMatrix> s(pState + 2 * DIM);
				tView<tSpaceMatrix> ds(pState + 2 * DIM + DIM * DIM);
				double& q = pState[2 * (DIM + DIM * DIM)];
				// set
				x = InitX + 0.5 * EnvParameters::cDomainSize;
				x[0] -= 1.25e-1 * EnvParameters::cDomainSize[0];
				s = InitS;
				q = InitC * (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(s.determinant()));
				v = -EnvParameters::cDomainSize.normalized();
				ds = tSpaceMatrix::Zero();
			}
			
			{ // 1
				tGroupVariable::pushBackMember(state);
				// set initial state
				double* pState = tGroupVariable::state(state.data(), tGroupVariable::groupSize(state.size()) - 1);
				// define
				tView<tSpaceVector> x(pState);
				tView<tSpaceVector> v(pState + DIM);
				tView<tSpaceMatrix> s(pState + 2 * DIM);
				tView<tSpaceMatrix> ds(pState + 2 * DIM + DIM * DIM);
				double& q = pState[2 * (DIM + DIM * DIM)];
				// set
				x = InitX - 0.0 * 0.25 * EnvParameters::cDomainSize;
				s = InitS;
				q = InitC * (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(s.determinant()));
				v = 0.0 * EnvParameters::cDomainSize.normalized();
				ds = tSpaceMatrix::Zero();
			}
		}
		
		// ---------------- CUSTOM INIT END
	}

	// ---------------- CUSTOM POST PARAMETERS START

	inline static const bool IsPostProcessingParticles = false;
	inline static const bool IsPostProcessingConcentration = true && IsPostProcessingParticles;
	inline static const bool IsPostProcessingConcentrationOnGrid = true;
	inline static const unsigned int GridN = 128;

	// ---------------- CUSTOM POST PARAMETERS START

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		densityField.prepare(tGroupVariable::cState(pState, 0), tGroupVariable::groupSize(stateSize));

		if(IsPostProcessingParticles) { // particles
			unsigned int number = tVariable::groupSize(stateSize);
			unsigned int formatNumber = int(std::log10(number)) + 1;
			
			for(unsigned int index = 0; index < number; ++index) {
				const double* pMemberState = tVariable::cState(pState, index);
				// input
				const tView<const tSpaceVector> x(pMemberState);
				const tView<const tSpaceVector> v(pMemberState + DIM);
				const tView<const tSpaceMatrix> s(pMemberState + 2 * DIM);
				const tView<const tSpaceMatrix> ds(pMemberState + 2 * DIM + DIM * DIM);
				const double& q = pMemberState[2 * (DIM + DIM * DIM)];
				// generate formated index
				std::ostringstream ossIndex;
				ossIndex << "passive_scalar_blobs__index_" << std::setw(formatNumber) << std::setfill('0') << index;
				// output
				for(unsigned int i = 0; i < DIM; ++i) {
					output[ossIndex.str() + "__pos_" + std::to_string(i)] = x[i];
					for(unsigned int j = 0; j < DIM; ++j) {
						output[ossIndex.str() + "__s_" + std::to_string(i) + "_" + std::to_string(j)] = s(i, j);
					}
				}
				output[ossIndex.str() + "__c0"] = q / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(s.determinant()));
				if(IsPostProcessingConcentration) {
					output[ossIndex.str() + "__c"] = tGroupVariable::density(pState, stateSize, x.data());
				}
			}
		}

		if(IsPostProcessingConcentrationOnGrid) { // profile
			const unsigned int formatNumber = int(std::log10(GridN)) + 1;

			const double dx = EnvParameters::cDomainSize[0]/GridN;
			const double dy = EnvParameters::cDomainSize[1]/GridN;
			
			for(unsigned int i = 0; i < GridN; ++i) {
				for(unsigned int j = 0; j < GridN; ++j) {
					tSpaceVector x = tSpaceVector::Zero();
					x[0] = -0.5 * EnvParameters::cDomainSize[0] + EnvParameters::cDomainCenter[0] + i * dx;
					x[1] = -0.5 * EnvParameters::cDomainSize[1] + EnvParameters::cDomainCenter[1] + j * dy;
					// generate formated i and j
					std::ostringstream ossIndex;
					ossIndex << "grid_c__i_" << std::setw(formatNumber) << std::setfill('0') << i << "_j_" << std::setw(formatNumber) << std::setfill('0') << j;
					// output
					output[ossIndex.str() + "__x"] = x[0];
					output[ossIndex.str() + "__y"] = x[1];
					output[ossIndex.str() + "__c"] = tGroupVariable::density(pState, stateSize, x.data());
					output[ossIndex.str() + "__n"] = tVariable::groupSize(stateSize);
				}
			}
		}
		
		// ---------------- CUSTOM INIT END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
