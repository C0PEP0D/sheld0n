#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_MANAGER_ALL_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_MANAGER_ALL_CORE_H
#pragma once

// std includes
#include <string> // to_string
#include <map>
#include <vector>
//#include <execution>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/post/manager/all/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class PostPostManagerAll : public PostPostManagerPost<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using PostPostManagerPost<TypeObjectStep>::sObjectStep;
    public:
        using PostPostManagerPost<TypeObjectStep>::PostPostManagerPost;
        PostPostManagerAll(std::shared_ptr<TypeObjectStep> p_sObjectStep) : PostPostManagerPost<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const std::vector<std::vector<double>>& states, const double& t) override {
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedManaged(sObjectStep->number());
            std::for_each(/*std::execution::par_unseq, */sObjectStep->managedIndexs.cbegin(), sObjectStep->managedIndexs.cend(), [this, states, t, &processedManaged](const unsigned int& managedIndex){
            	typename TypeParameters::template TypePostPostManaged<typename TypeObjectStep::TypeManagedStep> postManaged(sObjectStep->sManagedSteps[managedIndex]);
                for(const auto& p : postManaged(states[managedIndex].data(), t)) {
                    processedManaged[managedIndex]["managed_" + std::to_string(managedIndex) + "__" + p.first] = p.second;
                }
            });
            // return
            std::map<std::string, TypeScalar> processed;
            for(auto& tmp : processedManaged) {
                processed.merge(tmp);
            }
            return processed;
        };
};

}

#endif
