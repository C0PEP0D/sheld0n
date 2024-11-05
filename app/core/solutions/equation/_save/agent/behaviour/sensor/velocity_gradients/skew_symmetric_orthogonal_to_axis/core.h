#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SKEW_SYMMETRIC_ORTHOGONAL_TO_AXIS_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SKEW_SYMMETRIC_ORTHOGONAL_TO_AXIS_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/skew_symmetric_orthogonal_to_axis/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsSkewSymmetricOrthogonalToAxis : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
	public:
		TypeParameters parameters;
	public:
		AgentBehaviourSensorVelocityGradientsSkewSymmetricOrthogonalToAxis() {
		}
	public:
		TypeSpaceMatrix operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
			const TypeSpaceMatrix velocityGradients = stepActive.sFlow->getVelocityGradients(stepActive.cX(pState), t);
			TypeSpaceMatrix skewVelocityGradients = 0.5 * (velocityGradients - velocityGradients.transpose());
			if(parameters.axis == 0) {
				skewVelocityGradients(1, 2) = 0.0;
				skewVelocityGradients(2, 1) = 0.0;
			} else if (parameters.axis == 1) {
				skewVelocityGradients(0, 2) = 0.0;
				skewVelocityGradients(2, 0) = 0.0;
			} else if (parameters.axis == 2) {
				skewVelocityGradients(0, 1) = 0.0;
				skewVelocityGradients(1, 0) = 0.0;
			}
			return skewVelocityGradients;
		}
};


}

#endif
