#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_CHAIN_VALUE_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_CHAIN_VALUE_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <algorithm> // replace
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/chain/value/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class PostPostChainValue : public PostPostPost<TypeObjectStep> {
	public:
		TypeParameters parameters;
		typename TypeParameters::template TypePostPostMember<typename TypeObjectStep::TypeMemberStep> postMember;
	public:
		using PostPostPost<TypeObjectStep>::sObjectStep;
	public:
		PostPostChainValue(std::shared_ptr<TypeObjectStep> p_sObjectStep) : PostPostPost<TypeObjectStep>(p_sObjectStep), postMember(sObjectStep->sMemberStep)  {
			
		};
	public:
		std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
			std::map<std::string, TypeScalar> processed;
			const double length = sObjectStep->length(pState);
			const unsigned int n = std::ceil(length / parameters.dl);
			for(unsigned int i = 0; i < n + 1; i++) {
				const double l = i * parameters.dl;
				std::string lStr = std::to_string(l);
				std::replace(lStr.begin(), lStr.end(), '.', 'o');
				const double s = l/length;
				const auto state = sObjectStep->cState(pState, s);
				for(const auto& p : postMember(state.data(), t)) {
					processed["l_" + lStr + "__" + p.first] = p.second;
				}
			}
			return processed;
		};
};

}

#endif
