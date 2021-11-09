#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_SYMMETRIC_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_INV_velocity_GRADIENTS_SYMMETRIC_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/inv_velocity_gradients_symmetric/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetric : public AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetric() {
        }
    public:
        TypeScalar operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive, const TypeSpaceMatrix& velocityGradients) const override{
            const TypeScalar value = 0.5 * (velocityGradients + velocityGradients.transpose()).norm();
            if(value > 0) {
                return parameters.prefactor / value;
            } else {
                return parameters.max;
            }
        }
};


}

#endif
