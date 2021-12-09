#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/object/agent/_behaviour/tracker/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/surf/core.h"
#include "param/env/objects/object/agent/_behaviour/tracker/_behaviour_direction/surf/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourTrackerBehaviourDirectionSurf = AgentBehaviourTrackerBehaviourDirectionSurf<ObjectAgentBehaviourTrackerBehaviourDirectionSurfParameters, ObjectAgentActiveStep, ObjectAgentBehaviourTrackerBehaviourDirectionSurfBehaviourTimeHorizon<ObjectAgentActiveStep>>;
}

#endif
