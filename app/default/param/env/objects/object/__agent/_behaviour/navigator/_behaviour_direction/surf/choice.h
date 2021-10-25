#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/object/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/object/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// behaviour time horizon choice
#include "param/env/objects/object/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/object/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<ObjectAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, ObjectAgentActiveStep, ObjectAgentBehaviourSensorDirection<ObjectAgentActiveStep>, ObjectAgentBehaviourSensorVelocityGradients<ObjectAgentActiveStep>, ObjectAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<ObjectAgentActiveStep>>;
}

#endif
