#ifndef C0P_PARAM_OBJECTS_OBJECT_PASSIVE_ELLIPSOID_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_PASSIVE_ELLIPSOID_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/ellipsoid/prop.h"

namespace c0p {

// Parameters of a spheroid that can be advected and rotated by the flow
struct ObjectPassiveEllipsoidStepParameters {
    // Proportion: fraction of the big axis over the small axis
    std::vector<TypeScalar> dimensions = {1.0, 1.0, 1.0};
};

}

#endif
