// app includes
// // env
#include "param/parameters.h"
#include "core/core.h"
// // learn
#include "param/learn/parameters.h"
// python
#include "pybind11/embed.h"
namespace py = pybind11;

int main () {
	// python
	py::scoped_interpreter python;
	py::gil_scoped_release release;
	// declare
	typename c0p::LearnParameters::RLParameters::tDevice device;
	typename c0p::LearnParameters::RLParameters::tIndex seed = 0;
	typename c0p::LearnParameters::RLParameters::tLoopState ls;
	// init
	rlt::malloc(device, ls);
	rlt::init(device, ls, seed);
	// run
	while(!rlt::step(device, ls)) {
	}
}
