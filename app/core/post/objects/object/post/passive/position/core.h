#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_PASSIVE_POSITION_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_PASSIVE_POSITION_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/passive/position/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class PostPostPassivePosition : public PostPostPost<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
    public:
        std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
        	std::map<std::string, TypeScalar> result;
        	const TypeSpaceVector x = sObjectStep->cX(pState);
        	for(unsigned int i = 0; i < x.size(); i++) {
        		result[parameters.name + "_" + std::to_string(i)] = x[i];
        	}
        	return result;
        };
};

}

#endif
