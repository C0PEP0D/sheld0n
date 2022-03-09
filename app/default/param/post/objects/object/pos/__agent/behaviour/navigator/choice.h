#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/agent/behaviour/navigator/velocity/core.h"
#include "param/post/objects/object/pos/agent/behaviour/navigator/velocity/parameters.h"
namespace c0p {
    template<typename TypeObjectStep>
    using PostObjectPosAgentBehaviourNavigator = PostPostAgentBehaviourNavigatorVelocity<PostObjectPosAgentBehaviourNavigatorVelocityParameters, TypeObjectStep>;
}

#endif
