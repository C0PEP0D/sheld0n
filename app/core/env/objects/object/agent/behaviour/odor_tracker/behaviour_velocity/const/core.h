#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_VELOCITY_CONST_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_VELOCITY_CONST_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_velocity/const/prop.h"
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_velocity/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourOdorTrackerBehaviourVelocityConst : public AgentBehaviourOdorTrackerBehaviourVelocity<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourOdorTrackerBehaviourVelocityConst() {
        }
    public:
        double operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients, const TypeSpaceVector& swimmingDirection) const override {
            return 1.0;
        }
};


}

#endif
