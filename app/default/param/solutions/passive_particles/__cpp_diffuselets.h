#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// lib includes
#include "sp0ce/bin.h" // bin

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"

// FLAG: DYNAMIC

// TODO: wrong, need to integrate L and Tau and inverse to get what you want in the right direction

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM + DIM * DIM + DIM * DIM; // x, L, Tau
	// feel free to add parameters if you need
	inline static const double Diffusivity = 1.0;
	inline static const double InitMaxC = 1.0; // TODO: should be a state variable rather than a parameter (or use tau)
	inline static const double InitW = 1.0;
	static constexpr unsigned int Dx = 4.0;
	// ---------------- CUSTOM EQUATION PARAMETERS END

	using Bin = sp0ce::Bin<DIM>;
	inline static Bin bin = Bin(Dx);

	// variable

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;
			// ---------------- CUSTOM CONSTRAIN START
			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);
			Flow::prepareVelocityGradients(cX.data(), t);
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
			
			// // remove dead points
			// for(int index = tBase::groupSize(_state.size()) - 1; index > -1; index--) {
			// 	const double* pState = tBase::cState(_state.data(), index);
			// 	const double tLife = *(pState + DIM);
			// 	if (tLife < 0.0) {
			// 		tBase::eraseMember(_state, index);
			// 	}
			// }
			// // add points based on rate
			// if (_state.empty()) {
			// 	_spawn(_state, 1);
			// } else {
			// 	const double* pStateLast = tBase::cState(_state.data(), tBase::groupSize(_state.size()) - 1);
			// 	const double tLifeLast = *(pStateLast + DIM);
			// 	const unsigned int number = int((Lifetime - tLifeLast) * Rate);
			// 	if (number > 0) {
			// 		_spawn(_state, number);
			// 	}
			// }
			
			// ---------------- CUSTOM CONSTRAIN END
			
		}
		
		// static void _spawn(std::vector<double>& _state, unsigned int number) {
		// 	for (unsigned int index = 0; index < number; index++) {
		// 		tBase::pushBackMember(_state);
		// 		// set initial state
		// 		double* pState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);
		// 		tView<tSpaceVector> x(pState);
		// 		double* pTLife = pState + DIM;
		// 		// // set
		// 		x = tSpaceVector::Random();
		// 		for(unsigned int index = 0; index < DIM; ++index){
		// 			x[index] = x[index] * 0.5 * Length[index] + Center[index];
		// 		}
		// 		*pTLife = Lifetime;
		// 	}
		// }

		static double c(const double* pState, const unsigned int stateSize, const double* pX) {
			// input
			const tView<const tSpaceVector> x(pX);
			// get indexs
			const std::array<int, DIM> ijk = bin.positionToIjk(x.data());
			const std::vector<std::array<int, DIM>> neighborIjk = bin.ijkToNeighborIjk(ijk.data());
			// compute
			double output = 0.0;
			for(const std::array<int, DIM>& _ijk : neighborIjk) {
				auto itIjkToIndexes = bin.ijkToIndexes.find(_ijk);
				if(itIjkToIndexes != bin.ijkToIndexes.end()) {
					for(unsigned int& index : bin.ijkToIndexes[_ijk]) {
						// input
						const double* pMemberState = tBase::cState(pState, index);
						const tView<const tSpaceVector> memberX(pMemberState);
						const tView<const tSpaceMatrix> memberL(pState + DIM);
						const tView<const tSpaceMatrix> memberTau(pState + DIM + DIM * DIM);
						// compute
						const tSpaceVector r = x - memberX;
						const tSpaceMatrix memberLInverse = memberL.inverse();
						// concentration
						output += InitMaxC / std::sqrt(memberTau.determinant()) * std::exp(-r.transpose() * memberTau.inverse() * memberLInverse.transpose() * memberLInverse * r);
					}
				}
			}
			return output;
		}

		static tSpaceVector cGradient(const double* pState, const unsigned int stateSize, const double* pX) {
			// input
			const tView<const tSpaceVector> x(pX);
			// get indexs
			const std::array<int, DIM> ijk = bin.positionToIjk(x.data());
			const std::vector<std::array<int, DIM>> neighborIjk = bin.ijkToNeighborIjk(ijk.data());
			// compute
			tSpaceVector output = tSpaceVector::Zero();
			for(const std::array<int, DIM>& _ijk : neighborIjk) {
				auto itIjkToIndexes = bin.ijkToIndexes.find(_ijk);
				if(itIjkToIndexes != bin.ijkToIndexes.end()) {
					for(unsigned int& index : bin.ijkToIndexes[_ijk]) {
						// input
						const double* pMemberState = tBase::cState(pState, index);
						const tView<const tSpaceVector> memberX(pMemberState);
						const tView<const tSpaceMatrix> memberL(pState + DIM);
						const tView<const tSpaceMatrix> memberTau(pState + DIM + DIM * DIM);
						// compute
						const tSpaceVector r = x - memberX;
						const tSpaceMatrix memberLInverse = memberL.inverse();
						// concentration
						const tSpaceMatrix m = memberTau.inverse() * memberLInverse.transpose() * memberLInverse;
						output += -(m.transpose() + m) * r * c(pState, stateSize, pX);
					}
				}
			}
			return output;
		}
	};
	using tVariable = tGroupVariable;

	// equation

	struct tMemberEquation : public d0t::Equation<tMemberVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// ---------------- CUSTOM PREPARATION START
			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);
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
			const tView<const tSpaceMatrix> l(pState + DIM);
			const tView<const tSpaceMatrix> tau(pState + DIM + DIM * DIM);
			// // flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			const tSpaceMatrix j = Flow::getVelocityGradients(x.data(), t);
			// // utils
			const tSpaceVector uD = ( Diffusivity / tGroupVariable::c(pGroupState, groupStateSize, x.data()) ) * tGroupVariable::cGradient(pGroupState, groupStateSize, x.data());
			// // output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceMatrix> dL(dState.data() + DIM);
			tView<tSpaceMatrix> dTau(dState.data() + DIM + DIM * DIM);
			dX = u + uD;
			dL = -j.transpose();
			dTau = 4.0 * Diffusivity / std::pow(InitW, 2) * l.transpose() * l;

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
			
			// bin
			bin.clear();
			for(unsigned int index = 0; index < tGroupVariable::groupSize(stateSize); ++index) {
				const double* pMemberState = tGroupVariable::cState(pState, index);
				const tView<const tSpaceVector> x(pMemberState);
				bin.addIndex(index, x.data());
			}

			// ---------------- CUSTOM PREPARATION END
		}
	};
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(std::vector<double>& state) {
		// ---------------- CUSTOM INIT START

		{ // 0
			tGroupVariable::pushBackMember(state);
			// set initial state
			double* pState = tGroupVariable::state(state.data(), tGroupVariable::groupSize(state.size()) - 1);
			// x
			tView<tSpaceVector> x(pState);
			tView<tSpaceMatrix> l(pState + DIM);
			tView<tSpaceMatrix> tau(pState + DIM + DIM * DIM);
			x = tSpaceVector({0.5, 0.0});
			l = tSpaceMatrix::Identity();
			tau = tSpaceMatrix::Identity();
		}

		{ // 1
			tGroupVariable::pushBackMember(state);
			// set initial state
			double* pState = tGroupVariable::state(state.data(), tGroupVariable::groupSize(state.size()) - 1);
			// x
			tView<tSpaceVector> x(pState);
			tView<tSpaceMatrix> l(pState + DIM);
			tView<tSpaceMatrix> tau(pState + DIM + DIM * DIM);
			x = tSpaceVector({-0.5, 0.0});
			l = tSpaceMatrix::Identity();
			tau = tSpaceMatrix::Identity();
		}
		
		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		unsigned int number = tVariable::groupSize(stateSize);
		unsigned int formatNumber = int(std::log10(number)) + 1;
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < number; ++subIndex) {
			const double* pMemberState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pMemberState);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(formatNumber) << std::setfill('0') << subIndex;
			// output
			output[ossIndex.str() + "__pos_0"] = x[0];
			output[ossIndex.str() + "__pos_1"] = x[1];
			output[ossIndex.str() + "__c"] = tGroupVariable::c(pState, stateSize, x.data());
			// compute average
			xAverage += x;
		}
		xAverage /= number;
		output["passive_particles__average_pos_0"] = xAverage[0];
		output["passive_particles__average_pos_1"] = xAverage[1];
		// ---------------- CUSTOM INIT END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
