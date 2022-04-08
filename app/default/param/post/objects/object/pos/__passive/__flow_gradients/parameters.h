#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_PASSIVE_FLOW_GRADIENTS_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_PASSIVE_FLOW_GRADIENTS_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/flow_gradients/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostObjectPosPassiveFlowGradientsParameters {
    std::string name = "j";
};

}

#endif
