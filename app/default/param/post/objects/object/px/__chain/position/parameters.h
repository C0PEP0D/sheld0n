#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_PX_CHAIN_POSITION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_PX_CHAIN_POSITION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/chain/position/prop.h"

#include "param/parameters.h"

namespace c0p {

// Position post processing parameter
struct PostObjectPxChainPositionParameters {
    std::string name = "pos";
    // Position along the chain. 0 <= s <= 1.
    double dl = 0.1 * Parameters::cLength;
    // Component index of the position to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif