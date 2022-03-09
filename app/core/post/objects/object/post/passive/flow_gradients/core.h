
#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_PASSIVE_FLOW_GRADIENTS_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_PASSIVE_FLOW_GRADIENTS_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/passive/flow_gradients/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostPassiveFlowGradients : public PostPostPost<TypeObjectStep> {
	public:
		Parameters parameters;
	public:
		using PostPostPost<TypeObjectStep>::sObjectStep;
	public:
		using PostPostPost<TypeObjectStep>::PostPostPost;
	public:
		std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
			return {
				{ parameters.name + "_" + std::to_string(parameters.i) + "_" + std::to_string(parameters.j), sObjectStep->sFlow->getJacobian(sObjectStep->cX(pState), t)(parameters.i, parameters.j) }
			};
			std::map<std::string, TypeScalar> result;
		   	const TypeSpaceMatrix gradients = sObjectStep->sFlow->getJacobian(sObjectStep->cX(pState), t);
		   	for(unsigned int i = 0; i < gradients.rows(); i++) {
		   		for(unsigned int j = 0; j < gradients.cols(); j++) {
		   			result[parameters.name + "_" + std::to_string(i) + "_" + std::to_string(j)] = gradients(i, j);
		   		}
		   	}
		   	return result;
		};
};

}

#endif
