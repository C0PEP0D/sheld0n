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
	static const unsigned int Number = 0;
	// Index of the first time step that are to be post processed.
	static const unsigned int IndexStart = 0;
	// Iteration step. 0 means this step computed automaticaly
	// based on nb.
	static const unsigned int IndexStep = 1;
	// Specify what to post process.
	static const bool IsPostProcessingCustom = true;
	static std::map<std::string, tScalar> custom(const Env<EnvParameters>& env) {
		std::map<std::string, tScalar> output;
		// // _GroupOfPoints
		// const tScalar* pGroupOfPointsState = Solutions<SolutionsParameters>::tSolutionStatic::tEquation::tVariable::cState<0>(env.solutions.solutionsStatic.state.data());
		// // // position
		// for(unsigned int index = 0; index < _GroupOfPoints::tVariable::GroupSize; index++) {
		// 	output["group_of_points__particle_" + std::to_string(index) + "__pos_0"] = _GroupOfPoints::tVariable::tVariableMember::cPosition(_GroupOfPoints::tVariable::cState(pGroupOfPointsState, index))[0];
		// 	output["group_of_points__particle_" + std::to_string(index) + "__pos_1"] = _GroupOfPoints::tVariable::tVariableMember::cPosition(_GroupOfPoints::tVariable::cState(pGroupOfPointsState, index))[1];
		// };
		// // _SourceOfPoints
		// // // position
		// for(unsigned int index = 0; index < _SourceOfPoints::tVariable::groupSize(SolutionsParameters::solutionSourceOfPoints.state.size()); index++) {
		// 	output["source_of_points__particle_" + std::to_string(index) + "__pos_0"] = _SourceOfPoints::tVariable::tVariableMember::cPosition(_SourceOfPoints::tVariable::cState(SolutionsParameters::solutionSourceOfPoints.state.data(), index))[0];
		// 	output["source_of_points__particle_" + std::to_string(index) + "__pos_1"] = _SourceOfPoints::tVariable::tVariableMember::cPosition(_SourceOfPoints::tVariable::cState(SolutionsParameters::solutionSourceOfPoints.state.data(), index))[1];
		// 	output["source_of_points__particle_" + std::to_string(index) + "__lifetime"] = *_SourceOfPoints::tVariable::tVariableMember::cLifetime(_SourceOfPoints::tVariable::cState(SolutionsParameters::solutionSourceOfPoints.state.data(), index));
		// };
		// // _ReactiveFront
		// // // position
		// for(unsigned int curveIndex = 0; curveIndex < SolutionsParameters::solutionReactiveFront.states.size(); curveIndex++) {
		// 	for(double s = 0; s <= 1.0; s+=(1.0/4.0) * (1.0/_ReactiveFront::tParameters::tVariable::tCurve::cLength(SolutionsParameters::solutionReactiveFront.states[curveIndex].data(), SolutionsParameters::solutionReactiveFront.states[curveIndex].size()))) {
		// 		std::string sStr = std::to_string(s);
		// 		sStr.replace(sStr.find("."), sizeof(".") - 1, "o");
		// 		output["reactive_front__curve_index_"+ std::to_string(curveIndex) +"__s_" + sStr + "__pos_0"] = _ReactiveFront::tParameters::tVariable::tCurve::cPositionInterpolated(SolutionsParameters::solutionReactiveFront.states[curveIndex].data(), SolutionsParameters::solutionReactiveFront.states[curveIndex].size(), s)[0];
		// 		output["reactive_front__curve_index_"+ std::to_string(curveIndex) +"__s_" + sStr + "__pos_1"] = _ReactiveFront::tParameters::tVariable::tCurve::cPositionInterpolated(SolutionsParameters::solutionReactiveFront.states[curveIndex].data(), SolutionsParameters::solutionReactiveFront.states[curveIndex].size(), s)[1];
		// 	}
		// };
		// output
		return output;
	}
	// Specify if all static objects are merge in one unique file.
	static const bool IsStaticMerged = false;
};

}

#endif
