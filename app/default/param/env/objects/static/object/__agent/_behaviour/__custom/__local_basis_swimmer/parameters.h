#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/custom/local_basis_swimmer/prop.h"

// sensor choice
#include "param/env/objects/static/object/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/object/agent/_behaviour/_sensor/velocity_gradients/choice.h"

namespace c0p {

// Parameters of the step of a custom that controls its swimming direction
// delayed by a finite reorientation time
template<typename AgentActiveStep>
struct ObjectAgentBehaviourCustomLocalBasisSwimmerParameters {
    public:
        // Sensors declaration
        ObjectAgentBehaviourSensorDirection<AgentActiveStep> sensorDirection;
        ObjectAgentBehaviourSensorVelocityGradients<AgentActiveStep> sensorVelocityGradients;
    public:
        // Behaviour
        void operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const {
            const TypeSpaceVector direction = sensorDirection(pState, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(pState, t, stepActive);
            auto sAxis0 = stepActive.cAxis(pState, 0);
            auto sAxis1 = stepActive.cAxis(pState, 1);
            auto sAxis2 = stepActive.cAxis2(pState);
            const TypeSpaceVector swimmingDirection = stepActive.sStepBasisSwim.localDirection(0) * sAxis0 + stepActive.sStepBasisSwim.localDirection(1) * sAxis1 + stepActive.sStepBasisSwim.localDirection(2) * sAxis2;
            stepActive.sStepBasisOrient->globalDirection = direction;
            stepActive.sStepLocalBasisSwim->velocity = direction.dot(swimmingDirection) * stepActive.parameters.velocity;
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
