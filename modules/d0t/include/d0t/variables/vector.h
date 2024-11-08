#ifndef D0T_VARIABLES_VECTOR_H
#define D0T_VARIABLES_VECTOR_H
#pragma once

// std includes
#include <vector>
// module includes
#include "d0t/variable.h"

namespace d0t {

template<template<int> typename _tVector, template<typename...> class _tView, unsigned int _Dim>
class VariableVector : public VariableStatic<_tVector, _tView, _Dim> {
	public:
		using tBase = VariableStatic<_tVector, _tView, _Dim>;
    public:
    	template<int _Size> using tVector = typename tBase::template tVector<_Size>;
   		template<typename... Args> using tView = typename tBase::template tView<Args...>;
   		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
   		using tBase::MinSize;
   		using tBase::Size;
   		using tStateVectorStatic = typename tBase::tStateVectorStatic;
    public:
    	static const unsigned int Dim = _Dim;
        using tSpaceVector = typename tBase::template tVector<Dim>;
    public:
    	static tView<tSpaceVector> get(double* pState) {
            return tView<tSpaceVector>(pState);
        }
        static tView<const tSpaceVector> cGet(const double* pState) {
            return tView<const tSpaceVector>(pState);
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
