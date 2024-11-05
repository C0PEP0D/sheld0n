#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_PROP_H
#pragma once

// lib include
#include "sl0/point_inertial_kinematic.h"
// app include
#include "core/env/objects/object/passive/prop.h"

namespace c0p {

using TypePassiveKinematicInertialPointStep = sl0::StepPointInertialKinematic<TypeVector, DIM, TypeView, Flow>;

}

#endif
