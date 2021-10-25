#ifndef C0P_CORE_POST_MESH_CORE_H
#define C0P_CORE_POST_MESH_CORE_H
#pragma once

// std include
#include <vector>
#include <memory> // shared_ptr
#include <map>
#include <string>
#include <numeric> // iota
//#include <execution>
// app includes
#include "core/post/mesh/prop.h"
#include "core/post/mesh/post/core.h"

namespace c0p {

template<typename TypeParameters>
class PostMesh {
    public:
        std::shared_ptr<PostMeshMesh::Type> sMesh;
        TypeParameters parameters;
    public:
        PostMesh(std::shared_ptr<PostMeshMesh::Type> p_sMesh) : sMesh(p_sMesh), parameters(sMesh) {
        }
    public:
        std::map<std::string, TypeScalar> operator()() {
            std::vector<unsigned int> dataIndexs(parameters.data.size());
            std::iota(dataIndexs.begin(), dataIndexs.end(), 0);
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedData(parameters.data.size());
            std::for_each(/*std::execution::par_unseq, */dataIndexs.begin(), dataIndexs.end(), [this, &processedData](const unsigned int& dataIndex){ 
                for(const auto& p : (*parameters.data[dataIndex])()) {
                    processedData[dataIndex][p.first] = p.second;
                }
            });
            // return
            std::map<std::string, TypeScalar> processed;
            for(auto& processedDat : processedData) {
                processed.merge(processedDat);
            }
            return processed;
        }
};

}

#endif
