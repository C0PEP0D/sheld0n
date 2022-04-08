#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/local_axis_swimmer/core.h"
#include "param/env/objects/static/object/agent/_behaviour/navigator/local_axis_swimmer/parameters.h"
// sensor choice
#include "param/env/objects/static/object/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/object/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/static/object/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/static/object/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourNavigator = AgentBehaviourNavigatorLocalAxisSwimmer<ObjectAgentBehaviourNavigatorLocalAxisSwimmerParameters, ObjectAgentActiveStep, ObjectAgentBehaviourSensorDirection<ObjectAgentActiveStep>, ObjectAgentBehaviourSensorVelocityGradients<ObjectAgentActiveStep>, ObjectAgentBehaviourNavigatorBehaviourDirection<ObjectAgentActiveStep>, ObjectAgentBehaviourNavigatorBehaviourVelocity<ObjectAgentActiveStep>>;
}

#endif
