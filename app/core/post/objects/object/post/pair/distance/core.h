#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_PAIR_DISTANCE_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_PAIR_DISTANCE_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <vector>
//#include <execution>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/pair/distance/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class PostPostPairDistance : public PostPostPost<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
        PostPostPairDistance(std::shared_ptr<TypeObjectStep> p_sObjectStep) : PostPostPost<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const TypeVector<Eigen::Dynamic>& state, const double& t) override {
            // compute
            std::map<std::string, TypeScalar> processed;
            processed[parameters.name] = (sObjectStep->sAStep->cX(sObjectStep->cAState(state)) - sObjectStep->sBStep->cX(sObjectStep->cBState(state))).norm();
            // return
            return processed;
        };
};

}

#endif
