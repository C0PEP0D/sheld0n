#ifndef C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_CHOICE_H
#pragma once

#include "param/env/objects/object/pair/_a/agent/_active/choice.h"
// choose your behaviour
#include "param/env/objects/object/pair/_a/agent/_behaviour/swim_in_direction/swimming_direction/choice.h"
namespace c0p {
    template<typename ObjectPairAAgentActiveStep>
    using ObjectPairAAgentBehaviourSwimInDirection = ObjectPairAAgentBehaviourSwimInDirectionSwimmingDirection<ObjectPairAAgentActiveStep>;
}

#endif
