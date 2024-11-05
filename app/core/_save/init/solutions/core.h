#ifndef C0P_CORE_INIT_SOLUTIONS_CORE_H
#define C0P_CORE_INIT_SOLUTIONS_CORE_H
#pragma once

// app includes
#include "core/init/solutions/prop.h"

namespace c0p {

template<typename tParameters>
class InitSolutions {
	public:
		InitSolutions() {
		}
	public:
		static void set(Solutions<SolutionsParameters>& solutions) {
			tParameters::tInitStatic::set(solutions.solutionsStatic);
			tParameters::setGroups();
		}
};

}

#endif
