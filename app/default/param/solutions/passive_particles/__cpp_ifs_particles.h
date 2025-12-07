#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"

// ---------------- INCLUDE OTHER PARAM START
#include "param/solutions/point_vortices/parameters.h"
#include "param/run/parameters.h"
// ---------------- INCLUDE OTHER PARAM END

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START

	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = 16;// EnvParameters::cGroupSize; // number of members in the group
	static constexpr double ReactionLength = 1.0;
	static constexpr double Width = std::pow(2, -3);
	// periodicity
	inline static const tSpaceVector periodCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector periodSize = EnvParameters::cDomainSize;
	inline static const std::array<bool, DIM> isAxisPeriodic = EnvParameters::cDomainIsAxisPeriodic;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[0].data() + memberStateIndex;
			
			// ---------------- CUSTOM CONSTRAIN START

			// input

			tView<tSpaceVector> x(pState);

			// periodicity
			
			x = sp0ce::xPeriodic<tSpaceVector>(x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());

			// flow coupling

			using PointVorticesParameters = _PointVorticesParameters;
			
			const tView<const tSpaceVector> v(pState + DIM);
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
	
			const tSpaceVector dVelocity = -(u - v) * (u - v).norm() / Width * RunParameters::Dt;
			PointVorticesParameters::tGroupVariable::addVelocity(x.data(), dVelocity.data(), Width);
			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	using tGroupVariable = d0t::VariableGroupStatic<d0t::VariableComposed<tMemberVariable>, Number>;
	using tVariable = tGroupVariable;

	struct tMemberEquation : public d0t::Equation<tMemberVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {

			// ---------------- CUSTOM PREPARATION START

			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);

			// ---------------- CUSTOM PREPARATION END
		}
	
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, const unsigned int memberIndex) {
			// static input
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[0] + StateIndex, memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// input
			const tView<const tSpaceVector> x(pState);
			const tView<const tSpaceVector> v(pState + DIM);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceVector> dV(dState.data() + DIM);
			dX = v;
			dV = (u - v) * (u - v).norm() / ReactionLength;
			
			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}
	};
	using tGroupEquation = d0t::EquationGroupStatic<tGroupVariable, tMemberEquation>;
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START
	inline static const tSpaceVector BoxCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector BoxSize = EnvParameters::cDomainSize;
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START

		// interpret BoxCenter and BoxSize as vectors
		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
		// loop over each member of the variable group
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			// get the state variable of the subIndex member of the group
			double* pMemberState = tVariable::state(pState, subIndex);
			// interpret subState as a tSpaceVector
			tView<tSpaceVector> x(pMemberState);
			tView<tSpaceVector> v(pMemberState + DIM);
			// set the initial position of this member
			x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
			v = tSpaceVector::Zero();
		}

		// ---------------- CUSTOM INIT END
	}

	inline static unsigned int FormatNumber = int(std::log10(Number)) + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;

		// ---------------- CUSTOM POST START

		tSpaceVector xAverage = tSpaceVector::Zero();
		tSpaceVector vAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			const double* pMemberState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pMemberState);
			const tView<const tSpaceVector> v(pMemberState + DIM);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(FormatNumber) << std::setfill('0') << subIndex;
			// output
			for(unsigned int i = 0; i < DIM; ++i) {
				output[ossIndex.str() + "__pos_" + std::to_string(i)] = x[i];
				output[ossIndex.str() + "__vel_" + std::to_string(i)] = v[i];
			}
			// compute average
			xAverage += x;
			vAverage += v;
		}
		xAverage /= Number;
		vAverage /= Number;
		for(unsigned int i = 0; i < DIM; ++i) {
			output["passive_particles__average_pos_" + std::to_string(i)] = xAverage[i];
			output["passive_particles__average_vel_" + std::to_string(i)] = vAverage[i];
		}

		// ---------------- CUSTOM POST END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
