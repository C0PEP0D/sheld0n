#ifndef D0T_EQUATION_H
#define D0T_EQUATION_H
#pragma once

#include "d0t/variable.h"

namespace d0t {

template<typename _tVariable>
class Equation {
	public:
		using tVariable = _tVariable;
		template<int _Size> using tVector = typename tVariable::template tVector<_Size>;
		template<typename... Args> using tView = typename tVariable::template tView<Args...>;
		using tStateVectorDynamic = typename tVariable::tStateVectorDynamic;

	public:
		Equation() {
		}
};

// equation composed

template<unsigned int Index, typename tEquation, typename... tEquations>
struct EquationComponent : EquationComponent<Index - 1, tEquations...> { 
};

template<typename tEquation, typename... tEquations>
struct EquationComponent<0, tEquation, tEquations...> {
   using type = tEquation;
};

template<typename... tEquations>
class EquationComposed : public Equation<VariableComposed<typename tEquations::tVariable...>> {
	public:
		using tBase = Equation<VariableComposed<typename tEquations::tVariable...>>;

	public:
		   using tVariable = typename tBase::tVariable;
		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
		template<typename... Args> using tView = typename tBase::template tView<Args...>;
		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
		static const unsigned int Number = sizeof...(tEquations);

	public:
		template<unsigned int Index> using tEquationComponent = EquationComponent<Index, tEquations...>;

	public:
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			loopPrepare(pState, t);
		}
		
		template<unsigned int Index = 0>
		static void loopPrepare(const double* pState, const double t) {
			if constexpr(Index < Number) {
				tEquationComponent<Index>::type::prepare(tVariable::template cState<Index>(pState), tVariable::template tVariableComponent<Index>::type::Size, t);
				// recursion
				loopPrepare<Index+1>(pState, t);
			}
		}

	public:
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(pStateSize[0]);
			loopStateTemporalDerivative(pStateArray, pStateSize, arraySize, t, dState.data());
			return dState;
		}
		
		template<unsigned int Index = 0>
		static void loopStateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, double* pDstate) {
			if constexpr(Index < Number) {
				tView<tStateVectorDynamic>(tVariable::template state<Index>(pDstate), tVariable::template tVariableComponent<Index>::type::Size, 1) = tEquationComponent<Index>::type::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t);
				// recursion
				loopStateTemporalDerivative<Index+1>(pStateArray, pStateSize, arraySize, t);
			}
		}
};

// group equation

template<typename _tVariableGroup, typename _tMemberEquation>
class EquationGroupDynamic : public Equation<_tVariableGroup> {
	public:
		using tBase = Equation<_tVariableGroup>;

	public:
		using tVariable = typename tBase::tVariable;
		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
		template<typename... Args> using tView = typename tBase::template tView<Args...>;
		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;

	public:
		using tVariableGroup = tVariable;
		using tMemberEquation = _tMemberEquation;

	public:
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// create member indexs
			std::vector<unsigned int> memberIndexs(tVariableGroup::groupSize(stateSize));
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			// prepare each equation if necessary
			std::for_each(std::execution::seq, memberIndexs.cbegin(), memberIndexs.cend(), [pState, stateSize, t](const unsigned int memberIndex){
				tMemberEquation::prepare(tVariableGroup::cState(pState, memberIndex), tVariableGroup::tVariableMember::Size, t);
			});
		}
	 public:
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, const unsigned int groupIndex) {
			const unsigned int stateSize = pStateSize[groupIndex];
			// create member indexs
			std::vector<unsigned int> memberIndexs(tVariableGroup::groupSize(stateSize));
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			// apply sub equation to each member of the group
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(stateSize);
			std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [&dState, pStateArray, pStateSize, arraySize, t](const unsigned int memberIndex){
				tView<typename tVariableGroup::tVariableMember::tStateVectorStatic>(tVariableGroup::state(dState.data(), memberIndex)) = tMemberEquation::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t, memberIndex);
			});
			return dState;
		}
};

template<typename _tVariableGroup, typename _tMemberEquation>
class EquationGroupStatic : public Equation<_tVariableGroup> {
	public:
		using tBase = Equation<_tVariableGroup>;

	public:
		using tVariable = typename tBase::tVariable;
		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
		template<typename... Args> using tView = typename tBase::template tView<Args...>;
		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;

	public:
		using tVariableGroup = tVariable;
		using tMemberEquation = _tMemberEquation;

