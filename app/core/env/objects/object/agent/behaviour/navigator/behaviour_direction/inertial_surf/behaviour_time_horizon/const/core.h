#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_INERTIAL_SURF_BEHAVIOUR_TIME_HORIZON_CONST_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_INERTIAL_SURF_BEHAVIOUR_TIME_HORIZON_CONST_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/inertial_surf/behaviour_time_horizon/const/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/inertial_surf/behaviour_time_horizon/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourDirectionInertialSurfBehaviourTimeHorizonConst : public AgentBehaviourNavigatorBehaviourDirectionInertialSurfBehaviourTimeHorizon<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourDirectionInertialSurfBehaviourTimeHorizonConst() {
        }
    public:
        TypeScalar operator()(const double* pState, const double& t, const AgentActiveStep& stepActive, const TypeSpaceMatrix& velocityGradients) const override{
            return parameters.value;
        }
};


}

#endif
