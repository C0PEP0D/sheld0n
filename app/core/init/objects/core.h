#ifndef C0P_CORE_INIT_OBJECTS_CORE_H
#define C0P_CORE_INIT_OBJECTS_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <string>
#include <map>
// app includes
#include "core/init/objects/prop.h"

namespace c0p {

template<typename TypeParameters>
class InitObjects {
    public:
        TypeParameters parameters;
        std::shared_ptr<TypeObjects> sObjects;
    public:
        InitObjects(std::shared_ptr<TypeObjects> p_sObjects, std::shared_ptr<TypeObjectsParameters> sObjectsParameters) : parameters(sObjectsParameters), sObjects(p_sObjects) {
        }
    public:
        void operator()(double* pStateStatic, std::vector<std::vector<double>>& statesDynamic) {
            // static
            for(const unsigned int& memberIndex : sObjects->sStepStatic->memberIndexs) {
                (*parameters.sInitsStatic[memberIndex])(sObjects->sStepStatic->memberState(pStateStatic, memberIndex));
            }
            // dynamic
            for(const unsigned int& dynamicIndex : sObjects->dynamicIndexs) {
                (*parameters.sInitsDynamic[dynamicIndex])(sObjects->statesDynamic[dynamicIndex]);
            }
        }
};

}

#endif
