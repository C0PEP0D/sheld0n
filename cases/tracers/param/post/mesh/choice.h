#ifndef C0P_PARAM_POST_MESH_CHOICE_H
#define C0P_PARAM_POST_MESH_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your mesh
#include "core/post/mesh/regular/core.h"
#include "param/post/mesh/regular/parameters.h"
namespace c0p {
    using PostMeshMesh = PostMeshMeshRegular<PostMeshMeshRegularParameters>;
}

#endif
