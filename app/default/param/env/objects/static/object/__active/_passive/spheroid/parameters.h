#ifndef C0P_PARAM_OBJECTS_OBJECT_ACTIVE_PASSIVE_SPHEROID_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_ACTIVE_PASSIVE_SPHEROID_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/spheroid/prop.h"

namespace c0p {

// Parameters of the step of spheroidal particle advected and rotated by a flow
struct ObjectActivePassiveSpheroidStepParameters {
    // Proportion: fraction of the big axis over the small axis
    TypeScalar proportion = 1.0;
};

}

#endif
