#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/static/object/agent/_behaviour/odor_tracker/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_direction/surf/core.h"
#include "param/env/objects/static/object/agent/_behaviour/odor_tracker/_behaviour_direction/surf/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourOdorTrackerBehaviourDirectionSurf = AgentBehaviourOdorTrackerBehaviourDirectionSurf<ObjectAgentBehaviourOdorTrackerBehaviourDirectionSurfParameters, ObjectAgentActiveStep, ObjectAgentBehaviourOdorTrackerBehaviourDirectionSurfBehaviourTimeHorizon<ObjectAgentActiveStep>>;
}

#endif
