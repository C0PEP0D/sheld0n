#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_6O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_6O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/const/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour that sets a constant time horizon to the
// surfing behaviour
struct SurferUs15O58Surftimeconst6O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonConstParameters {
    // Constant surfing time horizon
    const TypeScalar value = 6.0 * Parameters::cTime;
};

}

#endif
