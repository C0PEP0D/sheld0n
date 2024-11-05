#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_SURF_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_SURF_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_direction/surf/prop.h"
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeBehaviourTimeHorizon>
class AgentBehaviourOdorTrackerBehaviourDirectionSurf : public AgentBehaviourOdorTrackerBehaviourDirection<AgentActiveStep> {
    public:
        TypeParameters parameters;
        // Sub behaviours
        TypeBehaviourTimeHorizon behaviourTimeHorizon;
    public:
        AgentBehaviourOdorTrackerBehaviourDirectionSurf() {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const override {
            const TypeSpaceVector predictedPosition = (velocityGradients * -behaviourTimeHorizon(pState, t, stepActive, position, velocityGradients)).exp() * (position - stepActive.cX(pState)) + stepActive.cX(pState);
            return (position - stepActive.cX(pState)).normalized();
        }
};


}

#endif
