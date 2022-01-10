#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_GROUP_ALL_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_GROUP_ALL_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <vector>
//#include <execution>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/group/all/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class PostPostGroupAll : public PostPostPost<TypeObjectStep> {
    public:
        TypeParameters parameters;
        typename TypeParameters::template TypePostPostMember<typename TypeObjectStep::TypeMemberStep> postMember;
    public:
        using PostPostPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostPost<TypeObjectStep>::PostPostPost;
        PostPostGroupAll(std::shared_ptr<TypeObjectStep> p_sObjectStep) : PostPostPost<TypeObjectStep>(p_sObjectStep), postMember(sObjectStep->sMemberStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedMembers(sObjectStep->size());
            std::for_each(/*std::execution::par_unseq, */sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, pState, t, &processedMembers](const unsigned int& memberIndex){ 
                for(const auto& p : postMember(sObjectStep->cMemberState(pState, memberIndex), t)) {
                    processedMembers[memberIndex]["particle_" + std::to_string(memberIndex) + "__" + p.first] = p.second;
                }
            });
            // return
            std::map<std::string, TypeScalar> processed;
            for(auto& processedMember : processedMembers) {
                processed.merge(processedMember);
            }
            return processed;
        };
};

}

#endif
