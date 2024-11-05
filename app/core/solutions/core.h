#ifndef C0P_CORE_SOLUTIONS_CORE_H
#define C0P_CORE_SOLUTIONS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
#include <execution>
// lib includes
#include "d0t/equation.h"
// app includes
#include "core/solutions/prop.h"

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

		template<unsigned int Index = 0>
		void initStatic() {
			using tStaticEquation = typename tSolutionStatic::tEquation;
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			if constexpr(Index < tStaticEquation::Number) {
				tStaticEquation::template tEquationComponent<Index>::type::tParameters::init(
					tStaticVariable::template state<Index>(
						solutionsStatic.state.data()
					)
				);
				// recursion
				initStatic<Index+1>();
			}
		}
		
		void init() {
			initStatic();
			tParameters::initGroups();
		}
	public:
		typename tParameters::tSolutionStatic solutionsStatic;
};

}

#endif
