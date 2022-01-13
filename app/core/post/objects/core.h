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
        std::shared_ptr<TypeObjects> sObjects;
        TypeParameters parameters;
    public:
        PostObjects(std::shared_ptr<TypeObjects> p_sObjects, std::shared_ptr<ObjectsParameters> sObjectsParameters) : parameters(sObjectsParameters), sObjects(p_sObjects) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const double* pStateStatic, const std::vector<std::vector<double>>& statesDynamic, const double& t) {
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedMembers(parameters.sPostsStatic.size() + parameters.sPostsDynamic.size());
            // static
            std::for_each(std::execution::par_unseq, sObjects->sStepStatic->memberIndexs.cbegin(), sObjects->sStepStatic->memberIndexs.cend(), [this, pStateStatic, t, &processedMembers](const unsigned int& memberIndex){ 
                processedMembers[memberIndex] = (*parameters.sPostsStatic[memberIndex])(sObjects->sStepStatic->cMemberState(pStateStatic, memberIndex), t);
            });
            // dynamic
            std::for_each(std::execution::par_unseq, sObjects->dynamicIndexs.cbegin(), sObjects->dynamicIndexs.cend(), [this, statesDynamic, t, &processedMembers](const unsigned int& dynamicIndex){ 
                processedMembers[sObjects->sStepStatic->size() + dynamicIndex] = (*parameters.sPostsDynamic[dynamicIndex])(statesDynamic[dynamicIndex].data(), t);
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
