#ifndef C0P_CORE_POST_CORE_H
#define C0P_CORE_POST_CORE_H
#pragma once

// std includes
#include <iostream> // cout, endl
#include <algorithm> // sort
#include <cmath> // round
#include <vector>
#include <string> // stod, to_string
#include <filesystem>
// app include
#include "core/post/prop.h"
#include "core/post/objects/core.h"
#include "core/post/mesh/core.h"
#include "core/post/flow/core.h"
// lib include
#include "l0ad/ascii/double.h"
#include "s0ve/double.h"

namespace c0p {

template<typename TypeParameters, typename TypeParametersObjects, typename TypeParametersMesh, typename TypeParametersFlow, typename TypeEnv>
class Post {
	public:
		// base
		TypeEnv env;
		std::vector<double> time;
	public:
		// input
		TypeParameters parameters;
		// // post objects
		PostObjects<TypeParametersObjects> postObjects;
		// // post mesh
		PostMeshMesh mesh;
		PostMesh<TypeParametersMesh> postMesh;
		// // post flow
		PostFlow<TypeParametersFlow> postFlow;
	public:
		Post() : env(), postObjects(env.sObjects, env.sObjectsParameters), postMesh(mesh.sData), postFlow(env.sFlow, mesh.sData) {
			std::cout << "INFO : Running post-processing" << std::endl;
			// Init time and processed
			init();
			// PostProcess case
			for(const auto& t : time) {
				std::string folder = "post_process/time/" + std::to_string(t);
				if(not std::filesystem::exists(folder)) {
					std::filesystem::create_directory(folder);
					// // load
					load(env, t);
					// // objects
					if(parameters.isPostProcessingObjects) {
						const auto processed = postObjects(env.sObjects->stateStatic.data(), env.sObjects->statesDynamic, env.sObjects->statesManager, t);
						for(unsigned int objectIndex = 0; objectIndex < processed.size(); objectIndex++) {
							if(objectIndex < env.sObjectsParameters->objectsStaticNames.size()) {
								s0ve::saveMapToCsvDouble(folder + "/" + env.sObjectsParameters->objectsStaticNames[objectIndex] + ".csv", processed[objectIndex], ",", "#");
							} else if(objectIndex < env.sObjectsParameters->objectsStaticNames.size() + env.sObjectsParameters->objectsDynamicNames.size()) {
								s0ve::saveMapToCsvDouble(folder + "/" + env.sObjectsParameters->objectsDynamicNames[objectIndex - env.sObjectsParameters->objectsStaticNames.size()] + ".csv", processed[objectIndex], ",", "#");
							} else {
								s0ve::saveMapToCsvDouble(folder + "/" + env.sObjectsParameters->objectsManagerNames[objectIndex - env.sObjectsParameters->objectsStaticNames.size() - env.sObjectsParameters->objectsDynamicNames.size()] + ".csv", processed[objectIndex], ",", "#");
							}
						}
					}
					// // flow
					if(parameters.isPostProcessingFlow) {
						s0ve::saveMapToCsvDouble(folder + "/flow.csv", postFlow(t), ",", "#");
					}
					// // msg
					std::cout << "INFO : Processed " << t << "/" << time.back() << std::endl;
				}
				// // mesh
				if(parameters.isPostProcessingMesh) {
					s0ve::saveMapToCsvDouble("post_process/mesh.csv", postMesh(), ",", "#");
				}
			}
			std::cout << "INFO : Post-processing end" << std::endl;
		}

		void init() {
			// create post_process directory
			if(not std::filesystem::exists("post_process")) {
				std::filesystem::create_directory("post_process");
				std::filesystem::create_directory("post_process/time");
			} else if(not std::filesystem::exists("post_process/time")) {
				std::filesystem::create_directory("post_process/time");
			}
			// load time
			if(std::filesystem::exists("time")) {
				for (const auto & entry : std::filesystem::directory_iterator("time")) {
					time.emplace_back(std::stod(entry.path().filename()));
				}
				if(time.size() > 0) {
					std::sort(time.begin(), time.end());
					// deal with parameters
					if(parameters.nb > 0 && parameters.nb < time.size() - parameters.begin) {
						if(parameters.step == 0) {
							parameters.step = (time.size() - parameters.begin)/(parameters.nb - 1);
						}
						for(int i = time.size() - 1; i > -1; i--) {
							if(not ((i >= parameters.begin) && (i < parameters.begin + parameters.nb * parameters.step) && ((i - parameters.begin) % parameters.step == 0))) {
								time.erase(time.begin() + i);
							}
						}
					}
				} else {
					std::cout << "INFO : No data. Nothing to do." << std::endl;
				}
			} else {
				std::cout << "INFO : No data. Nothing to do." << std::endl;
			}
		}

		void load(TypeEnv& env, const TypeScalar& t) {
			// Get directory
			std::string folder = "time/" + std::to_string(t);
   			// Load
   			// // Static
   			if (parameters.savedStaticMerge) {
   				if(not env.sObjects->stateStatic.empty()) {
   					l0ad::ascii::loadDouble(folder + "/static.txt", env.sObjects->stateStatic.data(), env.sObjects->stateStatic.size());
   				}
   			} else {
   				for(const unsigned int& staticIndex : env.sObjects->sStepStatic->memberIndexs) {
   					l0ad::ascii::loadDouble(folder + "/" + env.sObjectsParameters->objectsStaticNames[staticIndex] + ".txt", env.sObjects->sStepStatic->memberState(env.sObjects->stateStatic.data(), staticIndex), env.sObjects->sStepStatic->memberStateSizes[staticIndex]);
   				}
   			}
			// // Dynamic
   			for(const unsigned int& dynamicIndex : env.sObjects->dynamicIndexs) {
   				l0ad::ascii::loadVectorDouble(folder + "/" + env.sObjectsParameters->objectsDynamicNames[dynamicIndex] + ".txt", env.sObjects->statesDynamic[dynamicIndex]);
   				env.sObjects->sStepsDynamic[dynamicIndex]->registerState(env.sObjects->statesDynamic[dynamicIndex]);
   			}
   			// // Manager
   			for(const unsigned int& managerIndex : env.sObjects->managerIndexs) {
				// load data into states
				unsigned int managedIndex = 0;
				for (const std::filesystem::directory_entry& dir_entry : std::filesystem::directory_iterator(folder + "/" + env.sObjectsParameters->objectsManagerNames[managerIndex])) {
					if(env.sObjects->statesManager[managerIndex].size() == managedIndex) {
						env.sObjects->statesManager[managerIndex].emplace_back();
					}
					l0ad::ascii::loadVectorDouble(dir_entry.path(), env.sObjects->statesManager[managerIndex][managedIndex]);
					managedIndex += 1;
				}
				// clear unecessary data
				env.sObjects->statesManager[managerIndex].resize(managedIndex);
				// register states
				env.sObjects->sStepsManager[managerIndex]->registerStates(env.sObjects->statesManager[managerIndex]);
   			}
			// Set time
			env.sObjects->t = t;
			env.sFlow->init(t);
			// The prepare flow
			if(parameters.isPreparingFlow) {
				if(parameters.isPostProcessingObjects) {
					env.sFlow->prepare(env.sObjects->sStepStatic->positions(env.sObjects->stateStatic.data()), t);
					// TODO: all positions
				}
				if(parameters.isPostProcessingFlow) {
					env.sFlow->prepare(mesh.sData->positionCells(), t);
				}
			}
		}
};

}

#endif
