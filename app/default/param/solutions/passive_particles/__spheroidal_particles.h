#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <format>

// app includes
#include "core/solutions/prop.h"
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"

namespace c0p {

struct _PassiveParticlesParameters {
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	static constexpr double AspectRatio = 1.0; // aspect ratio of the spheroidal particles
	static constexpr double Factor = (AspectRatio*AspectRatio - 1.0) / (AspectRatio*AspectRatio + 1.0); // factor used in the equation
	// ---------------- CUSTOM EQUATION PARAMETERS END

	// definition of the member data
	using tSubVariable = d0t::VariableComposed<d0t::VariableVector<tVector, tView, StateSize>>;
	struct tSubEquation : public d0t::Equation<tSubVariable> {
		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariable::Size);

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
			dX = u;
			dP = skewGrad * p + Factor * (symGrad * p - (p.dot(symGrad * p)) * p);
			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}
	};
	// creating tVariable and tEquation
	using tVariable = d0t::VariableGroupStatic<tSubVariable, Number>;
	using tEquation = d0t::EquationGroupStatic<tVariable, tSubEquation>;

	// ---------------- CUSTOM INIT PARAMETERS START
	static constexpr std::array<double, DIM> BoxCenter = {0.0, 0.0}; // defined for 2D simulation, use {0.0, 0.0, 0.0} for 3D
	static constexpr std::array<double, DIM> BoxSize = {2.0 * M_PI, 2.0 * M_PI}; // defined for 2D simulation, use {2.0 * M_PI, 2.0 * M_PI,  2.0 * M_PI} for 3D
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START
		// interpret BoxCenter and BoxSize as vectors
		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
		// loop over each member of the variable group
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			// get the state variable of the subIndex member of the group
			double* pSubState = tVariable::state(pState, subIndex);
			// interpret subState as a tSpaceVector
			tView<tSpaceVector> x(pSubState);
			tView<tSpaceVector> p(pSubState + DIM);
			// set the initial position of this member
			x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
			p = tSpaceVector::Random().normalized(); // TODO: this should use a Gaussian distribution using EigenRand
		}
		// ---------------- CUSTOM INIT END
	}

	// static constexpr unsigned FormatNumber = std::ceil(Number/10.0); // compatibility issue with Clang
	static constexpr unsigned FormatNumber = Number/10 + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM POST START
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			const double* pSubState = tVariable::cState(pState, subIndex);
			const tView<const tSpaceVector> x(pSubState);
			const tView<const tSpaceVector> p(pSubState + DIM);
			output["passive_particles__index_" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__pos_0"] = x[0];
			output["passive_particles__index_" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__pos_1"] = x[1];
			output["passive_particles__index_" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__dir_0"] = p[0];
			output["passive_particles__index_" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__dir_1"] = p[1];
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
