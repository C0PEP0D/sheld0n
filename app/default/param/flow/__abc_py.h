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
	
	static tSpaceVector getAcceleration(const double* pX, const double t) {
		tSpaceVector a = tSpaceVector::Zero();
		// python
		py::gil_scoped_acquire acquire;
		auto locals = py::dict(
			"x"_a = py::array_t<double>(DIM, pX, py::capsule(pX, [](void* ptr) {})),
			"t"_a = t,
			"a"_a = py::array_t<double>(DIM, a.data(), py::capsule(a.data(), [](void* ptr) {}))
		);
		py::exec(R"(
			sys.path.append('flow')
			import parameters
			
			a[:] = parameters.get_acceleration(x, t)
		)", py::globals(), locals);
		// output
		return a;
	};
};

}

#endif
