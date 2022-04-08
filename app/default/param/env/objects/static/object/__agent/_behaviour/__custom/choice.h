#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/custom/local_axis_swimmer/core.h"
#include "param/env/objects/static/object/agent/_behaviour/custom/local_axis_swimmer/parameters.h"
namespace c0p {
    template<typename ObjectAgentActiveStep>
    using ObjectAgentBehaviourCustom = AgentBehaviourCustomLocalAxisSwimmer<ObjectAgentBehaviourCustomLocalAxisSwimmerParameters, ObjectAgentActiveStep>;
}

#endif
