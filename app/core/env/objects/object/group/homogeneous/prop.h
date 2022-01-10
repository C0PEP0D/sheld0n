#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_PROP_H
#pragma once

// lib includes
#include "sl0/group/static.h"
// app include
#include "core/env/objects/object/group/prop.h"

namespace c0p {

template<typename TypeMemberStep, unsigned int Size>
using TypeGroupHomogeneousStep = sl0::StepGroupStatic<TypeVector, DIM, TypeView, TypeMemberStep, Size>;

}

#endif
