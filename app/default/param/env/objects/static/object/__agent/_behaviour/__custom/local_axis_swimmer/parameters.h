#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_LOCAl_AXIS_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_LOCAl_AXIS_SWIMMER_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/custom/local_axis_swimmer/prop.h"

// sensor choice
#include "param/env/objects/object/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/object/agent/_behaviour/_sensor/velocity_gradients/choice.h"

namespace c0p {

// Parameters of the step of a custom that controls its swimming direction
// delayed by a finite reorientation time
template<typename TypeAgentStateStatic, typename AgentActiveStep>
struct ObjectAgentBehaviourCustomLocalAxisSwimmerParameters {
    public:
        // Sensors declaration
        ObjectAgentBehaviourSensorDirection<AgentActiveStep> sensorDirection;
        ObjectAgentBehaviourSensorVelocityGradients<AgentActiveStep> sensorVelocityGradients;
    public:
        // Behaviour
        void operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive) const {
            const TypeSpaceVector direction = sensorDirection(state, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(state, t, stepActive);
            const TypeSpaceVector swimmingDirection = stepActive.cAxis(state);
            stepActive.sStepAxisOrient->direction = direction;
            stepActive.sStepLocalAxisSwim->velocity = direction.dot(swimmingDirection) * stepActive.parameters.velocity;
        }
    public:
        // Positions
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const {
            TypeContainer<TypeSpaceVector> result;
            // sensors
            const TypeContainer<TypeSpaceVector> positionsSensorDirection = sensorDirection.positions(state, stepActive);
            result.insert(result.end(), positionsSensorDirection.begin(), positionsSensorDirection.end());
            const TypeContainer<TypeSpaceVector> positionsSensorVelocityGradients = sensorVelocityGradients.positions(state, stepActive);
            result.insert(result.end(), positionsSensorVelocityGradients.begin(), positionsSensorVelocityGradients.end());
            // return
            return result;
        }
};

}

#endif
