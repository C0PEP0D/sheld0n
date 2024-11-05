#ifndef C0P_PARAM_INIT_SOLUTIONS_REACTIVE_FRONT_CUSTOM_PARAMETERS_H
#define C0P_PARAM_INIT_SOLUTIONS_REACTIVE_FRONT_CUSTOM_PARAMETERS_H
#pragma once

// app include
#include "core/init/solutions/equation/prop.h"
#include "param/parameters.h"

namespace c0p {

// Add group members
struct Init_ReactiveFrontCustomParameters {

    inline static const std::array<double, DIM> Center = {0.0, 0.0};
    inline static const double Radius = 1.0/2.0;
    inline static const unsigned int Number = 16;

    static void set(std::vector<std::vector<double>>& p_states) {
        // Set initial state
        _ReactiveFront::tParameters::tVariable::pushBackGroup(p_states);
        for(unsigned int memberIndex = 0; memberIndex < Number; memberIndex++) {
            _ReactiveFront::tParameters::tVariable::tCurve::pushBackMember(p_states[0]);
            _ReactiveFront::tParameters::tVariable::tCurve::tVariableMember::position(
                _ReactiveFront::tParameters::tVariable::tCurve::state(p_states[0].data(), memberIndex)
            ) = tSpaceVector(Center.data()) + Radius * tSpaceVector({std::cos(2.0 * M_PI * memberIndex / Number), std::sin(2.0 * M_PI * memberIndex / Number)});
        }
    };
};

}

#endif
