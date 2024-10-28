#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_AGENT_BEHAVIOUR_NAVIGATOR_DIRECTION_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_AGENT_BEHAVIOUR_NAVIGATOR_DIRECTION_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/agent/behaviour/navigator/direction/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostAgentBehaviourNavigatorDirection : public PostPostPost<TypeObjectStep> {
	public:
		Parameters parameters;
	public:
		using PostPostPost<TypeObjectStep>::sObjectStep;
	public:
		using PostPostPost<TypeObjectStep>::PostPostPost;
	public:
		std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
			const TypeSpaceVector direction = sObjectStep->sBehaviour->sensorDirection(pState, t, *sObjectStep);
			const TypeSpaceMatrix velocityGradients = sObjectStep->sBehaviour->sensorVelocityGradients(pState, t, *sObjectStep);
			const TypeSpaceVector dir = sObjectStep->sBehaviour->behaviourDirection(pState, t, *sObjectStep, direction, velocityGradients).normalized();
			std::map<std::string, TypeScalar> result;
			for(unsigned int i = 0; i < dir.size(); i++) {
				result[parameters.name + "_" + std::to_string(i)] = dir[i];
			}
			return result;
		};
};

}

#endif
