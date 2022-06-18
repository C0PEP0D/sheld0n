#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_CORE_H
#pragma once

// App includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/passive/kinematic_inertial_point/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveKinematicInertialPointStep : public TypePassiveKinematicInertialPointStep {
    public:
        using Type = TypePassiveKinematicInertialPointStep;
    public:
        TypeParameters parameters;
    public:
        PassiveKinematicInertialPointStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(sFlow, 0.0, TypeSpaceVector::Zero()) {
        	Type::delay = parameters.delay;
        	Type::velocity = parameters.velocity;
        }
};

}

#endif
