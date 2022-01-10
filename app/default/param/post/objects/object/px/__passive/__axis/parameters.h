#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_PX_PASSIVE_AXIS_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_PX_PASSIVE_AXIS_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/axis/prop.h"

namespace c0p {

// Axis post processing parameter
struct PostObjectPxPassiveAxisParameters {
    std::string name = "axis";
    // Component index of the axis to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
