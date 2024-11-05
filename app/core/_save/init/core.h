#ifndef C0P_CORE_INIT_CORE_H
#define C0P_CORE_INIT_CORE_H
#pragma once

// std includes
#include <iostream> // cout, endl
// app include
#include "core/init/prop.h"
#include "core/init/solutions/core.h"
// lib include
#include "l0ad/ascii/double.h"
#include "s0ve/double.h"

namespace c0p {

template<typename tParameters>
class Init {
    public:
        Init() {
        }
    public:
        static void set(Env<EnvParameters>& env) {
            std::cout << "INFO : Init case start" << std::endl;
            InitSolutions<InitSolutionsParameters>::set(env.solutions);
            std::cout << "INFO : Init case end" << std::endl;
        }
};

}

#endif
