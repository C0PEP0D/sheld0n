#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SYMMETRIC_LOCAL_DIRECTION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SYMMETRIC_LOCAL_DIRECTION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/symmetric_local_direction/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsSymmetricLocalDirection : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsSymmetricLocalDirection() {
        }
    public:
        TypeSpaceMatrix operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
			// get data
            const TypeSpaceMatrix velocityGradients = stepActive.sFlow->getVelocityGradients(stepActive.cX(pState), t);
            const TypeSpaceMatrix symVelocityGradients = 0.5 * (velocityGradients + velocityGradients.transpose());
            const TypeSpaceVector globalDirection = stepActive.cBasis(pState) * parameters.localDirection;
            // create new basis
            TypeSpaceMatrix newBasis;
            newBasis.col(0) = globalDirection;
            newBasis.col(1) = TypeSpaceVector::Random();
            newBasis.col(1) = (newBasis.col(1) - newBasis.col(1).dot(newBasis.col(0)) * newBasis.col(0)).normalized();
            newBasis.col(2) = newBasis.col(0).cross(newBasis.col(1));
            // symVelocityGradients in new basis
            TypeSpaceMatrix newBasisSymVelocityGradients = newBasis.transpose() * symVelocityGradients * newBasis;
            newBasisSymVelocityGradients.block<DIM,DIM-1>(0, 1).fill(0.0);
            // return to global space
			return newBasis * newBasisSymVelocityGradients * newBasis.transpose();
        }
};


}

#endif
