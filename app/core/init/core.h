#ifndef C0P_CORE_INIT_CORE_H
#define C0P_CORE_INIT_CORE_H
#pragma once

// std includes
#include <iostream> // cout, endl
#include <algorithm> // sort
#include <cmath> // round
#include <vector>
#include <string> // stod, to_string
#include <filesystem>
// app include
#include "core/init/prop.h"
#include "core/init/objects/core.h"
// lib include
#include "l0ad/ascii/double.h"
#include "s0ve/double.h"

namespace c0p {

template<typename TypeParameters, typename TypeParametersObjects, typename TypeEnv>
class Init {
    public:
        // input
        TypeParameters parameters;
        InitObjects<TypeParametersObjects> initObjects;
    public:
        Init(std::shared_ptr<TypeEnv> sEnv) : initObjects(sEnv->sObjects, sEnv->sObjectsParameters) {
        }
    public:
        void operator()(std::shared_ptr<TypeEnv> sEnv) {
            std::cout << "INFO : Init case start" << std::endl;
            initObjects(sEnv->sObjects->stateStatic, sEnv->sObjects->statesDynamic, sEnv->sObjects->statesManager);
            sEnv->sFlow->init(0.0);
            std::cout << "INFO : Init case end" << std::endl;
        }
};

}

#endif
