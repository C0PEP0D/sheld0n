#ifndef D0T_VARIABLE_H
#define D0T_VARIABLE_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
#include <numeric> // iota
#include <execution>

namespace d0t {

// base types

template<template<int> typename _tVector, template<typename...> class _tView, unsigned int _MinSize = 0>
class Variable {
	public:
		template<int _Size> using tVector = _tVector<_Size>;
		template<typename... Args> using tView = _tView<Args...>;
		using tStateVectorDynamic = tVector<-1>;
		static const unsigned int MinSize = _MinSize;
	public:
		// // apply variable constraints
		// virtual static void constrain(std::vector<double>& state) {
			// T::_constrain(state);
		// }
};

template<template<int> typename _tVector, template<typename...> class _tView, unsigned int _Size>
class VariableStatic : public Variable<_tVector, _tView, _Size> {
	public:
		using tBase = Variable<_tVector, _tView, _Size>;
	public:
   		template<int _SizeTmp> using tVector = typename tBase::template tVector<_SizeTmp>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
	public:
		static const unsigned int Size = _Size;
		using tStateVectorStatic = typename tBase::template tVector<Size>;
	public:
		// // apply variable constraints
		// static void constrain(std::vector<double>& state) override {
			// constrain(state.data());
		// }
		// virtual static void constrain(double* pState) {
		// }
};

template<template<int> typename _tVector, template<typename...> class _tView>
class VariableNone : public VariableStatic<_tVector, _tView, 0> {
	public:
		using tBase = VariableStatic<_tVector, _tView, 0>;
	public:
		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
   		using tBase::Size;
   		using tStateVectorStatic = typename tBase::tStateVectorStatic;
	// public:
		// static double* get(double* pState) {
			// return pState;
		// }
		// static const double* cGet(const double* pState) {
			// return pState;
		// }
	public:
		static void constrain(double* pState) {
		}
		static void constrain(std::vector<double>& state) {
			constrain(state.data());
		}
};

// composed variable

template<unsigned int Index, typename tVariable, typename... tVariables>
struct VariableComponent : VariableComponent<Index - 1, tVariables...> { 
};

template<typename tVariable, typename... tVariables>
struct VariableComponent<0, tVariable, tVariables...> {
   using type = tVariable;
};

template<unsigned int Index, typename tVariable, typename... tVariables>
double* variableComponentState(double* pState) {
	if constexpr (Index == 0) {
		return pState;
	} else {
		return variableComponentState<Index - 1, tVariables...>(pState + tVariable::Size);
	}
}

template<unsigned int Index, typename tVariable, typename... tVariables>
const double* cVariableComponentState(const double* pState) {
	if constexpr (Index == 0) {
		return pState;
	} else {
		return cVariableComponentState<Index - 1, tVariables...>(pState + tVariable::Size);
	}
}

template<typename tVariableA, typename tVariableB, typename... tVariables>
double* variableComponentState(double* pState) {
	if constexpr (std::is_same<tVariableA, tVariableB>::value) {
		return pState;
	} else {
		return variableComponentState<tVariableA, tVariables...>(pState + tVariableB::Size);
	}
}

template<typename tVariableA, typename tVariableB, typename... tVariables>
const double* cVariableComponentState(const double* pState) {
	if constexpr (std::is_same<tVariableA, tVariableB>::value) {
		return pState;
	} else {
		return cVariableComponentState<tVariableA, tVariables...>(pState + tVariableB::Size);
	}
}

template<typename... tVariables>
class VariableComposed;

template<typename tVariable>
class VariableComposed<tVariable> : public VariableStatic<tVariable::template tVector, tVariable::template tView, tVariable::Size> {
	public:
		using tBase = VariableStatic<tVariable::template tVector, tVariable::template tView, tVariable::Size>;
	public:
   		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
   		using tBase::Size;
   		using tStateVectorStatic = typename tBase::tStateVectorStatic;
	public:
		template<unsigned int Index> using tVariableComponent = VariableComponent<Index, tVariable>;
	public:
		template<unsigned int Index>
		static double* state(double* pState) {
			return variableComponentState<Index, tVariable>(pState);
		}
		template<unsigned int Index>
		static const double* cState(const double* pState) {
			return cVariableComponentState<Index, tVariable>(pState);
		}
		template<typename _tVariable>
		static double* state(double* pState) {
			return variableComponentState<_tVariable, tVariable>(pState);
		}
		template<typename _tVariable>
		static const double* cState(const double* pState) {
			return cVariableComponentState<_tVariable, tVariable>(pState);
		}
	public:
		static void constrain(double* pState) {
			tVariable::constrain(pState);
		}
		static void constrain(std::vector<double>& state) {
			constrain(state.data());
		}
};

template<typename tVariable, typename... tVariables>
class VariableComposed<tVariable, tVariables...> : public VariableStatic<tVariable::template tVector, tVariable::template tView, tVariable::Size + VariableComposed<tVariables...>::Size> {
	public:
		using tBase = VariableStatic<tVariable::template tVector, tVariable::template tView, tVariable::Size + VariableComposed<tVariables...>::Size>;
	public:
   		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
   		using tBase::Size;
   		using tStateVectorStatic = typename tBase::tStateVectorStatic;
	public:
		template<unsigned int Index> using tVariableComponent = VariableComponent<Index, tVariable, tVariables...>;
	public:
		template<unsigned int Index>
		static double* state(double* pState) {
			return variableComponentState<Index, tVariable, tVariables...>(pState);
		}
		template<unsigned int Index>
		static const double* cState(const double* pState) {
			return cVariableComponentState<Index, tVariable, tVariables...>(pState);
		}
		template<typename _tVariable>
		static double* state(double* pState) {
			return variableComponentState<_tVariable, tVariable, tVariables...>(pState);
		}
		template<typename _tVariable>
		static const double* cState(const double* pState) {
			return cVariableComponentState<_tVariable, tVariable, tVariables...>(pState);
		}
	public:
		static void constrain(double* pState) {
			tVariable::constrain(pState);
			VariableComposed<tVariables...>::constrain(pState + tVariable::Size);
		}
		static void constrain(std::vector<double>& state) {
			constrain(state.data());
		}
};

// group variables

template<typename _tVariableMember, unsigned int _GroupSize, typename _tVariableMeta = VariableNone<_tVariableMember::template tVector, _tVariableMember::template tView> >
class VariableGroupStatic : public VariableStatic<_tVariableMember::template tVector, _tVariableMember::template tView, _tVariableMember::Size * _GroupSize> {
	public:
		using tBase = VariableStatic<_tVariableMember::template tVector, _tVariableMember::template tView, _tVariableMeta::Size + _tVariableMember::Size * _GroupSize>;
	public:
   		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
   		using tBase::Size;
   		using tStateVectorStatic = typename tBase::tStateVectorStatic;
	public:
		using tVariableMember = _tVariableMember;
		static const unsigned int GroupSize = _GroupSize;
		using tVariableMeta = _tVariableMeta;
	public:
		static double* stateMeta(double* pState) {
		   	return pState;
		}
  		static const double* cStateMeta(const double* pState) {
		  	return pState;
  		}
	public:
		static double* state(double* pState, const unsigned int index) {
			return pState + tVariableMeta::Size + index * tVariableMember::Size;
		}
   		static const double* cState(const double* pState, const unsigned int index) {
		   	return pState + tVariableMeta::Size + index * tVariableMember::Size;
   		}
   	public:
		// apply variable constraints
		static void constrain(double* pState) {
			// constrain meta
			tVariableMeta::constrain(pState);
			// create member indexs
			std::vector<unsigned int> memberIndexs(GroupSize);
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			// constrain everything
			std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [pState](const unsigned int memberIndex){
				tVariableMember::constrain(state(pState, memberIndex));
			});
		}
		static void constrain(std::vector<double>& state) {
			constrain(state.data());
		}
};

