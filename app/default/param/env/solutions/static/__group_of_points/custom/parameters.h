#ifndef C0P_SOLUTIONS_GROUP_OF_POINTS_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_GROUP_OF_POINTS_CUSTOM_PARAMETERS_H
#pragma once

// app includes
#include "core/env/solutions/prop.h"
#include "core/env/solutions/core.h"
#include "param/env/flow/choice.h"

#include "core/env/solutions/equation/custom/prop.h"
#include "param/parameters.h"

// include lib
#include "d0t/equations/advection.h"

namespace c0p {

struct _GroupOfPointsCustomParameters {
	// basic parameters
	inline static std::string name = "group_of_points";
	static const unsigned Number = 16;
	// definition of the member data
    class Point : public d0t::VariableComposed<d0t::VariableVector<tVector, tView, DIM>> {
    	public:
    		using tPosition = tVariableComponent<0>::type;
    		static constexpr auto statePosition = state<0>;
    		static constexpr auto cStatePosition = cState<0>;
    	public:
   			static tView<tSpaceVector> position(double* pState) {
   				return tPosition::get(statePosition(pState));
   			}
   			static tView<const tSpaceVector> cPosition(const double* pState) {
   				return tPosition::cGet(cStatePosition(pState));
   			}
    };
    using tSubEquation = d0t::EquationAdvection<Point, Flow>;
	// creating tVariable and tEquation
    class tVariable : public d0t::VariableGroupStatic<Point, Number> {
    };
    using tEquation = d0t::EquationGroupStatic<tVariable, tSubEquation>;
};

}

#endif
