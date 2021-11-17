#ifndef C0P_CORE_POST_FLOW_POST_U_CORE_H
#define C0P_CORE_POST_FLOW_POST_U_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/flow/post/core.h"
#include "core/post/flow/post/u/prop.h"

namespace c0p {

template<typename TypeParameters>
class PostFlowU : public PostFlowPost {
    public:
        TypeParameters parameters;
    public:
        using PostFlowPost::sFlow;
        using PostFlowPost::sMesh;
    public:
        using PostFlowPost::PostFlowPost;
    public:
        std::map<std::string, TypeScalar> operator()(const double& t) override {
            // Init
            std::map<std::string, TypeScalar> processed;
            // Members process
            for(const auto& index : sMesh->indexCells()) {
                processed["mesh_index_" + std::to_string(index) + "__" + parameters.name + "_" + std::to_string(parameters.i)] = sFlow->getVelocity(sMesh->positionCell(index), t)[parameters.i];
            }
            return processed;
        };
};

}

#endif
