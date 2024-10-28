#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorDirection, typename TypeSensorVelocityGradients, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourNavigatorSwimmer : public sl0::sa0::Behaviour<AgentActiveStep> {
    public:
        using Type = sl0::sa0::Behaviour<AgentActiveStep>;
    public:
        TypeParameters parameters;
        // sensors
        TypeSensorDirection sensorDirection;
        TypeSensorVelocityGradients sensorVelocityGradients;
        // sub behaviours
        TypeBehaviourDirection behaviourDirection;
        TypeBehaviourVelocity behaviourVelocity;
    public:
        AgentBehaviourNavigatorSwimmer(std::shared_ptr<Objects> sObjects) : sensorDirection(sObjects) {
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const override {
            TypeContainer<TypeSpaceVector> result;
            // sensors
            const TypeContainer<TypeSpaceVector> positionsSensorDirection = sensorDirection.positions(pState, stepActive);
            result.insert(result.end(), positionsSensorDirection.begin(), positionsSensorDirection.end());
            const TypeContainer<TypeSpaceVector> positionsSensorVelocityGradients = sensorVelocityGradients.positions(pState, stepActive);
            result.insert(result.end(), positionsSensorVelocityGradients.begin(), positionsSensorVelocityGradients.end());
            // sub behaviours
            const TypeContainer<TypeSpaceVector> positionsBehaviourDirection = behaviourDirection.positions(pState, stepActive);
            result.insert(result.end(), positionsBehaviourDirection.begin(), positionsBehaviourDirection.end());
            const TypeContainer<TypeSpaceVector> positionsBehaviourVelocity = behaviourVelocity.positions(pState, stepActive);
            result.insert(result.end(), positionsBehaviourVelocity.begin(), positionsBehaviourVelocity.end());
            // return
            return result;
        }
    public:
        void operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const override {
            const TypeSpaceVector direction = sensorDirection(pState, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(pState, t, stepActive);
            const TypeSpaceVector swimmingDirection = behaviourDirection(pState, t, stepActive, direction, velocityGradients).normalized();
            stepActive.sStepSwim->velocity = swimmingDirection * behaviourVelocity(pState, t, stepActive, direction, velocityGradients, swimmingDirection) * stepActive.parameters.velocity.norm();
        }
};


}

#endif
