#ifndef C0P_CORE_SOLUTIONS_CORE_H
#define C0P_CORE_SOLUTIONS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
#include <execution>
#include <format>
// lib includes
#include "d0t/equation.h"
#include "s0ve/double.h"
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

		// output

		template<unsigned int Index>
		double* stateStatic() {
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			return tStaticVariable::template state<Index>(
				solutionsStatic.state.data()
			);
		}

		template<typename tType>
		double* stateStatic() {
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			return tStaticVariable::template state<tType>(
				solutionsStatic.state.data()
			);
		}

		// step
		
		void step(const double dt) {
			solutionsStatic.step(dt);
			tParameters::stepDynamic(dt);
			tParameters::stepGroups(dt);
		}

		// init

		template<unsigned int Index = 0>
		void initStatic() {
			using tStaticEquation = typename tSolutionStatic::tEquation;
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			if constexpr(Index < tStaticEquation::Number) {
				tStaticEquation::template tEquationComponent<Index>::type::tParameters::init(stateStatic<Index>());
				// recursion
				initStatic<Index+1>();
			}
		}
		
		void init() {
			initStatic();
			tParameters::initGroups();
		}
		
		// post

		template<unsigned int Index = 0>
		void postStatic(const double t) {
			using tStaticEquation = typename tSolutionStatic::tEquation;
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			if constexpr(Index < tStaticEquation::Number) {
				s0ve::saveMapToCsvDouble(
					"post_process/time/" + std::format("{:0>10f}", t) + "/" + tStaticEquation::template tEquationComponent<Index>::type::tParameters::name + ".csv",
					tStaticEquation::template tEquationComponent<Index>::type::tParameters::post(stateStatic<Index>(), t),
					",", 
					"#"
				);
				// recursion
				postStatic<Index+1>(t);
			}
		}
		
		void post(const double t) {
			postStatic(t);
			tParameters::postGroups(t);
		}
	public:
		typename tParameters::tSolutionStatic solutionsStatic;
};

}

#endif
