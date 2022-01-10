#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_PASSIVE_AXIS_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_PASSIVE_AXIS_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/passive/axis/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostPassiveAxis : public PostPostPost<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
    public:
        std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
            return {
                { parameters.name + "_" + std::to_string(parameters.i), sObjectStep->cAxis(pState)[parameters.i] }
            };
        };
};

}

#endif
