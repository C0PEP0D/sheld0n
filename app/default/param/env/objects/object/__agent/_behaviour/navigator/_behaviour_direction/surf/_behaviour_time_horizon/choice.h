#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/const/core.h"
#include "param/env/objects/object/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/const/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon = AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonConst<ObjectAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonConstParameters, ObjectAgentActiveStep>;
}

#endif
