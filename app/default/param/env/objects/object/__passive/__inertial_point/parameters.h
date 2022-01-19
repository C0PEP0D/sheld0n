#ifndef C0P_PARAM_OBJECTS_OBJECT_PASSIVE_INERTIAL_POINT_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_PASSIVE_INERTIAL_POINT_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/inertial_point/prop.h"

// parameters
#include "param/parameters.h"

namespace c0p {

// Parameters of a spheroid that can be advected and rotated by the flow
struct ObjectPassiveInertialPointStepParameters {
    // Delay: inertial delay, characteristic time to reach a steady velocity in a steady flow
    static TypeScalar delay = 1.0 * Parameters::cTime;
};

}

#endif
