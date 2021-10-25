#ifndef C0P_PARAM_OBJECTS_TRACERS_POS_GROUP_BOX_PARAMETERS_H
#define C0P_PARAM_OBJECTS_TRACERS_POS_GROUP_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/group/box/prop.h"

#include "param/parameters.h"

namespace c0p {

// Group members position initialisation uniformly in a box parameters
struct InitTracersPosGroupBoxParameters {
    // Origin of the box
    TypeSpaceVector origin = TypeSpaceVector::Zero();
    // Length of the box for each dimension
    std::vector<double> l = std::vector<double>(3, 2 * M_PI);
};

}

#endif
