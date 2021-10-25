#ifndef C0P_CORE_POST_MESH_REGULAR_CORE_H
#define C0P_CORE_POST_MESH_REGULAR_CORE_H
#pragma once

// std includes
#include <memory> //shared_ptr, make_shared
// app includes
#include "core/post/mesh/regular/prop.h"
// modules includes
#include "m0sh/regular.h"

namespace c0p {

template<typename TypeParameters>
class PostMeshMeshRegular {
    public:
        using Type = m0sh::Regular<TypeSpaceVector, TypeRef, TypeContainer>;
    public:
        TypeParameters parameters;
        std::shared_ptr<Type> sData;
    public:
        PostMeshMeshRegular() : parameters(), sData(std::make_shared<Type>(parameters.n, parameters.length, parameters.origin)) {
        }
};

}

#endif
