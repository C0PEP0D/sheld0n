#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "param/env/objects/object/agent/_behaviour/odor_tracker/_behaviour_direction/surf/choice.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourOdorTrackerBehaviourDirection = ObjectAgentBehaviourOdorTrackerBehaviourDirectionSurf<ObjectAgentActiveStep>;
}

#endif
