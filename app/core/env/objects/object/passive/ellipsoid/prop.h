#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_ELLIPSOID_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_ELLIPSOID_PROP_H
#pragma once

// lib include
#include "sl0/ellipsoid.h"
// app include
#include "core/env/objects/object/passive/prop.h"

namespace c0p {

using TypePassiveEllipsoidStep = sl0::StepEllipsoid<TypeVector, TypeMatrix, DIM, TypeView, Flow>;

}

#endif
