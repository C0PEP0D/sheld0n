#ifndef C0P_PARAM_POST_MESH_PZ_CHOICE_H
#define C0P_PARAM_POST_MESH_PZ_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/mesh/post/pos/core.h"
#include "param/post/mesh/pz/pos/parameters.h"
namespace c0p {
    using PostMeshPz = PostMeshPos<PostMeshPzPosParameters>;
}

#endif
