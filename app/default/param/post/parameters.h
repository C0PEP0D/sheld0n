#ifndef C0P_PARAM_POST_PARAPETERS_H
#define C0P_PARAM_POST_PARAMETERS_H
#pragma once

// std include
#include <map>
#include <string>
// app include
#include "core/post/prop.h"

namespace c0p {

// Post processing parameters
struct PostParameters {
	// Number of time steps that are to be post processed.
	// 0 means all saved time steps are to be post processed.
	static const unsigned int Number = 32;
	// Index of the first time step that are to be post processed.
	static const unsigned int IndexStart = 0;
	// Iteration step. 0 means this step computed automatically
	// based on Number.
	static const unsigned int IndexStep = 0;
	
	// Specify if all static objects are merge in one unique file.
	static const bool IsStaticMerged = false;
};

}

#endif
