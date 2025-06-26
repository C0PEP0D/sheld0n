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

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	static constexpr double AspectRatio = 1.0; // aspect ratio of the spheroidal particles
	static constexpr double Factor = (AspectRatio*AspectRatio - 1.0) / (AspectRatio*AspectRatio + 1.0); // factor used in the equation
	static constexpr float SwimmingVelocity = 0.5;
	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
		
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[0].data() + memberStateIndex;
			// ---------------- CUSTOM CONSTRAIN START
			tView<tSpaceVector> p(pState + DIM);
			p.normalize();
			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	using tGroupVariable = d0t::VariableGroupStatic<d0t::VariableComposed<tMemberVariable>, Number>;
	using tVariable = tGroupVariable;

	// definition of the member data
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
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[0] + StateIndex, memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START
			// input
			const tView<const tSpaceVector> x(pState);
			const tView<const tSpaceVector> p(pState + DIM);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			const tSpaceMatrix grad = Flow::getVelocityGradients(x.data(), t);
			const tSpaceMatrix symGrad = 0.5 * (grad + grad.transpose());
			const tSpaceMatrix skewGrad = 0.5 * (grad - grad.transpose());
			// output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceVector> dP(dState.data() + DIM);
			dX = u + SwimmingVelocity * p.normalized();
			dP = skewGrad * p + Factor * (symGrad * p - (p.dot(symGrad * p)) * p);
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
			tView<tSpaceVector> p(pMemberState + DIM);
			// set the initial position of this member
			x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
			p = tSpaceVector::Random().normalized(); // TODO: this should use a Gaussian distribution using EigenRand
		}
		// ---------------- CUSTOM INIT END
	}

	inline static unsigned int FormatNumber = int(std::log10(Number)) + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM POST START
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			const double* pMemberState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pMemberState);
			const tView<const tSpaceVector> p(pMemberState + DIM);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(FormatNumber) << std::setfill('0') << subIndex;
			// output
			output[ossIndex.str() + "__pos_0"] = x[0];
			output[ossIndex.str() + "__pos_1"] = x[1];
			output[ossIndex.str() + "__dir_0"] = p[0];
			output[ossIndex.str() + "__dir_1"] = p[1];
			// compute average
						xAverage += x;
		}
		xAverage /= Number;
		output["passive_particles__average_pos_0"] = xAverage[0];
		output["passive_particles__average_pos_1"] = xAverage[1];
		// ---------------- CUSTOM POST END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
