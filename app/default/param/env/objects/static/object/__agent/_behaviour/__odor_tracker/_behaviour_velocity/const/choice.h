#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_velocity/const/core.h"
#include "param/env/objects/object/agent/_behaviour/odor_tracker/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourOdorTrackerBehaviourVelocityConst = AgentBehaviourOdorTrackerBehaviourVelocityConst<ObjectAgentBehaviourOdorTrackerBehaviourVelocityConstParameters, ObjectAgentActiveStep>;
}

#endif
