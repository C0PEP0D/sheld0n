#ifndef C0P_CORE_POST_MESH_POST_POSITION_CORE_H
#define C0P_CORE_POST_MESH_POST_POSITION_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/mesh/post/core.h"
#include "core/post/mesh/post/position/prop.h"

namespace c0p {

template<typename TypeParameters>
class PostMeshPosition : public PostMeshPost {
	public:
		TypeParameters parameters;
	public:
		using PostMeshPost::sMesh;
	public:
		using PostMeshPost::PostMeshPost;
	public:
		std::map<std::string, TypeScalar> operator()() override {
			std::map<std::string, TypeScalar> result;
			for(const auto& index : sMesh->indexCells()) {
			   	const TypeSpaceVector x = sMesh->positionCell(index);
			   	for(unsigned int i = 0; i < x.size(); i++) {
			   		result["mesh__index_" + std::to_string(index) + "__" + parameters.name + "_" + std::to_string(i)] = x[i];
			   	}
			}
		   	return result;
		};
};

}

#endif
