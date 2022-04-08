#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_CHAIN_POSITION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_CHAIN_POSITION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/chain/position/prop.h"

#include "param/parameters.h"

namespace c0p {

// Position post processing parameter
struct PostObjectPosChainPositionParameters {
    std::string name = "pos";
    // Length increment
    double dl = 0.01;
};

}

#endif
