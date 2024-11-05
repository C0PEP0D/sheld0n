#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_FILTERED_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_KINEMATIC_INERTIAL_POINT_FILTERED_CORE_H
#pragma once

// App includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/passive/kinematic_inertial_point_filtered/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveKinematicInertialPointFilteredStep : public TypePassiveKinematicInertialPointFilteredStep {
    public:
        using Type = TypePassiveKinematicInertialPointFilteredStep;
    public:
        TypeParameters parameters;
    public:
        PassiveKinematicInertialPointFilteredStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(sFlow, 0.0, TypeSpaceVector::Zero(), 0.0) {
        	Type::delay = parameters.delay;
        	Type::velocity = parameters.velocity;
        	Type::dt = parameters.dt;
        }
};

}

#endif
