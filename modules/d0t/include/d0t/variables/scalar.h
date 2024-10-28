#ifndef D0T_VARIABLES_SCALAR_H
#define D0T_VARIABLES_SCALAR_H
#pragma once

// std includes
#include <vector>
// module includes
#include "d0t/variable.h"

namespace d0t {

template<template<int> typename _tVector, template<typename...> class _tView>
class VariableScalar : public VariableStatic<_tVector, _tView, 1> {
	public:
		using tBase = VariableStatic<_tVector, _tView, 1>;
    public:
    	template<int _Size> using tVector = typename tBase::tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
   		using tBase::Size;
   		using tStateVectorStatic = typename tBase::tStateVectorStatic;
    public:
    	static double* get(double* pState) {
            return pState;
        }
        static const double* cGet(const double* pState) {
            return pState;
        }
    public:
    	static void constrain(double* pState) {
    	}
    	static void constrain(std::vector<double>& state) {
    		constrain(state.data());
    	}
};

}

#endif
