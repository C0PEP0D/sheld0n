#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/static/object/agent/_behaviour/navigator/_behaviour_velocity/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/sprinter/core.h"
#include "param/env/objects/static/object/agent/_behaviour/navigator/_behaviour_velocity/surf/sprinter/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourNavigatorBehaviourVelocitySurf = AgentBehaviourNavigatorBehaviourVelocitySurfSprinter<ObjectAgentBehaviourNavigatorBehaviourVelocitySurfSprinterParameters, ObjectAgentActiveStep, ObjectAgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizon<ObjectAgentActiveStep>>;
}

#endif
