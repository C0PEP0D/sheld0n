#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_POS_CHAIN_COORDINATE_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_POS_CHAIN_COORDINATE_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/chain/coordinate/prop.h"

#include "param/parameters.h"

namespace c0p {

// Position post processing parameter
struct PostDobjectPosChainCoordinateParameters {
    std::string name = "l";
    // Position along the chain. 0 <= s <= 1.
    double dl = 0.01;
};

}

#endif
