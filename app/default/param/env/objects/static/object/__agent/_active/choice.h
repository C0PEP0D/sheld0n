#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_ACTIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/static/object/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/static/object/agent/_active/local_axis_swimmer/parameters.h"
#include "core/env/objects/object/active/local_axis_swimmer/core.h"
namespace c0p {
    using ObjectAgentActiveStep = ActiveLocalAxisSwimmerStep<ObjectAgentActiveLocalAxisSwimmerStepParameters, ObjectAgentActivePassiveStep>;
}

#endif
