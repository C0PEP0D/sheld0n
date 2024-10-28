#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon {
    public:
        AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon() {
        }
    public:
        virtual TypeScalar operator()(const double* pState, const double& t, const AgentActiveStep& stepActive, const TypeSpaceMatrix& velocityGradients) const = 0;
};


}

#endif
