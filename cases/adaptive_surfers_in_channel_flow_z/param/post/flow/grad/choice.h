#ifndef C0P_PARAM_POST_FLOW_GRAD_CHOICE_H
#define C0P_PARAM_POST_FLOW_GRAD_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/flow/post/gradients/core.h"
#include "param/post/flow/grad/gradients/parameters.h"
namespace c0p {
    using PostFlowGrad = PostFlowGradients<PostFlowGradGradientsParameters>;
}

#endif
