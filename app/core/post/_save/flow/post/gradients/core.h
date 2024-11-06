#ifndef C0P_CORE_POST_FLOW_POST_GRADIENTS_CORE_H
#define C0P_CORE_POST_FLOW_POST_GRADIENTS_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/flow/post/core.h"
#include "core/post/flow/post/gradients/prop.h"

namespace c0p {

template<typename TypeParameters>
class PostFlowGradients : public PostFlowPost {
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
	   		   	const TypeSpaceMatrix gradients = sFlow->getVelocityGradients(sMesh->positionCell(index), t);
	   		   	for(unsigned int i = 0; i < gradients.rows(); i++) {
	   		   		for(unsigned int j = 0; j < gradients.cols(); j++) {
	   		   			result["flow__index_" + std::to_string(index) + "__" + parameters.name + "_" + std::to_string(i) + "_" + std::to_string(j)] = gradients(i, j);
	   		   		}
	   		   	}
	   		}
   		   	return result;
		};
};

}

#endif
