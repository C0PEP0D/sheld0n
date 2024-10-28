#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_BASIS_SWIMMER_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_BASIS_SWIMMER_PROP_H
#pragma once

// lib includes
#include "sa0/actuator/basis.h"
// app includes
#include "core/env/objects/object/active/prop.h"

namespace c0p {

template<typename ActivePassiveStep>
using TypeLocalBasisSwimStep = sl0::sa0::StepBasisSwim<ActivePassiveStep>;
template<typename ActivePassiveStep>
using TypeBasisOrientStep = sl0::sa0::StepBasisOrient<ActivePassiveStep>;

}

#endif
