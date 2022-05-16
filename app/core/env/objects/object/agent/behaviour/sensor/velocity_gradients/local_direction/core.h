#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_LOCAL_DIRECTION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_LOCAL_DIRECTION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/local_direction/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsLocalDirection : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsLocalDirection() {
        }
    public:
        TypeSpaceMatrix operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
			// get data
            const TypeSpaceMatrix velocityGradients = stepActive.sFlow->getVelocityGradients(stepActive.cX(pState), t);
            const TypeSpaceVector globalDirection = stepActive.cBasis() * parameters.localDirection;
            // create new basis
            TypeSpaceMatrix newBasis;
            newBasis.col(0) = globalDirection;
            newBasis.col(1) = TypeSpaceVector::Random();
            newBasis.col(1) = (newBasis.col(1) - newBasis.col(1).dot(newBasis.col(0)) * newBasis.col(0)).normalized();
            newBasis.col(2) = newBasis.col(0).cross(newBasis.col(1));
            // symVelocityGradients in new basis
            TypeSpaceMatrix newBasisVelocityGradients = newBasis.transpose() * velocityGradients * newBasis;
            newBasisVelocityGradients.block<DIM,DIM-1>(0, 1).fill(0.0);
            // return to global space
			return newBasis * newBasisVelocityGradients * newBasis.transpose();
        }
};


}

#endif
