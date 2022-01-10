#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_AXIS_SWIMMER_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_AXIS_SWIMMER_PROP_H
#pragma once

// lib includes
#include "sa0/actuator/axis.h"
// app includes
#include "core/env/objects/object/active/prop.h"

namespace c0p {

template<typename ActivePassiveStep>
using TypeLocalAxisSwimStep = sl0::sa0::StepAxisSwim<ActivePassiveStep>;
template<typename ActivePassiveStep>
using TypeAxisOrientStep = sl0::sa0::StepAxisOrient<ActivePassiveStep>;

}

#endif
