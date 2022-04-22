#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/custom/core.h"
#include "param/env/objects/static/object/agent/_behaviour/tracker/_behaviour_direction/custom/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourTrackerBehaviourDirectionCustom = AgentBehaviourTrackerBehaviourDirectionCustom<ObjectAgentBehaviourTrackerBehaviourDirectionCustomParameters, ObjectAgentActiveStep>;
}

#endif
