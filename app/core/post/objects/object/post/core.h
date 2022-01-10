#ifndef C0P_CORE_POST_OBJECTS_OBJECT_POST_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_POST_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <map>
#include <string>
// app includes
#include "core/post/objects/object/post/prop.h"

namespace c0p {

template<typename TypeObjectStep>
class PostPostPost {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
    public:
        PostPostPost(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep) {
        }
    public:
        virtual std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) = 0;
};

}

#endif
