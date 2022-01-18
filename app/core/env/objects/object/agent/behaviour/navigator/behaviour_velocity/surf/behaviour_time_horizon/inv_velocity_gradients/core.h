#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/behaviour_time_horizon/inv_velocity_gradients/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/behaviour_time_horizon/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizonInvVelocityGradients : public AgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizon<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizonInvVelocityGradients() {
        }
    public:
        TypeScalar operator()(const double* pState, const double& t, const AgentActiveStep& stepActive, const TypeSpaceMatrix& velocityGradients) const override{
            const TypeScalar value = velocityGradients.norm();
            if(value > 0) {
                return parameters.prefactor / value;
            } else {
                return parameters.max;
            }
        }
};


}

#endif
