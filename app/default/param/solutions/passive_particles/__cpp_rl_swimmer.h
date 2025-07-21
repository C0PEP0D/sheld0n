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

// rl include
#include <rl_tools/operations/cpu_mux.h>

namespace rlt = rl_tools;

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START

	static const unsigned StateSize = DIM + DIM + DIM; // position + target direction + swimming direction
	// feel free to add parameters if you need
	static constexpr double SwimmingVelocity = 0.5;
	// rl
	static constexpr unsigned int ObservationDim = DIM + DIM * DIM; // target direction + flow velocity gradients
	static constexpr unsigned int ActionDim = DIM; // swimming direction

	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int stateIndex) {
			// input
			double* pState = stateArray[0].data() + stateIndex;

			// ---------------- CUSTOM CONSTRAIN START

			// ---------------- CUSTOM CONSTRAIN END
		}

	};

	struct tEquation : public d0t::Equation<tVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {

			// ---------------- CUSTOM PREPARATION START

			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);

			// ---------------- CUSTOM PREPARATION END
		}
	
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
			// static input
			const unsigned int stateSize = tVariable::Size;
			const double* pState = pStateArray[0] + StateIndex;
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// input
			const tView<const tSpaceVector> x(pState);
			const tView<const tSpaceVector> z(pState + DIM);
			const tView<const tSpaceVector> n(pState + 2 * DIM);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// output
			tView<tSpaceVector> dX(dState.data());
			dX = u + n.normalized() * SwimmingVelocity;

			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}
	};

	// ---------------- CUSTOM INIT PARAMETERS START
	inline static const tSpaceVector BoxCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector BoxSize = EnvParameters::cDomainSize;
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {

		// ---------------- CUSTOM INIT START

		// interpret BoxCenter and BoxSize as vectors
		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
		// interpret state as a tSpaceVector
		tView<tSpaceVector> x(pState);
		tView<tSpaceVector> z(pState + DIM);
		tView<tSpaceVector> n(pState + 2 * DIM);
		// set the initial position of this member
		x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
		z = tSpaceVector::Random().normalized();
		n = z;

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

	// reinforcement learning

	template<typename tObsSpec>
	static void observe(const double* pState, const double t, rlt::Matrix<tObsSpec>& observation) {

		// ---------------- CUSTOM OBSERVE START

		// input
		const tView<const tSpaceVector> x(pState);
		const tView<const tSpaceVector> z(pState + DIM);
		const tSpaceMatrix grad = Flow::getVelocityGradients(x.data(), t);
		// target direction
		set(observation, 0, 0, z[0]);
		set(observation, 0, 1, z[1]);
		// flow velocity gradients
		set(observation, 0, 2, grad(0, 0));
		set(observation, 0, 3, grad(0, 1));
		set(observation, 0, 4, grad(1, 0));
		set(observation, 0, 5, grad(1, 1));

		// ---------------- CUSTOM OBSERVE END
	}

	template<typename tActionSpec>
	static void act(const rlt::Matrix<tActionSpec>& action, double* pState) {

		// ---------------- CUSTOM ACT START

		tView<tSpaceVector> n(pState + 2 * DIM);
		std::copy(action._data, action._data + DIM, n.data());

		// ---------------- CUSTOM ACT END
	}

	static double reward(const double* pState, const double* pNextState) {

		// ---------------- CUSTOM REWARD START

		const tView<const tSpaceVector> x(pState);
		const tView<const tSpaceVector> z(pState + DIM);
		const tView<const tSpaceVector> n(pState + 2 * DIM);
		const tView<const tSpaceVector> nextX(pNextState);
		return (nextX - x).dot(z) + 0.001 * -std::abs(n.norm() - 1.0);

		// ---------------- CUSTOM REWARD END
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
