#ifndef C0P_PARAM_OBJECTS_OBJECT_PAIR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "core/env/objects/object/pair/simple/core.h"
#include "param/env/objects/static/object/pair/simple/parameters.h"
#include "param/env/objects/static/object/pair/_a/choice.h"
#include "param/env/objects/static/object/pair/_b/choice.h"
namespace c0p {
    using ObjectPairStep = PairSimpleStep<ObjectPairSimpleStepParameters, ObjectPairAStep, ObjectPairBStep>;
}

#endif
