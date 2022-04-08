#ifndef C0P_CORE_ENV_OBJECTS_PROP_H
#define C0P_CORE_ENV_OBJECTS_PROP_H
#pragma once

// lib includes
#include "sl0/object.h"
// app include
#include "core/env/prop.h"
#include "param/env/flow/choice.h"

namespace c0p {
    class ObjectsParameters;

    using StepObjectStatic = sl0::StepObjectStaticBase<TypeVector, DIM>;
    using StepObjectDynamic = sl0::StepGroupDynamicHomogeneousBase<TypeVector, DIM>;
    using StepObjectManager = sl0::StepManagerHomogeneousBase<TypeVector, DIM>;
}

#endif
