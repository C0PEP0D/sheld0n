#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>

// app includes
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
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[0].data() + memberStateIndex;
			// ---------------- CUSTOM CONSTRAIN START
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
			// ---------------- CUSTOM PREPARATION END
		}
		
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, const unsigned int memberIndex) {
			// static input
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[0] + StateIndex, memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			/// ---------------- CUSTOM EQUATION START
			
			// input
			const tView<const tSpaceVector> x(pState);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);

			// python
			
			py::gil_scoped_acquire acquire;
			auto locals = py::dict(
				"state"_a = py::array_t<double>(tVariable::Size, pState, py::capsule(pState, [](void* ptr) {})),
				"u"_a = py::array_t<double>(DIM, u.data(), py::capsule(u.data(), [](void* ptr) {})),
				"dstate"_a = py::array_t<double>(tVariable::Size, dState.data(), py::capsule(dState.data(), [](void* ptr) {}))
			);
			py::exec(R"(
				sys.path.append('param/solutions/passive_particles')
				import parameters
				
				dstate[:] = parameters.state_temporal_derivative(state, u)
			)", py::globals(), locals);
	
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

	inline static unsigned int FormatNumber = int(std::log10(Number)) + 1;

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
