#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_SURFACE_ELEMENT_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_SURFACE_ELEMENT_CORE_H
#pragma once

// App includes
#include "core/env/objects/object/passive/surface_element/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveSurfaceElementStep : public TypePassiveSurfaceElementStep {
    public:
        using Type = TypePassiveSurfaceElementStep;
    public:
        TypeParameters parameters;
    public:
        PassiveSurfaceElementStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(sFlow) {
        }
};

}

#endif
