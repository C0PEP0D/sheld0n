#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>
// app includes
#include "core/solutions/prop.h"
#include "core/solutions/core.h"
#include "param/flow/parameters.h"
#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"
// nn
#include "core/learn/neural_network/core.h"

namespace c0p {

// TODO : adapt that to be run in parallel !

struct _PassiveParticlesParameters {
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static constexpr double SwimmingVelocity = 0.5;
	static constexpr std::array<double, DIM> TargetDirection = {0.0, 1.0}; // defined for 2D simulations, use {0.0, 1.0, 0.0} for 3D
	// ---------------- CUSTOM EQUATION PARAMETERS END

	// definition of the member data
	using tVariable = d0t::VariableVector<tVector, tView, StateSize>;
	struct tEquation : public d0t::Equation<tVariable> {
		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariable::Size);

			// ---------------- CUSTOM EQUATION START			
			// input
			const tView<const tSpaceVector> x(pState);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			const tSpaceMatrix grad = Flow::getVelocityGradients(x.data(), t);
			// compute
			// // observation
			set(NeuralNetwork::input, 0, 0, TargetDirection[0]);
			set(NeuralNetwork::input, 0, 1, TargetDirection[1]);
			set(NeuralNetwork::input, 0, 2, grad(0, 0));
			set(NeuralNetwork::input, 0, 3, grad(0, 1));
			set(NeuralNetwork::input, 0, 4, grad(1, 0));
			set(NeuralNetwork::input, 0, 5, grad(1, 1));
			// // evaluation
			const tView<const tSpaceVector> n(NeuralNetwork::evaluate());
			// output
			tView<tSpaceVector> dX(dState.data());
			dX = u + n.normalized() * SwimmingVelocity;
			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}
	};

	// ---------------- CUSTOM INIT PARAMETERS START
	static constexpr std::array<double, DIM> BoxCenter = {0.0, 0.0}; // defined for 2D simulation, use {0.0, 0.0, 0.0} for 3D
	static constexpr std::array<double, DIM> BoxSize = {2.0 * M_PI, 2.0 * M_PI}; // defined for 2D simulation, use {2.0 * M_PI, 2.0 * M_PI,  2.0 * M_PI} for 3D
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START
		// interpret BoxCenter and BoxSize as vectors
		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
		// interpret state as a tSpaceVector
		tView<tSpaceVector> x(pState);
		// set the initial position of this member
		x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM POST START
		const tView<const tSpaceVector> x(pState);
		output["passive_particles__pos_0"] = x[0];
		output["passive_particles__pos_1"] = x[1];
		// ---------------- CUSTOM POST END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