template<typename _tVariableMember, typename _tVariableMeta = VariableNone<_tVariableMember::template tVector, _tVariableMember::template tView>>
class VariableGroupDynamic : public Variable<_tVariableMember::template tVector, _tVariableMember::template tView, _tVariableMeta::Size> {
	public:
		using tBase = Variable<_tVariableMember::template tVector, _tVariableMember::template tView>;
	public:
   		template<int _Size> using tVector = typename tBase::template tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
	public:
		using tVariableMember = _tVariableMember;
		using tVariableMeta = _tVariableMeta;
	public:
		static double* stateMeta(double* pState) {
			return pState;
		}
   		static const double* cStateMeta(const double* pState) {
		   	return pState;
   		}
   	public:
		static double* state(double* pState, const unsigned int index) {
			return pState + tVariableMeta::Size + index * tVariableMember::Size;
		}
   		static const double* cState(const double* pState, const unsigned int index) {
		   	return pState + tVariableMeta::Size + index * tVariableMember::Size;
   		}
   		static const unsigned int groupSize(const unsigned int stateSize) {
   			return (stateSize - tVariableMeta::Size) / tVariableMember::Size;
   		}
   	public:
		// apply variable constraints
		static void _constrain(std::vector<double>& p_state) {
			// constrain meta
			tVariableMeta::constrain(p_state.data());
			// create member indexs
			std::vector<unsigned int> memberIndexs(groupSize(p_state.size()));
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			// constrain everything
			std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [&p_state](const unsigned int memberIndex){
				tVariableMember::constrain(state(p_state.data(), memberIndex));
			});
		}
		// member management
   		static void pushBackMember(std::vector<double>& p_state) {
   			p_state.resize(p_state.size() + tVariableMember::Size);
   		}
   
   		static void eraseMember(std::vector<double>& p_state, const unsigned int index) {
   			p_state.erase(p_state.begin() + tVariableMeta::Size + index * tVariableMember::Size, p_state.begin() + tVariableMeta::Size + (index + 1) * tVariableMember::Size);
   		}

   		static void popBackMember(std::vector<double>& p_state) {
   			p_state.resize(p_state.size() - tVariableMember::Size);
   		}
};

