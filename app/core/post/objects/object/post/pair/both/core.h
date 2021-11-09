#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_PAIR_BOTH_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_PAIR_BOTH_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <vector>
//#include <execution>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/pair/both/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class PostPostPairBoth : public PostPostPost<TypeObjectStep> {
    public:
        TypeParameters parameters;
        typename TypeParameters::TypePostPostA<typename TypeObjectStep::TypeAStep> postA;
        typename TypeParameters::TypePostPostB<typename TypeObjectStep::TypeBStep> postB;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
        PostPostPairBoth(std::shared_ptr<TypeObjectStep> p_sObjectStep) : PostPostPost<TypeObjectStep>(p_sObjectStep), postA(sObjectStep->sAStep), postB(sObjectStep->sBStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const TypeVector<Eigen::Dynamic>& state, const double& t) override {
            // compute
            std::map<std::string, TypeScalar> processed;
            for(const auto& p : postA(sObjectStep->cAState(state), t)) {
                processed["a__" + p.first] = p.second;
            }
            for(const auto& p : postB(sObjectStep->cBState(state), t)) {
                processed["b__" + p.first] = p.second;
            }
            // return
            return processed;
        };
};

}

#endif
