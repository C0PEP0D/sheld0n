#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "param/env/objects/object/agent/_behaviour/navigator/choice.h"
// choose your active part
#include "param/env/objects/object/agent/_active/choice.h"
namespace c0p {
    using ObjectAgentBehaviour = ObjectAgentBehaviourNavigator<ObjectAgentActiveStep>;
}

#endif
