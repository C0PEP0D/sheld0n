#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_DISCONTINUOUS_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_DISCONTINUOUS_PROP_H
#pragma once

// lib includes
#include "sl0/chain/manager.h"
// app include
#include "core/env/objects/object/group/prop.h"

namespace c0p {

template<typename TypeMemberStep>
using TypeChainDiscontinuousStep = sl0::StepChainManager<TypeVector, DIM, TypeView, TypeRef, TypeMemberStep>;

}

#endif
