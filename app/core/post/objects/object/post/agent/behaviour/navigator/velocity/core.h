#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_AGENT_BEHAVIOUR_NAVIGATOR_VELOCITY_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_AGENT_BEHAVIOUR_NAVIGATOR_VELOCITY_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/agent/behaviour/navigator/velocity/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostAgentBehaviourNavigatorVelocity : public PostPostPost<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
    public:
        std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
            const TypeSpaceVector direction = sObjectStep->sBehaviour->sensorDirection(pState, t, *sObjectStep);
            const TypeSpaceMatrix velocityGradients = sObjectStep->sBehaviour->sensorVelocityGradients(pState, t, *sObjectStep);
            const TypeSpaceVector swimmingDirection = sObjectStep->cAxis(pState);
            return {
                { parameters.name, sObjectStep->sBehaviour->behaviourVelocity(pState, t, *sObjectStep, direction, velocityGradients, swimmingDirection) * (*sObjectStep).parameters.velocity }
            };
        };
};

}

#endif
