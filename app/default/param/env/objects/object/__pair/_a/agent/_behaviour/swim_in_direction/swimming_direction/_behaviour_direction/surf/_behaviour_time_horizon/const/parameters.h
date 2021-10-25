#ifndef C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_SWIMMING_DIRECTION_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_SWIMMING_DIRECTION_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/swim_in_direction/swimming_direction/behaviour_direction/surf/behaviour_time_horizon/const/prop.h"
#include "param/parameters.h"

namespace c0p {

struct ObjectPairAAgentBehaviourSwimInDirectionSwimmingDirectionBehaviourDirectionSurfBehaviourTimeHorizonConstParameters {
    const TypeScalar value = 1.0 * Parameters::cTime;
};

}

#endif
