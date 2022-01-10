#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_LOCAL_AXIS_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_LOCAL_AXIS_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/odor_tracker/local_axis_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorPosition, typename TypeSensorVelocityGradients, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourOdorTrackerLocalAxisSwimmer : public sl0::sa0::Behaviour<AgentActiveStep> {
    public:
        using Type = sl0::sa0::Behaviour<AgentActiveStep>;
    public:
        TypeParameters parameters;
        // sensors
        TypeSensorPosition sensorPosition;
        TypeSensorVelocityGradients sensorVelocityGradients;
        // sub behaviours
        TypeBehaviourDirection behaviourDirection;
        TypeBehaviourVelocity behaviourVelocity;
    public:
        AgentBehaviourOdorTrackerLocalAxisSwimmer(std::shared_ptr<Objects> sObjects) : sensorPosition(std::shared_ptr<Objects> sObjects) {
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const override {
            TypeContainer<TypeSpaceVector> result;
            // sensors
            const TypeContainer<TypeSpaceVector> positionsSensorPosition = sensorPosition.positions(pState, stepActive);
            result.insert(result.end(), positionsSensorPosition.begin(), positionsSensorPosition.end());
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
            const TypeSpaceVector direction = sensorPosition(pState, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(pState, t, stepActive);
            const TypeSpaceVector swimmingDirection = stepActive.cAxis(pState);
            stepActive.sStepAxisOrient->direction = behaviourDirection(pState, t, stepActive, direction, velocityGradients).normalized();
            stepActive.sStepLocalAxisSwim->velocity = behaviourVelocity(pState, t, stepActive, direction, velocityGradients, swimmingDirection) * stepActive.parameters.velocity;
        }
};


}

#endif
