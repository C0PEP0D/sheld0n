#ifndef C0P_PARAM_POST_FLOW_PARAMETERS_H
#define C0P_PARAM_POST_FLOW_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMANDS ARE USED

// std include
#include <memory> // shared_ptr
#include <vector>
#include <string>
// app include
#include "core/post/flow/post/core.h"
// FLAG: INCLUDE POST BEGIN
#include "param/post/flow/ux/choice.h"
#include "param/post/flow/uz/choice.h"
#include "param/post/flow/uy/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

struct PostFlowParameters {
    // make data
    std::vector<std::shared_ptr<PostFlowPost>> data;
    PostFlowParameters(std::shared_ptr<Flow> sFlow, std::shared_ptr<PostMeshMesh::Type> sMesh) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostFlowUx>(sFlow, sMesh));
        data.push_back(std::make_shared<PostFlowUz>(sFlow, sMesh));
        data.push_back(std::make_shared<PostFlowUy>(sFlow, sMesh));
        // FLAG: MAKE POST END
    }
};

}

#endif
