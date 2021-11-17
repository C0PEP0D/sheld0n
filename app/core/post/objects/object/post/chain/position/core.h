#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_CHAIN_POSITION_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_CHAIN_POSITION_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <algorithm> // replace
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/chain/position/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostChainPosition : public PostPostPost<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
    public:
        std::map<std::string, TypeScalar> operator()(const TypeVector<Eigen::Dynamic>& state, const double& t) override {
            std::map<std::string, TypeScalar> processed;
            const unsigned int n = std::ceil(sObjectStep->length / parameters.dl);
            const double ds = 1.0 / (n - 1);
            for(unsigned int i = 0; i < n; i++) {
                const double s = i *ds;
                std::string sStr = std::to_string(s);
                std::replace(sStr.begin(), sStr.end(), '.', 'o');
                processed["s_" + sStr + "__" + parameters.name + "_" + std::to_string(parameters.i)] = sObjectStep->cX(state, s)[parameters.i];
            }
            return processed;
        };
};

}

#endif