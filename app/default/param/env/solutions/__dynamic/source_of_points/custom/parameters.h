#ifndef C0P_SOLUTIONS_SOURCE_OF_POINTS_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_SOURCE_OF_POINTS_CUSTOM_PARAMETERS_H
#pragma once

// app includes
#include "core/env/solutions/prop.h"
#include "core/env/solutions/core.h"
#include "param/env/flow/choice.h"

#include "core/env/solutions/equation/custom/prop.h"
#include "param/parameters.h"

// include lib
#include "d0t/variables/vector.h"
#include "d0t/variables/scalar.h"

namespace c0p {

struct _SourceOfPointsCustomParameters {
	// name
	inline static const std::string name = "source_of_points";
	static constexpr double Lifetime = 1.0;
	static constexpr double Interval = 1.0 / 128.0;
	static constexpr unsigned int Number = 16;
	static constexpr std::array<double, DIM> Center = {0.0, 0.0};
	static constexpr std::array<double, DIM> Length = {3.0 * M_PI, 3.0 * M_PI};
	// sub data
    class Point : public d0t::VariableComposed<d0t::VariableVector<tVector, tView, DIM>, d0t::VariableScalar<tVector, tView>> {
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
   		public:
   			using tLifetime = tVariableComponent<1>::type;
    		static constexpr auto stateLifetime = state<1>;
    		static constexpr auto cStateLifetime = cState<1>;
   			static double* lifetime(double* pState) {
   				return tLifetime::get(stateLifetime(pState));
   			}
   			static const double* cLifetime(const double* pState) {
   				return tLifetime::cGet(cStateLifetime(pState));
   			}
    };
    class tSubEquation : public d0t::Equation<Point> {
    	public:
	    	static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
	    		// init
	            tStateVectorDynamic output = tStateVectorDynamic::Zero(tVariable::Size);
	            // advection
                tView<tSpaceVector> dX = Point::position(output.data());
                dX = Flow::getVelocity(Point::cPosition(pState).data(), t);
                // lifetime
                double* dLifeTime = Point::lifetime(output.data());
                *dLifeTime = -1.0;
                // output
                return output;
	        }
    };
	// creating tVariable and tEquation
    class tVariable : public d0t::VariableGroupDynamic<Point> {
    	public:
    		using tBase = d0t::VariableGroupDynamic<Point>;
    	public:
	    	static void constrain(std::vector<double>& p_state) {
	    		tBase::_constrain(p_state);
				// remove dead points
				for(int index = tBase::groupSize(p_state.size()) - 1; index > -1; index--) {
					if (*Point::cLifetime(tBase::cState(p_state.data(), index)) < 0.0) {
						tBase::eraseMember(p_state, index);
					}
				}
				// add points based on rate
				if (p_state.empty() || (Lifetime - *Point::cLifetime(tBase::cState(p_state.data(), tBase::groupSize(p_state.size()) - 1)) > Interval)) {
					for (unsigned int index = 0; index < Number; index++) {
						tBase::pushBackMember(p_state);
						// set initial state
						Point::position(tBase::state(p_state.data(), tBase::groupSize(p_state.size()) - 1)) = tSpaceVector::Random();
						for(unsigned int index = 0; index < DIM; index++){
							Point::position(tBase::state(p_state.data(), tBase::groupSize(p_state.size()) - 1))[index] = Point::cPosition(tBase::cState(p_state.data(), tBase::groupSize(p_state.size()) - 1))[index] * Length[index] + Center[index];
						}
						*Point::lifetime(tBase::state(p_state.data(), tBase::groupSize(p_state.size()) - 1)) = Lifetime;
					}
				}
	    	}
    };
    using tEquation = d0t::EquationGroupDynamic<tVariable, tSubEquation>;
};

}

#endif
