#ifndef C0P_PARAM_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_FILTERED_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_FILTERED_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/kinematic_inertial_point_filtered/prop.h"

// parameters
#include "param/parameters.h"

namespace c0p {

// Parameters of a spheroid that can be advected and rotated by the flow
struct ObjectPassiveKinematicInertialPointFilteredStepParameters {
    // Delay: inertial delay, characteristic time to reach a steady velocity in a steady flow
    TypeScalar delay = 1.0 * Parameters::cTime;
    TypeSpaceVector velocity = 1.0 * Parameters::cVelocity * TypeSpaceVector({1.0, 0.0, 0.0});
    TypeScalar dt = 0.25 * Parameters::cTime;
};

}

#endif
