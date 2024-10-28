#ifndef C0P_CORE_ENV_FLOW_INTERPOLATED_STATIONARY_CORE_H
#define C0P_CORE_ENV_FLOW_INTERPOLATED_STATIONARY_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "v0l/bin/file_data.h"
#include "m0sh/uniform.h"
#include "m0sh/structured_sub.h"
#include "fl0p/stationary.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/interpolated/stationary/prop.h"

namespace c0p {

using TypeFlowInterpolatedMesh = m0sh::Uniform<TypeVector, TypeRef, TypeContainer>;
using TypeFlowInterpolatedMeshSub = m0sh::StructuredSub<TypeVector, TypeRef, TypeContainer>;
using TypeFlowInterpolated = fl0w::fl0p::Stationary<TypeVector, TypeMatrix, TypeRef, TypeFlowInterpolatedMesh, TypeContainer, TypeFlowInterpolatedMeshSub, v0l::FileData>;

template<typename TypeParameters>
class BaseFlowInterpolatedStationary {
    public:
        using Type = TypeFlowInterpolated;
        std::shared_ptr<Type> sData;

        TypeParameters parameters;
        
        BaseFlowInterpolatedStationary() {
            // load scalars
            v0l::FileData<float> ux(parameters.fileName, 0);
            v0l::FileData<float> uy(parameters.fileName, 1);
            v0l::FileData<float> uz(parameters.fileName, 2);
            v0l::FileData<float> duxdx(parameters.fileName, 3);
            v0l::FileData<float> duxdy(parameters.fileName, 4);
            v0l::FileData<float> duxdz(parameters.fileName, 5);
            v0l::FileData<float> duydx(parameters.fileName, 6);
            v0l::FileData<float> duydy(parameters.fileName, 7);
            v0l::FileData<float> duydz(parameters.fileName, 8);
            v0l::FileData<float> duzdx(parameters.fileName, 9);
            v0l::FileData<float> duzdy(parameters.fileName, 10);
            v0l::FileData<float> duzdz(parameters.fileName, 11);
            // mesh
            TypeSpaceVector origin;
            std::vector<double> lengths(3);
            for(std::size_t i = 0; i < 3; i++) {
                lengths[i] = vx.meta.dimensions[i] * vx.meta.spacing[i];
                origin[i] = vx.meta.origin[i];
            }
            // Allocate data
            sData = std::make_shared<Type>(std::make_shared<TypeFlowInterpolatedMesh>(vx.meta.dimensions, lengths, origin, std::vector<bool>(3, true)), std::vector<v0l::FileData>({vx, vy, vz}), std::vector<v0l::FileData>({duxdx, duydx, duzdx, duxdy, duydy, duzdy, duxdz, duydz, duzdz}), parameters.order);
        }
        
        void init(const TypeScalar& t) {
        }
        
        void update(const TypeScalar& t) {
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "INTERPOLATED STATIONARY FLOW" << std::endl;
            std::cout << "file name" << space << parameters.fileName << std::endl;
            std::cout << "interpolation order" << space << parameters.order << std::endl;
        }

};

}

#endif
