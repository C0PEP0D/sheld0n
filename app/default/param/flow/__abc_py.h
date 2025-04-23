#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

// include thirdparty
#include "pybind11/embed.h"
#include "pybind11/numpy.h"
#include "pybind11/stl.h"
namespace py = pybind11;
using namespace pybind11::literals;

namespace c0p {

struct Flow {

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		tSpaceVector u = tSpaceVector::Zero();
		// python
		py::gil_scoped_acquire acquire;
		auto locals = py::dict(
			"x"_a = py::array_t<double>(DIM, pX, py::capsule(pX, [](void* ptr) {})),
			"t"_a = t,
			"u"_a = py::array_t<double>(DIM, u.data(), py::capsule(u.data(), [](void* ptr) {}))
		);
		py::exec(R"(
			sys.path.append('param/flow')
			import parameters
			
			u[:] = parameters.get_velocity(x, t)
		)", py::globals(), locals);
		// output
		return u;
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		tSpaceMatrix j = tSpaceMatrix::Zero();
		// python
		py::gil_scoped_acquire acquire;
		auto locals = py::dict(
			"x"_a = py::array_t<double>(DIM, pX, py::capsule(pX, [](void* ptr) {})),
			"t"_a = t,
			"j"_a = py::array_t<double>(DIM * DIM, j.data(), py::capsule(j.data(), [](void* ptr) {}))
		);
		py::exec(R"(
			sys.path.append('param/flow')
			import parameters
			
			j[:] = parameters.get_velocity_gradients(x, t).transpose().flatten()
		)", py::globals(), locals);
		// output
		return j;
	};

	// prepare
	static void prepare(const double* pState, const unsigned int stateSize, const double t) {
		// nothing to do
	}

	static void prepareVelocity(const double* pX, const double t) {
		// nothing to do
	}
	
	static void prepareVelocityGradients(const double* pX, const double t) {
		// nothing to do
	}
};

}

#endif
