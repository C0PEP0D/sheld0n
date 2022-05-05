#ifndef C0P_PARAM_POST_MESH_UNIFORM_PARAMETERS_H
#define C0P_PARAM_POST_MESH_UNIFORM_PARAMETERS_H
#pragma once

// app include
#include "core/post/mesh/uniform/prop.h"

namespace c0p {

// Uniform post processing mesh parameters
struct PostMeshMeshUniformParameters {
    // Number of nodes of the mesh for each dimension
    std::vector<std::size_t> n = { 4, 4, 4 };
    // Length of the mesh for each dimension
    std::vector<TypeScalar> length = { 1.0, 1.0, 1.0 };
    // Origin position of the mesh
    TypeSpaceVector origin = TypeSpaceVector::Constant(-0.5);
    
};

}

#endif
