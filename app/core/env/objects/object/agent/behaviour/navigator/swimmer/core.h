#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourNavigatorSwimmer : public sl0::sa0::Behaviour<typename AgentActiveStep::TypeStateStatic, TypeRef, AgentActiveStep> {
    public:
        using Type = sl0::sa0::Behaviour<typename AgentActiveStep::TypeStateStatic, TypeRef, AgentActiveStep>;
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
        TypeBehaviourDirection behaviourDirection;
        TypeBehaviourVelocity behaviourVelocity;
    public:
        AgentBehaviourNavigatorSwimmer(Objects<ObjectsParameters>* pObjects) {
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const override {
            TypeContainer<TypeSpaceVector> result;
            TypeContainer<TypeSpaceVector> positionsBehaviourDirection = behaviourDirection.positions(state, stepActive);
            result.insert(result.end(), positionsBehaviourDirection.begin(), positionsBehaviourDirection.end());
            TypeContainer<TypeSpaceVector> positionsBehaviourVelocity = behaviourVelocity.positions(state, stepActive);
            result.insert(result.end(), positionsBehaviourVelocity.begin(), positionsBehaviourVelocity.end());
            return result;
        }
    public:
        void operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive) const override {
            const TypeSpaceVector swimmingDirection = behaviourDirection(state, t, stepActive).normalized();
            stepActive.sStepSwim->velocity = swimmingDirection * behaviourVelocity(state, t, stepActive, swimmingDirection) * stepActive.parameters.velocity.norm();
        }
};


}

#endif
