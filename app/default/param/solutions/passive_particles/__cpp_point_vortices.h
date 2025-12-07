#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>
#include <mutex>

// lib includes
#include "sp0ce/operators.h"

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"
#include "param/run/parameters.h"

// // ---------------- INCLUDE OTHER SOLUTION START

// #include "param/solutions/ifs_particles/parameters.h"

// // ---------------- INCLUDE OTHER SOLUTION END

// FLAG: DYNAMIC

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START

	static const unsigned StateSize = DIM + 1; // dimension of the state variable 
	// domain
	inline static const tSpaceVector domainCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector domainSize = EnvParameters::cDomainSize;
	inline static const std::array<bool, DIM> isAxisPeriodic = EnvParameters::cDomainIsAxisPeriodic;
	// point removal
	static const bool IsRemovingPointsOutOfDomain = false;
	// merge of points
	static const bool IsMergingNeighborPoints = false;
	// jet source
	static const bool HasJetSource = false;
	inline static const tSpaceVector JetSourcePosition = domainCenter;
	inline static const tSpaceVector JetSourceVelocity = {1.0, 0.0};
	inline static const tSpaceVector JetSourceDirection = JetSourceVelocity.normalized();
	inline static const double JetSourceWidth = domainSize[1] / 8;
	inline static const double JetSourceReactionTime = 1.0;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	inline static std::mutex _addedVelocityMutex;
	inline static std::vector<double> _addedVelocity;

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {

		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;
			// ---------------- CUSTOM CONSTRAIN START

			tView<tSpaceVector> x(pState);
			x = sp0ce::xPeriodic<tSpaceVector>(x.data(), domainCenter.data(), domainSize.data(), isAxisPeriodic.data());

			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	struct tGroupVariable : public d0t::VariableGroupDynamic<tMemberVariable> {
		using tBase = d0t::VariableGroupDynamic<tMemberVariable>;

		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int stateIndex) {
			tBase::_constrain(stateArray, t, stateIndex);
			// input
			std::vector<double>& _state = stateArray[StateIndex];

			// ---------------- CUSTOM CONSTRAIN START

			// physics

			if(HasJetSource) {
				const tSpaceVector dVelocity = (JetSourceVelocity - Flow::getVelocity(JetSourcePosition.data(), t)) * RunParameters::Dt / JetSourceReactionTime;
				
				if(true || dVelocity.dot(JetSourceDirection) > 0.0) {
					addVelocity(JetSourcePosition.data(), dVelocity.data(), JetSourceWidth);
				}
			}

			if (not _addedVelocity.empty()) { // ifs
				_addedVelocityMutex.lock();

				_state.insert(_state.end(), _addedVelocity.begin(), _addedVelocity.end());
				_addedVelocity.clear();
				
				_addedVelocityMutex.unlock();
			}

			// numerics

			if(IsRemovingPointsOutOfDomain) {
				for(int index = tBase::groupSize(_state.size()) - 1; index > -1; index--) {
					const double* pState = tBase::cState(_state.data(), index);
					const tView<const tSpaceVector> x(pState);
					for(unsigned int i = 0; i < DIM; ++i) {
						if(std::abs(x[i] - domainCenter[i]) > 0.5 * EnvParameters::cDomainSize[i]) {
							tBase::eraseMember(_state, index);
							break;
						}
					}
				}
			}

			if(IsMergingNeighborPoints) {
				Flow::prepare(_state.data(), tBase::groupSize(_state.size()));
				_state = Flow::flow.superStateArray[0];
			}

// 			using IfsParticlesParameters = _IfsParticlesParameters;
// 			const double* pIfsParticlesState = stateArray[0].data() + IfsParticlesParameters::StateIndex;
// 			
// 			for(unsigned int index = 0; index < IfsParticlesParameters::Number; ++index) {
// 			
// 				const double* pState = IfsParticlesParameters::tGroupVariable::cState(pIfsParticlesState, index);
// 
// 				// input
// 				const tView<const tSpaceVector> x(pState);
// 				const tView<const tSpaceVector> v(pState + DIM);
// 				// flow
// 				const tSpaceVector u = Flow::getVelocity(x.data(), t);
// 	
// 				// apply "force" on flow
// 				const tSpaceVector dVelocity = -(u - v) * (u - v).norm() / IfsParticlesParameters::Width * RunParameters::Dt;
// 				_addVelocity(_state, x.data(), dVelocity.data(), IfsParticlesParameters::Width);
// 				
// 			}

			// ---------------- CUSTOM CONSTRAIN END
		}
		
		static void addVelocity(const double* pPosition, const double* pDVelocity, const double spacing) {
			// input
			const tView<const tSpaceVector> position(pPosition);
			const tView<const tSpaceVector> dVelocity(pDVelocity);
			const double dVelocityNorm = dVelocity.norm();
			if(dVelocityNorm > 0.0) {
				const tSpaceVector dVelocityDirection = dVelocity / dVelocityNorm;
				const tSpaceVector dVelocityOrthogonal = tSpaceVector({-dVelocityDirection[1], dVelocityDirection[0]});
				// circulation
				const double dCirculation = 0.5 * M_PI * spacing * dVelocityNorm; // constrain needs t
				{ // positive
					_addedVelocityMutex.lock();

					tBase::pushBackMember(_addedVelocity);

					_addedVelocityMutex.unlock();
					// set initial state
					double* pState = tBase::state(_addedVelocity.data(), tBase::groupSize(_addedVelocity.size()) - 1);
					tView<tSpaceVector> x(pState);
					double* pCirculation = pState + DIM;
					// // set
					x = position + 0.5 * spacing * dVelocityOrthogonal;
					*pCirculation = dCirculation;
				}
				{ // negative
					_addedVelocityMutex.lock();

					tBase::pushBackMember(_addedVelocity);

					_addedVelocityMutex.unlock();
					// set initial state
					double* pState = tBase::state(_addedVelocity.data(), tBase::groupSize(_addedVelocity.size()) - 1);
					tView<tSpaceVector> x(pState);
					double* pCirculation = pState + DIM;
					// // set
					x = position - 0.5 * spacing * dVelocityOrthogonal;
					*pCirculation = -dCirculation;
				}
			}
		}
	};
	using tVariable = tGroupVariable;

	struct tMemberEquation : public d0t::Equation<tMemberVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// ---------------- CUSTOM PREPARATION START

			// prepare velocity just in case

			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);

			// ---------------- CUSTOM PREPARATION END
		}
	
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, const unsigned int memberIndex) {
			// static input
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[StateIndex], memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// input
			const tView<const tSpaceVector> x(pState);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			const double w = pState[DIM];
			// output
			tView<tSpaceVector> dX(dState.data());
			dX = u;

			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}
	};
	struct tGroupEquation : public d0t::EquationGroupDynamic<tVariable, tMemberEquation> {

		using tBase = d0t::EquationGroupDynamic<tVariable, tMemberEquation>;
	
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			tBase::prepare(pState, stateSize, t);
			// prepare flow
			Flow::prepare(pState, tGroupVariable::groupSize(stateSize));
		}
	};
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START

	static const unsigned int InitNumber = EnvParameters::cGroupSize;
	static constexpr double InitCirculation = 1.0/InitNumber;
	inline static const tSpaceVector InitCenter = EnvParameters::cDomainCenter - tSpaceVector({0.5 * EnvParameters::cDomainSize[0], 0.0});
	static const bool IsInitRandomInDomain = true;
	inline static const tSpaceVector InitSize = EnvParameters::cDomainSize;
	static const bool IsInitDipole = false;
	inline static const double InitPoleRadius = 0.125 * EnvParameters::cDomainSize[1];
	inline static const double InitDipoleSpacing = 0.75 * EnvParameters::cDomainSize[1];

	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(std::vector<double>& p_state) {
		// ---------------- CUSTOM INIT START

		if(IsInitRandomInDomain) {
			for(unsigned int subIndex = 0; subIndex < InitNumber; ++subIndex) {
				tGroupVariable::pushBackMember(p_state);
				// set initial state
				double* pState = tGroupVariable::state(p_state.data(), tGroupVariable::groupSize(p_state.size()) - 1);
				tView<tSpaceVector> x(pState);
				double& w = pState[DIM];
				// set the initial position of this member
				x = InitCenter + 0.5 * InitSize.asDiagonal() * tSpaceVector::Random();
				w = InitCirculation * tVector<1>::Random()[0];
			}
		}

		if(IsInitDipole) {
			const unsigned int halfNumber = InitNumber / 2;
			for(unsigned int index = 0; index < halfNumber; ++index) {
				tGroupVariable::pushBackMember(p_state);
				// get the state variable of the index member of the group
				double* pMemberState = tVariable::state(p_state.data(), index);
				// interpret subState as a tSpaceVector
				tView<tSpaceVector> x(pMemberState);
				double& w = pMemberState[DIM];
				// set the initial position of this member
				x = InitCenter + tSpaceVector({0.0, 0.5 * InitDipoleSpacing}) + InitPoleRadius * tSpaceVector({
					std::cos(index * 2 * M_PI / halfNumber), 
					std::sin(index * 2 * M_PI / halfNumber)
				});
				w = InitCirculation;
			}
			for(unsigned int index = 0; index < (InitNumber - halfNumber); ++index) {
				tGroupVariable::pushBackMember(p_state);
				// get the state variable of the index member of the group
				double* pMemberState = tVariable::state(p_state.data(), index + halfNumber);
				// interpret subState as a tSpaceVector
				tView<tSpaceVector> x(pMemberState);
				double& w = pMemberState[DIM];
				// set the initial position of this member
				x = InitCenter - tSpaceVector({0.0, 0.5 * InitDipoleSpacing}) + InitPoleRadius * tSpaceVector({
					std::cos(index * 2 * M_PI / (InitNumber - halfNumber)), 
					std::sin(index * 2 * M_PI / (InitNumber - halfNumber))
				});
				w = -InitCirculation;
			}
		}

		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;

		// ---------------- CUSTOM POST START

		unsigned int number = tVariable::groupSize(stateSize);
		unsigned int formatNumber = int(std::log10(number)) + 1;

		tSpaceVector xAverage = tSpaceVector::Zero();
		double wAverage = 0.0;

		for(unsigned int subIndex = 0; subIndex < number; ++subIndex) {
			const double* pMemberState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pMemberState);
			const double w = pMemberState[DIM];
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(formatNumber) << std::setfill('0') << subIndex;
			// output
			for(unsigned int i = 0; i < DIM; ++i) {
				output[ossIndex.str() + "__pos_" + std::to_string(i)] = x[i];
			}
			output[ossIndex.str() + "__circulation"] = w;
			// compute average
			xAverage += x;
			wAverage += w;
		}
		xAverage /= number;
		for(unsigned int i = 0; i < DIM; ++i) {
			output["passive_particles__average_pos_" + std::to_string(i)] = xAverage[i];
		}
		output["passive_particles__average_circulation"] = wAverage;

		// ---------------- CUSTOM POST END

		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
