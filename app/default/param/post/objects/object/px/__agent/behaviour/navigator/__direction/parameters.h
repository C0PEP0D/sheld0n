#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_PX_AGENT_BEHAVIOUR_NAVIGATOR_DIRECTION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_PX_AGENT_BEHAVIOUR_NAVIGATOR_DIRECTION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/agent/behaviour/navigator/direction/prop.h"

namespace c0p {

// Swimming direction post processing parameter
struct PostObjectPxAgentBehaviourNavigatorDirectionParameters {
    std::string name = "dir";
    // Component index of the swimming direction to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
