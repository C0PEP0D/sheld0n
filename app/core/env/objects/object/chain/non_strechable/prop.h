#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_NON_STRECHABLE_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_NON_STRECHABLE_PROP_H
#pragma once

// lib includes
#include "sl0/chain/static.h"
// app include
#include "core/env/objects/object/group/prop.h"

namespace c0p {

template<unsigned int Size, typename TypeMemberStep>
using TypeChainNonStrechableStep = sl0::StepChainStatic<TypeVector, DIM, TypeRef, Size, TypeView, TypeMemberStep>;

}

#endif
