#ifndef C0P_CORE_POST_MESH_POST_CORE_H
#define C0P_CORE_POST_MESH_POST_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <map>
#include <string>
// app includes
#include "core/post/mesh/post/prop.h"

namespace c0p {

class PostMeshPost {
    public:
        std::shared_ptr<PostMeshMesh::Type> sMesh;
    public:
        PostMeshPost(std::shared_ptr<PostMeshMesh::Type> p_sMesh) : sMesh(p_sMesh) {
        }
    public:
        virtual std::map<std::string, TypeScalar> operator()() = 0;
};

}

#endif
