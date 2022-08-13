#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_AGENT_SENSOR_VELOCITY_GRADIENTS_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_AGENT_SENSOR_VELOCITY_GRADIENTS_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <vector>
//#include <execution>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/agent/sensor_velocity_gradients/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class PostPostAgentSensorVelocityGradients : public PostPostPost<TypeObjectStep> {
	public:
		TypeParameters parameters;
	public:
		using PostPostPost<TypeObjectStep>::sObjectStep;
	public:
		using PostPostPost<TypeObjectStep>::PostPostPost;
		PostPostAgentSensorVelocityGradients(std::shared_ptr<TypeObjectStep> p_sObjectStep) : PostPostPost<TypeObjectStep>(p_sObjectStep) {
		}
	public:
		std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
			std::map<std::string, TypeScalar> result;
   		   	const TypeSpaceMatrix gradients = sObjectStep->sBehaviour->sensorVelocityGradients(pState, t, *sObjectStep);
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
