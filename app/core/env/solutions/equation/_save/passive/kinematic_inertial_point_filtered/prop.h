#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_FILTERED_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_FILTERED_PROP_H
#pragma once

// lib include
#include "sl0/point_inertial_kinematic_filtered.h"
// app include
#include "core/env/objects/object/passive/prop.h"

namespace c0p {

using TypePassiveKinematicInertialPointFilteredStep = sl0::StepPointInertialKinematicFiltered<TypeVector, TypeMatrix, DIM, TypeView, Flow>;

}

#endif
