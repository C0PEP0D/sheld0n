#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_PROP_H
#pragma once

// lib includes
#include "sl0/group/dynamic.h"
// app include
#include "core/env/objects/object/group/prop.h"

namespace c0p {

using TypeGroupHomogeneousStep = sl0::StepGroupDynamic<TypeVector, DIM, TypeRef, TypeView, sl0::StepObject<TypeVector, DIM, TypeRef>>;

}

#endif
