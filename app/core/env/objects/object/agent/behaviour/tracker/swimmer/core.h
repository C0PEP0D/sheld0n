#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/tracker/swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorPosition, typename TypeSensorVelocityGradients, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourTrackerSwimmer : public sl0::sa0::Behaviour<typename AgentActiveStep::TypeStateStatic, TypeRef, AgentActiveStep> {
    public:
        using Type = sl0::sa0::Behaviour<typename AgentActiveStep::TypeStateStatic, TypeRef, AgentActiveStep>;
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
        // sensors
        TypeSensorPosition sensorPosition;
        TypeSensorVelocityGradients sensorVelocityGradients;
        // sub behaviours
        TypeBehaviourDirection behaviourDirection;
        TypeBehaviourVelocity behaviourVelocity;
    public:
        AgentBehaviourTrackerSwimmer(std::shared_ptr<Objects> sObjects) : sensorPosition(sObjects) {
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const override {
            TypeContainer<TypeSpaceVector> result;
            // sensors
            const TypeContainer<TypeSpaceVector> positionsSensorPosition = sensorPosition.positions(state, stepActive);
            result.insert(result.end(), positionsSensorPosition.begin(), positionsSensorPosition.end());
            const TypeContainer<TypeSpaceVector> positionsSensorVelocityGradients = sensorVelocityGradients.positions(state, stepActive);
            result.insert(result.end(), positionsSensorVelocityGradients.begin(), positionsSensorVelocityGradients.end());
            // sub behaviours
            const TypeContainer<TypeSpaceVector> positionsBehaviourDirection = behaviourDirection.positions(state, stepActive);
            result.insert(result.end(), positionsBehaviourDirection.begin(), positionsBehaviourDirection.end());
            const TypeContainer<TypeSpaceVector> positionsBehaviourVelocity = behaviourVelocity.positions(state, stepActive);
            result.insert(result.end(), positionsBehaviourVelocity.begin(), positionsBehaviourVelocity.end());
            // return
            return result;
        }
    public:
        void operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive) const override {
            const TypeSpaceVector position = sensorPosition(state, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(state, t, stepActive);
            const TypeSpaceVector swimmingDirection = behaviourDirection(state, t, stepActive, position, velocityGradients).normalized();
            stepActive.sStepSwim->velocity = swimmingDirection * behaviourVelocity(state, t, stepActive, position, velocityGradients, swimmingDirection) * stepActive.parameters.velocity.norm();
        }
};


}

#endif
