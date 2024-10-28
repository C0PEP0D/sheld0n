#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_SPHEROID_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_SPHEROID_PROP_H
#pragma once

// lib include
#include "sl0/spheroid.h"
// app include
#include "core/env/objects/object/passive/prop.h"

namespace c0p {

using TypePassiveSpheroidStep = sl0::StepSpheroid<TypeVector, DIM, TypeView, Flow>;

}

#endif
