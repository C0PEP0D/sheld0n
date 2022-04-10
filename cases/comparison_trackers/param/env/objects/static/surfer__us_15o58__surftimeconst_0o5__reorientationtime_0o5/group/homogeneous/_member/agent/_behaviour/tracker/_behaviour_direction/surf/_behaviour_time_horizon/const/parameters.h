#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_0O5__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_0O5__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CONST_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/surf/behaviour_time_horizon/const/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour that sets a constant time horizon to the
// surfing behaviour
struct SurferUs15O58Surftimeconst0O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourTrackerBehaviourDirectionSurfBehaviourTimeHorizonConstParameters {
    // Constant surfing time horizon
    const TypeScalar value = 0.5 * Parameters::cTime;
};

}

#endif
