#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/agent/sensor_velocity_gradients/core.h"
#include "param/post/objects/object/pos/agent/sensor_velocity_gradients/parameters.h"
namespace c0p {
    template<typename TypeObjectStep>
    using PostObjectPosAgentSensorVelocityGradients = PostPostAgentSensorVelocityGradients<PostObjectPosAgentSensorVelocityGradientsParameters, TypeObjectStep>;
}

#endif
