#ifndef C0P_CORE_SOLUTIONS_CORE_H
#define C0P_CORE_SOLUTIONS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
#include <execution>
#include <iomanip>
// lib includes
#include "d0t/equation.h"
#include "s0ve/double.h"

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

		template<unsigned int Index>
		const double* cStateStatic() const {
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			return tStaticVariable::template cState<Index>(
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

		template<typename tType>
		const double* cStateStatic() const {
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			return tStaticVariable::template cState<tType>(
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
			// make sure state is correctly allocated
			solutionsStatic.state.resize(tStaticVariable::MinSize);
			// then run init
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
		void postStatic(const double t) const {
			using tStaticEquation = typename tSolutionStatic::tEquation;
			using tStaticVariable = typename tSolutionStatic::tEquation::tVariable;
			if constexpr(Index < tStaticEquation::Number) {
				// build name
				std::ostringstream oss;
				oss << "post_process/time/" << std::fixed << std::setprecision(7) << std::setw(10) << std::setfill('0') << t << "/" << tStaticEquation::template tEquationComponent<Index>::type::tParameters::name << ".csv";
				// save data
				s0ve::saveMapToCsvDouble(
					oss.str(),
					tStaticEquation::template tEquationComponent<Index>::type::tParameters::post(cStateStatic<Index>(), t),
					",",
					"#"
				);
				// recursion
				postStatic<Index+1>(t);
			}
		}
		
		void post(const double t) const {
			postStatic(t);
			tParameters::postGroups(t);
		}
	public:
		typename tParameters::tSolutionStatic solutionsStatic;
};

}

#endif
