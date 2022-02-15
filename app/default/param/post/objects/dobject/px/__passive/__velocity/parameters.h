#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PX_PASSIVE_VELOCITY_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PX_PASSIVE_VELOCITY_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/velocity/prop.h"

namespace c0p {

// Position post processing parameter
struct PostDobjectPxPassiveVelocityParameters {
    std::string name = "v";
    // Component index of the velocity to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
