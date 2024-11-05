#ifndef C0P_CORE_ENV_CORE_H
#define C0P_CORE_ENV_CORE_H
#pragma once

// std includs
#include <iostream>
// app includes
#include "core/prop.h"
#include "param/flow/choice.h"
#include "core/solutions/core.h"
#include "param/solutions/parameters.h"

namespace c0p {

template<typename tParameters>
class Env {
	public:
		Solutions<SolutionsParameters> solutions;
	public:
		Env() {
		}

		void init() {
			std::cout << "INFO : Init case start" << std::endl;
			solutions.init();
			std::cout << "INFO : Init case end" << std::endl;
		}
};

}

#endif
