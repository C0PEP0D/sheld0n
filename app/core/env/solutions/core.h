#ifndef C0P_CORE_ENV_SOLUTIONS_CORE_H
#define C0P_CORE_ENV_SOLUTIONS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
#include <execution>
// lib includes
#include "d0t/equation.h"
// app includes
#include "core/env/solutions/prop.h"

namespace c0p {

template<typename tParameters>
class Solutions {
	public:
		using tSolutionStatic = typename tParameters::tSolutionStatic;
	public:
		Solutions() {
		}
	public:
		void step(const double dt) {
			solutionsStatic.step(dt);
			tParameters::stepDynamic(dt);
			tParameters::stepGroups(dt);
		}
	public:
		typename tParameters::tSolutionStatic solutionsStatic;
};

}

#endif
