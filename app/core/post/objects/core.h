#ifndef C0P_CORE_POST_OBJECTS_CORE_H
#define C0P_CORE_POST_OBJECTS_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <string>
#include <map>
//#include <execution>
// app includes
#include "core/post/objects/prop.h"

namespace c0p {

template<typename TypeParameters>
class PostObjects {
    public:
        std::shared_ptr<TypeObjects::Type::TypeStep> sObjectsStep;
        TypeParameters parameters;
    public:
        PostObjects(const TypeObjects& objects) : parameters(objects), sObjectsStep(objects.sStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const TypeVector<Eigen::Dynamic>& state, const double& t) {
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedMembers(parameters.data.size());
            std::for_each(/*std::execution::par_unseq, */sObjectsStep->memberIndexs.cbegin(), sObjectsStep->memberIndexs.cend(), [this, state, t, &processedMembers](const unsigned int& memberIndex){ 
                processedMembers[memberIndex] = (*parameters.data[memberIndex])(sObjectsStep->cMemberState(state, memberIndex), t);
            });
            // return
            std::map<std::string, TypeScalar> processed;
            for(auto& processedMember : processedMembers) {
                processed.merge(processedMember);
            }
            return processed;
        }
};

}

#endif
