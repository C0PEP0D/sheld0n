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

// include thirdparty
#include "pybind11/embed.h"
#include "pybind11/numpy.h"
#include "pybind11/stl.h"
namespace py = pybind11;
using namespace pybind11::literals;

namespace c0p {

struct _PassiveParticlesParameters {
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	// ---------------- CUSTOM EQUATION PARAMETERS END

	// definition of the member data
	using tSubVariable = d0t::VariableComposed<d0t::VariableVector<tVector, tView, StateSize>>;
	struct tSubEquation : public d0t::Equation<tSubVariable> {
		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariable::Size);

			/// ---------------- CUSTOM EQUATION START
			
			// input
			const tView<const tSpaceVector> x(pState);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			const tSpaceMatrix grad = Flow::getVelocityGradients(x.data(), t);

			// python
			
			py::gil_scoped_acquire acquire;
			auto locals = py::dict(
				"state"_a = py::array_t<double>(tVariable::Size, pState, py::capsule(pState, [](void* ptr) {})),
				"u"_a = py::array_t<double>(DIM, u.data(), py::capsule(u.data(), [](void* ptr) {})),
				"grad_u"_a = py::array_t<double>(DIM * DIM, grad.data(), py::capsule(grad.data(), [](void* ptr) {})),
				"dstate"_a = py::array_t<double>(tVariable::Size, dState.data(), py::capsule(dState.data(), [](void* ptr) {}))
			);
			py::exec(R"(
				sys.path.append('param/solutions/passive_particles')
				import parameters
				
				dstate[:] = parameters.state_temporal_derivative(state, u, grad_u)
			)", py::globals(), locals);
	
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
		py::gil_scoped_acquire acquire;
		auto locals = py::dict(
			"state"_a = py::array_t<double>(Number * StateSize, pState, py::capsule(pState, [](void* ptr) {})),
			"particle_state_size"_a = StateSize,
			"particle_number"_a = Number
		);
		py::exec(R"(
			sys.path.append('param/solutions/passive_particles')
			import parameters
			
			state[:] = parameters.init(particle_state_size, particle_number)
		)", py::globals(), locals);
		// ---------------- CUSTOM INIT END
	}

	// static constexpr unsigned FormatNumber = std::ceil(Number/10.0); // compatibility issue with Clang
	static constexpr unsigned FormatNumber = Number/10 + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		// ---------------- CUSTOM POST START
		py::gil_scoped_acquire acquire;
		auto locals = py::dict(
			"state"_a = py::array_t<double>(Number * StateSize, pState, py::capsule(pState, [](void* ptr) {})),
			"particle_state_size"_a = StateSize,
			"particle_number"_a = Number,
			"output"_a = py::dict()
		);
		py::exec(R"(
			sys.path.append('param/solutions/passive_particles')
			import parameters
			
			output = parameters.post(state, particle_state_size, particle_number)
		)", py::globals(), locals);
		// ---------------- CUSTOM POST END
		return locals["output"].cast<std::map<std::string, tScalar>>();
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
