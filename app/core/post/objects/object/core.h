#ifndef C0P_CORE_POST_OBJECTS_OBJECT_CORE_H
#define C0P_CORE_POST_OBJECTS_OBJECT_CORE_H
#pragma once

// std include
#include <vector>
#include <memory> // shared_ptr
#include <map>
#include <string>
#include <numeric> // iota
//#include <execution>
// app includes
#include "core/post/objects/object/post/core.h"
#include "core/post/objects/object/prop.h"

namespace c0p {

class PostPostBase {
    public:
        PostPostBase() {
        }
    public:
        virtual std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) = 0;
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class PostPost : public PostPostBase {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
        TypeParameters<TypeObjectStep> parameters;
    public:
        PostPost(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const double* pState, const double& t) override {
            std::vector<unsigned int> dataIndexs(parameters.data.size());
            std::iota(dataIndexs.begin(), dataIndexs.end(), 0);
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedData(parameters.data.size());
            std::for_each(/*std::execution::par_unseq, */dataIndexs.begin(), dataIndexs.end(), [this, pState, t, &processedData](const unsigned int& dataIndex){ 
                for(const auto& p : (*parameters.data[dataIndex])(pState, t)) {
                    processedData[dataIndex][parameters.name + "__" + p.first] = p.second;
                }
            });
            // return
            std::map<std::string, TypeScalar> processed;
            for(auto& processedDat : processedData) {
                processed.merge(processedDat);
            }
            return processed;
        }
};

class PostPostManagerBase {
    public:
        PostPostManagerBase() {
        }
    public:
        virtual std::map<std::string, TypeScalar> operator()(const std::vector<std::vector<double>>& states, const double& t) = 0;
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class PostPostManager : public PostPostManagerBase {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
        TypeParameters<TypeObjectStep> parameters;
    public:
        PostPostManager(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
        }
    public:
        std::map<std::string, TypeScalar> operator()(const std::vector<std::vector<double>>& states, const double& t) override {
            std::vector<unsigned int> dataIndexs(parameters.data.size());
            std::iota(dataIndexs.begin(), dataIndexs.end(), 0);
            // compute
            std::vector<std::map<std::string, TypeScalar>> processedData(parameters.data.size());
            std::for_each(/*std::execution::par_unseq, */dataIndexs.begin(), dataIndexs.end(), [this, states, t, &processedData](const unsigned int& dataIndex){ 
                for(const auto& p : (*parameters.data[dataIndex])(states, t)) {
                    processedData[dataIndex][parameters.name + "__" + p.first] = p.second;
                }
            });
            // return
            std::map<std::string, TypeScalar> processed;
            for(auto& tmp : processedData) {
                processed.merge(tmp);
            }
            return processed;
        }
};

}

#endif
