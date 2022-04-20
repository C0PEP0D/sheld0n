#ifndef C0P_PARAM_POST_PARAPETERS_H
#define C0P_PARAM_POST_PARAMETERS_H
#pragma once

// app include
#include "core/post/prop.h"

namespace c0p {

// Post processing parameters
struct PostParameters {
	// Number of time steps that are to be post processed.
	// 0 means all saved time steps are to be post processed.
	int nb = 0;
	// Index of the first time step that are to be post processed.
	int begin = 0;
	// Iteration step. 0 means this step computed automaticaly
	// based on nb.
	int step = 0;
	// Specify what to post process.
	bool isPostProcessingObjects = true;
	bool isPostProcessingMesh = true;
	bool isPostProcessingFlow = true;
	// isPreparingFlow: true or false. Specify if the flow needs to be prepared or not. 
	// If the post processing does not require the flow, isPreparingFlow should be set to false for performance improvements.
	bool isPreparingFlow = true;
	// Specify if all static objects are merge in one unique file.
	bool savedStaticMerge = false;
};

}

#endif
