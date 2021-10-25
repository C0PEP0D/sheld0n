#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_SIMPLE_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_SIMPLE_PROP_H
#pragma once

// lib includes
#include "sl0/group/chain.h"
// app include
#include "core/env/objects/object/group/prop.h"

namespace c0p {

template<unsigned int Size, typename TypeMemberStep>
using TypeChainSimpleStep = sl0::StepGroupChain<TypeVector<-1>, TypeRef, Size, TypeView, TypeMemberStep>;

}

#endif
