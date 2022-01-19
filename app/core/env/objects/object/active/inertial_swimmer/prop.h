#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_INERTIAL_SWIMMER_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_INERTIAL_SWIMMER_PROP_H
#pragma once

// lib includes
#include "sa0/actuator/point_inertial.h"
// app includes
#include "core/env/objects/object/active/prop.h"

namespace c0p {

template<typename ActivePassiveStep>
using TypeInertialSwimStep = sl0::sa0::StepInertialSwim<ActivePassiveStep>;

}

#endif
