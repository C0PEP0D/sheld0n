#ifndef C0P_PARAM_POST_MESH_UNIFORM_PARAMETERS_H
#define C0P_PARAM_POST_MESH_UNIFORM_PARAMETERS_H
#pragma once

// app include
#include "core/post/mesh/uniform/prop.h"

namespace c0p {

// Uniform post processing mesh parameters
struct PostMeshMeshUniformParameters {
    // Number of nodes of the mesh for each dimension
    std::vector<std::size_t> n = { 16, 16, 16 };
    // Length of the mesh for each dimension
    std::vector<TypeScalar> length = { 2.0 * M_PI, 2.0 * M_PI, 2.0 * M_PI };
    // Origin position of the mesh
    TypeSpaceVector origin = TypeSpaceVector::Constant(0.0);
    
};

}

#endif
