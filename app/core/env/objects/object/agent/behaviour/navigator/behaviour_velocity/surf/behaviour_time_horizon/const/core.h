#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_BEHAVIOUR_TIME_HORIZON_CONST_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_BEHAVIOUR_TIME_HORIZON_CONST_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/behaviour_time_horizon/const/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/behaviour_time_horizon/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizonConst : public AgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizon<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizonConst() {
        }
    public:
        TypeScalar operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive, const TypeSpaceMatrix& gradientsMeasure) const override{
            return parameters.value;
        }
};


}

#endif
