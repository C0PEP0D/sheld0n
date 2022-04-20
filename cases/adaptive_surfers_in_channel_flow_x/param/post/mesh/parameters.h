#ifndef C0P_PARAM_POST_MESH_PARAMETERS_H
#define C0P_PARAM_POST_MESH_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMANDS ARE USED

// std include
#include <memory> // shared_ptr
#include <vector>
#include <string>
// app include
#include "core/post/mesh/post/core.h"
// FLAG: INCLUDE POST BEGIN
#include "param/post/mesh/px/choice.h"
#include "param/post/mesh/py/choice.h"
#include "param/post/mesh/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

struct PostMeshParameters {
    // make data
    std::vector<std::shared_ptr<PostMeshPost>> data;
    PostMeshParameters(std::shared_ptr<PostMeshMesh::Type> sMesh) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostMeshPx>(sMesh));
        data.push_back(std::make_shared<PostMeshPy>(sMesh));
        data.push_back(std::make_shared<PostMeshPz>(sMesh));
        // FLAG: MAKE POST END
    }
};

}

#endif