	public:
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// create member indexs
			std::vector<unsigned int> memberIndexs(tVariableGroup::GroupSize);
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			// prepare each equation if necessary
			std::for_each(std::execution::seq, memberIndexs.cbegin(), memberIndexs.cend(), [pState, stateSize, t](const unsigned int memberIndex){
				tMemberEquation::prepare(tVariableGroup::cState(pState, memberIndex), tVariableGroup::tVariableMember::Size, t);
			});
		}

	public:
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
			// create member indexs
			std::vector<unsigned int> memberIndexs(tVariableGroup::GroupSize);
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			// apply sub equation to each member of the group
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariableGroup::Size);
			std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [&dState, pStateArray, pStateSize, arraySize, t](const unsigned int memberIndex){
				tView<typename tVariableGroup::tVariableMember::tStateVectorStatic>(tVariableGroup::state(dState.data(), memberIndex)) = tMemberEquation::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t, memberIndex);
			});
			return dState;
		}
};

// // solution
// 
// template<typename _tSolver, typename _tEquation, typename _tPrepare>
// class SolutionDynamic {
// 	public:
// 		using tSolver = _tSolver;
// 		using tEquation = _tEquation;
// 		using tVariable = typename tEquation::tVariable;
// 		using tPrepare = _tPrepare;
// 
// 	public:
// 		SolutionDynamic(const double p_t = 0.0) : state(tVariable::MinSize), t(p_t) {
// 		}
// 
// 	public:
// 		virtual void step(const double dt) {
// 			tSolver::step(
// 				[](const double* pState, const unsigned int stateSize, const double t) { 
// 					tEquation::prepare(pState, stateSize, t);
// 					tPrepare::prepare(pState, stateSize, t);
// 					return tEquation::stateTemporalDerivative(pState, stateSize, t); 
// 				}, 
// 				state.data(),
// 				state.size(),
// 				t, 
// 				dt
// 			);
// 			tVariable::constrain(state);
// 			t += dt;
// 		}
// 
// 	public:
// 		double t;
// 		std::vector<double> state;
// };
// 
// template<typename _tSolver, typename _tEquation, typename _tPrepare>
// class SolutionStatic : public SolutionDynamic<_tSolver, _tEquation, _tPrepare> {
// 	public:
// 		using tBase = SolutionDynamic<_tSolver, _tEquation, _tPrepare>;
// 
// 	public:
// 		using tSolver = typename tBase::tSolver;
// 		using tEquation = typename tBase::tEquation;
// 		using tVariable = typename tBase::tVariable;
// 		using tPrepare = typename tBase::tPrepare;
// 
// 	public:
// 		SolutionStatic(const double p_t = 0.0) : tBase(p_t)  {
// 		}
// 
// 	public:
// 		void step(const double dt) override {
// 			tSolver::step(
// 				[](const double* pState, const unsigned int stateSize, const double t) {
// 					tEquation::prepare(pState, stateSize, t);
// 					tPrepare::prepare(pState, stateSize, t);
// 					return tEquation::stateTemporalDerivative(pState, stateSize, t); 
// 				},
// 				tBase::state.data(), 
// 				tBase::state.size(), 
// 				tBase::t,
// 				dt
// 			);
// 			tVariable::constrain(tBase::state.data());
// 			tBase::t += dt;
// 		}
// };
// 
// // TODO: SolutionGroups should be a SolutionDynamic with meta. I need to think about it.
// 
// template<typename _tSolver, typename _tEquation, typename _tPrepare, typename _tVariable>
// class SolutionGroups {
// 	public:
// 		using tSolver = _tSolver;
// 		using tEquation = _tEquation;
// 		using tVariable = _tVariable;
// 		using tPrepare = _tPrepare;
// 
// 	public:
// 		SolutionGroups(const double p_t = 0.0) : states(1, std::vector<double>(tVariable::tVariableMeta::MinSize)), t(p_t) {
// 		}
// 
// 	public:
// 		virtual void step(const double dt) {
// 			tSolver::step(
// 				[](const std::vector<std::vector<double>>& states, const double t) {
// 					tEquation::prepare(states, t);
// 					tPrepare::prepare(states, t);
// 					return tEquation::stateTemporalDerivative(states, t); 
// 				},
// 				states,
// 				t,
// 				dt
// 			);
// 			tVariable::constrain(states);
// 			t += dt;
// 		}
// 
// 	public:
// 		double t;
// 		std::vector<std::vector<double>> states;
// };

}

#endif
