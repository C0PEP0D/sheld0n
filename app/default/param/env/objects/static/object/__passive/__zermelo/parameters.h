#ifndef C0P_PARAM_OBJECTS_OBJECT_PASSIVE_ZERMELO_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_PASSIVE_ZERMELO_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/zermelo/prop.h"

namespace c0p {

// Parameters of a Zermelo objects that can be advected and rotated according to the Zermelo equation
struct ObjectPassiveZermeloStepParameters {
    // Factor: fraction of the big axis over the small axis
    TypeScalar factor = 1.0;
};

}

#endif
