#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_PROP_H
#pragma once

// lib includes
#include "sa0/active.h"
// app include
#include "core/env/objects/object/prop.h"

namespace c0p {

template<typename ActivePassiveStep>
using TypeActiveStep = sl0::sa0::StepActive<TypeView, ActivePassiveStep, sl0::sa0::StepActuator<ActivePassiveStep>>;

}

#endif
