#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_CHAIN_COORDINATE_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_CHAIN_COORDINATE_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <algorithm> // replace
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/chain/coordinate/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostChainCoordinate : public PostPostPost<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
    public:
        std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
            std::map<std::string, TypeScalar> processed;
            const double length = sObjectStep->length(pState);
            const unsigned int n = std::ceil(length / parameters.dl);
            for(unsigned int i = 0; i < n + 1; i++) {
                const double l = i * parameters.dl;
                std::string lStr = std::to_string(l);
                std::replace(lStr.begin(), lStr.end(), '.', 'o');
                processed["l_" + lStr + "__" + parameters.name] = l;
            }
            return processed;
        };
};

}

#endif
