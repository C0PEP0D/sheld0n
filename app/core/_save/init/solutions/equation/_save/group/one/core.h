#ifndef C0P_CORE_POST_POSTS_POST_OBJECT_GROUP_ONE_CORE_H
#define C0P_CORE_POST_POSTS_POST_OBJECT_GROUP_ONE_CORE_H
#include <type_traits>
#pragma once

// std includes
#include <vector>
#include <numeric>
// app includes
#include "core/post/posts/post/object/group/one/prop.h"

namespace c0p {

template<typename Parameters>
class PostObjectGroupOne {
    public:
        Parameters parameters;
        
        template<typename TypeState, typename TypeStep>
        std::map<std::string, TypeScalar> operator()(TypeRef<TypeState> state, const TypeScalar& t, const TypeStep& step) {
            // Init
            std::map<std::string, TypeScalar> processed;
            // Members process
            std::map<std::string, TypeScalar> member = parameters.memberPost.template operator()<typename TypeStep::TypeMemberState>(step.memberState(state, parameters.n), t, *step.sStepMember);
            for(const auto& p : member) {
                processed[parameters.name + "_" + std::to_string(parameters.n) + "_" + p.first] = p.second;
            }
            return processed;
        }
};

}

#endif
