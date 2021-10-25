#ifndef C0P_CORE_POST_MESH_POST_POS_CORE_H
#define C0P_CORE_POST_MESH_POST_POS_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/mesh/post/core.h"
#include "core/post/mesh/post/pos/prop.h"

namespace c0p {

template<typename TypeParameters>
class PostMeshPos : public PostMeshPost {
    public:
        TypeParameters parameters;
    public:
        using PostMeshPost::sMesh;
    public:
        using PostMeshPost::PostMeshPost;
    public:
        std::map<std::string, TypeScalar> operator()() override {
            // Init
            std::map<std::string, TypeScalar> processed;
            // Members process
            for(const auto& index : sMesh->indexs()) {
                processed["mesh_index_" + std::to_string(index) + "__" + parameters.name + "_" + std::to_string(parameters.i)] = sMesh->x(index)[parameters.i];
            }
            return processed;
        };
};

}

#endif
