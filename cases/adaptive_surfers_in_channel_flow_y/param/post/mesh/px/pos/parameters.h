#ifndef C0P_PARAM_POST_MESH_PX_POS_PARAMETERS_H
#define C0P_PARAM_POST_MESH_PX_POS_PARAMETERS_H
#pragma once

// app include
#include "core/post/mesh/post/pos/prop.h"

namespace c0p {

// Position post processing mesh parameters
struct PostMeshPxPosParameters {
    std::string name = "pos";
    // Component index of the position to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
