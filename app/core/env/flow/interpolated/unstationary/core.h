#ifndef C0P_CORE_ENV_FLOW_INTERPOLATED_UNSTATIONARY_CORE_H
#define C0P_CORE_ENV_FLOW_INTERPOLATED_UNSTATIONARY_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
#include <filesystem>
// Lib includes
#include "v0l/bin/file_data.h"
#include "m0sh/regular.h"
#include "m0sh/structured_sub.h"
#include "fl0p/unstationary.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/interpolated/unstationary/prop.h"

namespace c0p {

using TypeFlowInterpolatedMesh = m0sh::Regular<TypeSpaceVector, TypeRef, TypeContainer>;
using TypeFlowInterpolatedMeshSub = m0sh::StructuredSub<TypeSpaceVector, TypeRef, TypeContainer>;
using TypeFlowInterpolatedMeshTime = m0sh::Regular<TypeVector<1>, TypeRef, TypeContainer>;
using TypeFlowInterpolatedMeshTimeSub = m0sh::StructuredSub<TypeVector<1>, TypeRef, TypeContainer>;
using TypeFlowInterpolated = fl0w::fl0p::Unstationary<TypeSpaceVector, TypeSpaceMatrix, TypeRef, TypeFlowInterpolatedMesh, TypeContainer, TypeFlowInterpolatedMeshSub, TypeFlowInterpolatedMeshTime, TypeFlowInterpolatedMeshTimeSub, TypeVector<1>, v0l::FileData>;

template<typename TypeParameters>
class FlowInterpolatedUnstationary : public TypeFlowInterpolated {
    public:
        using Type = TypeFlowInterpolated;
    public:
        TypeParameters parameters;
        std::vector<std::string> files;
    public:
        FlowInterpolatedUnstationary() : Type() {
            // Files
            for (const auto & file : std::filesystem::directory_iterator(parameters.directory)) {
                files.push_back(file.path());
            }
            std::sort(files.begin(), files.end());
            // Load
            load(0.0);
        }

        void init(const TypeScalar& t) {
            if(t != Type::sTimeMesh->origin[0]) {
                load(t);
            }
        }

        void update(const TypeScalar& t) {
            if(t != Type::sTimeMesh->origin[0]) {
                load(t);
            }
        }

        void prepare(const TypeContainer<TypeSpaceVector>& positions, const TypeScalar& t) {
            // compute indexs
            std::vector<std::size_t> indexs;
            for(const TypeSpaceVector& x : positions) {
                // Compute offset
                std::vector<int> offset = Type::data[0].sMesh->ijk(x);
                for(auto& o : offset) {
                    o -= (Type::data[0].order + 1)/2;
                }
                //// If not periodic then be sure you are inside
                //if(not periodic) {
                //    for(std::size_t i = 0; i < offset.size(); i++) {
                //        if(offset[i] < 0) {
                //            offset[i] = 0;
                //        }
                //        else if(offset[i] > Type::data[0].sMesh->n[i] - n) {
                //            offset[i] = Type::data[0].sMesh->n[i] - n;
                //        }
                //    }
                //}
                // Build subMesh and compute
                std::vector<std::size_t> xIndexs = TypeFlowInterpolatedMeshSub(std::vector<std::size_t>(x.size(), Type::data[0].order + 1), offset, Type::data[0].sMesh).indexs();
                indexs.insert(indexs.end(), xIndexs.begin(), xIndexs.end());
            }
            for(auto& frame : Type::data) {
                // velocity
                frame.velocity[0].load(indexs);
                frame.velocity[1].load(indexs);
                frame.velocity[2].load(indexs);
                // jacobian
                frame.jacobian[0].load(indexs);
                frame.jacobian[1].load(indexs);
                frame.jacobian[2].load(indexs);
                frame.jacobian[3].load(indexs);
                frame.jacobian[4].load(indexs);
                frame.jacobian[5].load(indexs);
                frame.jacobian[6].load(indexs);
                frame.jacobian[7].load(indexs);
                frame.jacobian[8].load(indexs);
            }
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "INTERPOLATED UNSTATIONARY FLOW" << std::endl;
            std::cout << "directory name" << space << parameters.directory << std::endl;
            std::cout << "time step" << space << parameters.dt << std::endl;
            std::cout << "interpolation space order" << space << parameters.spaceOrder << std::endl;
            std::cout << "interpolation time order" << space << parameters.timeOrder << std::endl;
        }
        
        void load(const TypeScalar& t) {
            std::size_t indexT = std::round(t / parameters.dt);
            if(indexT + parameters.timeOrder + 1 > files.size()) {
                indexT = files.size() - (parameters.timeOrder + 1);
            }
            // Velocity and Jacobian
            std::vector<std::vector<v0l::FileData<float>>> velocity;
            std::vector<std::vector<v0l::FileData<float>>> jacobian;
            for (std::size_t indexFile = indexT; indexFile < indexT + parameters.timeOrder + 1; indexFile++) {
                std::string fileName = files[indexFile];
                // velocity
                velocity.emplace_back();
                velocity.back().emplace_back(fileName, 0);
                velocity.back().emplace_back(fileName, 1);
                velocity.back().emplace_back(fileName, 2);
                // jacobian
                jacobian.emplace_back();
                jacobian.back().emplace_back(fileName, 3); // duxdx
                jacobian.back().emplace_back(fileName, 6); // duydx
                jacobian.back().emplace_back(fileName, 9); // duzdx
                jacobian.back().emplace_back(fileName, 4); // duxdy
                jacobian.back().emplace_back(fileName, 7); // duydy
                jacobian.back().emplace_back(fileName, 10); // duzdy
                jacobian.back().emplace_back(fileName, 5); // duxdz
                jacobian.back().emplace_back(fileName, 8); // duydz
                jacobian.back().emplace_back(fileName, 11); // duzdz
            }
            // mesh
            TypeSpaceVector origin;
            std::vector<double> lengths(3);
            for(std::size_t i = 0; i < 3; i++) {
                lengths[i] = velocity[0][0].meta.dimensions[i] * velocity[0][0].meta.spacing[i];
                origin[i] = velocity[0][0].meta.origin[i];
            }
            // build data
            Type::build(std::make_shared<TypeFlowInterpolatedMesh>(velocity[0][0].meta.dimensions, lengths, origin), velocity, jacobian, parameters.spaceOrder, std::make_shared<TypeFlowInterpolatedMeshTime>(TypeContainer<std::size_t>(1, parameters.timeOrder + 1), TypeContainer<TypeScalar>(1, parameters.dt * (parameters.timeOrder + 1)), TypeVector<1>(t)), parameters.timeOrder);
        }
};

}

#endif
