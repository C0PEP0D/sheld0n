#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_SENSOR_POSITION_DISTANCE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_SENSOR_POSITION_DISTANCE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/agent/sensor_position_distance/core.h"
#include "param/post/objects/object/pos/agent/sensor_position_distance/parameters.h"
namespace c0p {
    template<typename TypeObjectStep>
    using PostObjectPosAgentSensorPositionDistance = PostPostAgentSensorPositionDistance<PostObjectPosAgentSensorPositionDistanceParameters, TypeObjectStep>;
}

#endif
