#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMECONST_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMECONST_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/const/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour that sets a constant time horizon to the
// surfing behaviour
struct SurferUs0O05Surftimeconst2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonConstParameters {
    // Constant surfing time horizon
    const TypeScalar value = 2.25 * Parameters::cTime;
};

}

#endif
