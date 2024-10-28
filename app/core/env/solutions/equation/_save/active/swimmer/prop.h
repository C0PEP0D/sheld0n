#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_SWIMMER_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_SWIMMER_PROP_H
#pragma once

// lib includes
#include "sa0/actuator/point.h"
// app includes
#include "core/env/objects/object/active/prop.h"

namespace c0p {

template<typename ActivePassiveStep>
using TypeSwimStep = sl0::sa0::StepPointSwim<ActivePassiveStep>;

}

#endif
