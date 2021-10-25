#ifndef C0P_CORE_POST_FLOW_POST_CORE_H
#define C0P_CORE_POST_FLOW_POST_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <map>
#include <string>
// app includes
#include "core/post/flow/post/prop.h"

namespace c0p {

class PostFlowPost {
    public:
        std::shared_ptr<Flow> sFlow;
        std::shared_ptr<PostMeshMesh::Type> sMesh;
    public:
        PostFlowPost(std::shared_ptr<Flow> p_sFlow, std::shared_ptr<PostMeshMesh::Type> p_sMesh) : sFlow(p_sFlow), sMesh(p_sMesh) {
        }
    public:
        virtual std::map<std::string, TypeScalar> operator()(const double& t) = 0;
};

}

#endif
