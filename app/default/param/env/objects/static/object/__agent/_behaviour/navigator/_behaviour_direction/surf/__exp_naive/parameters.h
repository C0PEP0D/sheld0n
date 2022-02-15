#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_NAIVE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_NAIVE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp_naive/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour of a surfer that use a naive implementation 
// of a matrix exponential. The choice of the order of the computation is
// available.
struct ObjectAgentBehaviourNavigatorBehaviourDirectionSurfExpNaiveParameters {
    // Order of the matrix exponential
    unsigned int order = 4;
};

}

#endif
