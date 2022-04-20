#ifndef C0P_CORE_POST_FLOW_POST_VELOCITY_CORE_H
#define C0P_CORE_POST_FLOW_POST_VELOCITY_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/flow/post/core.h"
#include "core/post/flow/post/velocity/prop.h"

namespace c0p {

template<typename TypeParameters>
class PostFlowVelocity : public PostFlowPost {
	public:
		TypeParameters parameters;
	public:
		using PostFlowPost::sFlow;
		using PostFlowPost::sMesh;
	public:
		using PostFlowPost::PostFlowPost;
	public:
		std::map<std::string, TypeScalar> operator()(const double& t) override {
			std::map<std::string, TypeScalar> result;
			for(const auto& index : sMesh->indexCells()) {
			 	const TypeSpaceVector u = sFlow->getVelocity(sMesh->positionCell(index), t);
			 	for(unsigned int i = 0; i < u.size(); i++) {
			 		result["flow__index_" + std::to_string(index) + "__" + parameters.name + "_" + std::to_string(i)] = u[i];
			 	}
			}
		 	return result;
		};
};

}

#endif
