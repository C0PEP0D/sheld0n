#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_ACTIVE_PASSIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_ACTIVE_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your object
#include "core/env/objects/object/passive/spheroid/core.h"
#include "param/env/objects/static/object/agent/_active/_passive/spheroid/parameters.h"
namespace c0p {
    using ObjectAgentActivePassiveStep = PassiveSpheroidStep<ObjectAgentActivePassiveSpheroidStepParameters>;
}

#endif