template<typename _tVariableGroup, typename _tVariableMeta = VariableNone<_tVariableGroup::template tVector, _tVariableGroup::template tView>>
class VariableGroups {
	public:
		using tVariableGroup = _tVariableGroup;
		using tVariableMeta = _tVariableMeta;
	public:
		static std::vector<double>& stateMeta(std::vector<std::vector<double>>& states) {
			return states.front();
		}
   		static const std::vector<double>& cStateMeta(const std::vector<std::vector<double>>& states) {
		   	return states.front();
   		}
   	public:
		static std::vector<double>& state(std::vector<std::vector<double>>& states, const unsigned int index) {
			return states[1 + index];
		}
   		static const std::vector<double>& cState(const std::vector<std::vector<double>>& states, const unsigned int index) {
		   	return states[1 + index];
   		}
   		static const unsigned int groupNumber(const unsigned int statesSize) {
   			return statesSize - 1;
   		}
	public:
		// apply variable constraints
		static void _constrain(std::vector<std::vector<double>>& states) {
			// constrain meta
			tVariableMeta::constrain(states.front());
			// create group indexs
			std::vector<unsigned int> groupIndexs(states.size() - 1);
			std::iota(groupIndexs.begin(), groupIndexs.end(), 0);
			// constrain everything
			std::for_each(std::execution::par_unseq, groupIndexs.cbegin(), groupIndexs.cend(), [&states](const unsigned int groupIndex){
				tVariableGroup::constrain(states[1 + groupIndex]);
			});
		}
		// member management
		static void pushBackGroup(std::vector<std::vector<double>>& states) {
			states.push_back(std::vector<double>(tVariableGroup::MinSize));
		}
		static void insertGroups(std::vector<std::vector<double>>& states, const std::vector<std::vector<double>>& otherStates) {
			states.insert(states.end(), otherStates.begin(), otherStates.end());
		}
		static void popBackGroup(std::vector<std::vector<double>>& states) {
			states.pop_back();
		}
		static void eraseGroup(std::vector<std::vector<double>>& states, const unsigned int& memberIndex) {
			states.erase(states.begin() + 1 + memberIndex);
		}
};

}

#endif
