#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_SWIMMER_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/custom/swimmer/prop.h"

// sensor choice
#include "param/env/objects/static/object/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/object/agent/_behaviour/_sensor/velocity_gradients/choice.h"

namespace c0p {

// Parameters of the step of a custom that controls its swimming direction
// delayed by a finite reorientation time
template<typename AgentActiveStep>
struct ObjectAgentBehaviourCustomSwimmerParameters {
    public:
        // Sensors declaration
        ObjectAgentBehaviourSensorDirection<AgentActiveStep> sensorDirection;
        ObjectAgentBehaviourSensorVelocityGradients<AgentActiveStep> sensorVelocityGradients;
    public:
        // Behaviour
        void operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const {
            const TypeSpaceVector direction = sensorDirection(pState, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(pState, t, stepActive);
            stepActive.sStepSwim->velocity = direction * stepActive.parameters.velocity.norm();
        }
    public:
        // Positions
        TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const {
            TypeContainer<TypeSpaceVector> result;
            // sensors
            const TypeContainer<TypeSpaceVector> positionsSensorDirection = sensorDirection.positions(pState, stepActive);
            result.insert(result.end(), positionsSensorDirection.begin(), positionsSensorDirection.end());
            const TypeContainer<TypeSpaceVector> positionsSensorVelocityGradients = sensorVelocityGradients.positions(pState, stepActive);
            result.insert(result.end(), positionsSensorVelocityGradients.begin(), positionsSensorVelocityGradients.end());
            // return
            return result;
        }
};

}

#endif
