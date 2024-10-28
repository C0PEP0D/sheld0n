#ifndef C0P_SOLUTIONS_REACTIVE_FRONT_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_REACTIVE_FRONT_CUSTOM_PARAMETERS_H
#pragma once

// app includes
#include "core/env/solutions/prop.h"
#include "core/env/solutions/core.h"
#include "param/env/flow/choice.h"

#include "core/env/solutions/equation/custom/prop.h"
#include "param/parameters.h"

// include lib
#include "d0t/variables/vector.h"
#include "d0t/variables/border.h"
#include "d0t/equations/g.h"

namespace c0p {

struct _ReactiveFrontCustomParameters {
	// name
	inline static const std::string name = "reactive_front";
	inline static constexpr double Density = 4.0;
	inline static const bool IsClosed = true;
	inline static const unsigned int InterpolationOrder = 4;
	inline static constexpr double LocalReactingVelocity = 1.0;
	// sub data
    class Point : public d0t::VariableComposed<
    	d0t::VariableVector<tVector, tView, DIM>
    > {
    	public:
    		using tSpaceVector = tSpaceVector;
    	public:
    		using tPosition = tVariableComponent<0>::type;
    		static constexpr auto statePosition = state<0>;
    		static constexpr auto cStatePosition = cState<0>;
   			static tView<tSpaceVector> position(double* pState) {
   				return tPosition::get(statePosition(pState));
   			}
   			static tView<const tSpaceVector> cPosition(const double* pState) {
   				return tPosition::cGet(cStatePosition(pState));
   			}
    };
	// creating tVariable and tEquation
    using tVariable = d0t::VariableBorder<Point, Density, IsClosed, InterpolationOrder>;
    using tEquation = d0t::EquationG<tVariable::tCurve, Flow, LocalReactingVelocity>;
};

}

#endif
