#ifndef C0P_CORE_ENV_CORE_H
#define C0P_CORE_ENV_CORE_H
#pragma once

// std includs
#include <iostream>
// app includes
#include "core/prop.h"
#include "param/flow/parameters.h"
#include "core/solutions/core.h"
#include "param/solutions/parameters.h"

namespace c0p {

	struct Env {

		using tSolutions = Solutions<SolutionsParameters>;
		inline static tSolutions solutions;

		static void init() {
			// init random
			rand0m::seed(EnvParameters::randomSeed);
			// init flow
			Flow::init();
			// init solutions
			std::cout << "INFO : Init case start" << std::endl;
			solutions.init();
			std::cout << "INFO : Init case end" << std::endl;
		}

	};

}

#endif
