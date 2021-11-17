#ifndef C0P_CORE_POST_MESH_UNIFORM_CORE_H
#define C0P_CORE_POST_MESH_UNIFORM_CORE_H
#pragma once

// std includes
#include <memory> //shared_ptr, make_shared
// app includes
#include "core/post/mesh/uniform/prop.h"
// modules includes
#include "m0sh/uniform.h"

namespace c0p {

template<typename TypeParameters>
class PostMeshMeshUniform {
    public:
        using Type = m0sh::Uniform<TypeSpaceVector, TypeRef, TypeContainer>;
    public:
        TypeParameters parameters;
        std::shared_ptr<Type> sData;
    public:
        PostMeshMeshUniform() : parameters(), sData(std::make_shared<Type>(parameters.n, parameters.length, parameters.origin, TypeContainer<bool>(DIM, true))) {
        }
};

}

#endif
