#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_LOCAL_AXIS_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_LOCAL_AXIS_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/tracker/local_axis_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorPosition, typename TypeSensorVelocityGradients, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourTrackerLocalAxisSwimmer : public sl0::sa0::Behaviour<typename AgentActiveStep::TypeStateStatic, TypeRef, AgentActiveStep> {
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
        AgentBehaviourTrackerLocalAxisSwimmer(std::shared_ptr<Objects> sObjects) : sensorPosition(std::shared_ptr<Objects> sObjects) {
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
            const TypeSpaceVector direction = sensorPosition(state, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(state, t, stepActive);
            const TypeSpaceVector swimmingDirection = stepActive.cAxis(state);
            stepActive.sStepAxisOrient->direction = behaviourDirection(state, t, stepActive, direction, velocityGradients).normalized();
            stepActive.sStepLocalAxisSwim->velocity = behaviourVelocity(state, t, stepActive, direction, velocityGradients, swimmingDirection) * stepActive.parameters.velocity;
        }
};


}

#endif
