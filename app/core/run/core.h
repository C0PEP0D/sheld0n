#ifndef C0P_CORE_RUN_CORE_H
#define C0P_CORE_RUN_CORE_H
#pragma once

// std includes
#include <iostream> // cout, endl
#include <algorithm> // sort
#include <cmath> // round
#include <vector>
#include <string> // stod, to_string
#include <filesystem>
// lib includes
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"

namespace c0p {

template<typename TypeParameters, typename TypeEnv, typename TypeInit>
class Run {
	public:
		TypeParameters parameters;
		std::shared_ptr<TypeEnv> sEnv;
		std::shared_ptr<TypeInit> sInit;
	public:
		std::size_t startIndex;
	public:
		Run() : parameters() {
			sEnv = std::make_shared<TypeEnv>();
			sInit = std::make_shared<TypeInit>(sEnv);
			// Init saving system
			init();
			// Run case
			for(std::size_t index = startIndex; index < parameters.nt; index++) {
				const TypeScalar t = index * parameters.dt;
				// Update step
				update(t);
				// Save step attempt
				if(index % (parameters.nt / parameters.nsave) == 0) {
					std::cout << "INFO : Saving step " << index << "/" << parameters.nt << "." << std::endl;
					save(t);
				}
			}
			if (startIndex < parameters.nt) {
				std::cout << "INFO : Saving step " << parameters.nt << "/" << parameters.nt << "." << std::endl;
				save(parameters.nt * parameters.dt);
			}
		}

		void init() {
			if(std::filesystem::exists("time")) {
				std::vector<double> time;
				for (const auto & entry : std::filesystem::directory_iterator("time")) {
					time.emplace_back(std::stod(entry.path().filename()));
				}
				if(time.size() > 0) {
					std::sort(time.begin(), time.end());
					startIndex = std::round(time.back() / parameters.dt) + 1;
					if (startIndex < parameters.nt) {
						load(time.back());
					} else {
						std::cout << "INFO : Computation already finished. Nothing to do." << std::endl;
					}
				} else {
					// Init
					startIndex = 1;
					(*sInit)(sEnv);
					save(0.0);
				}
			} else {
				// Init
				startIndex = 1;
				(*sInit)(sEnv);
				// Create time directory
				std::filesystem::create_directory("time");
				save(0.0);
			}
		}

		void update(const TypeScalar& t) {
			sEnv->sFlow->update(t);
			sEnv->sObjects->update(parameters.dt);
		}
		
		void save(const TypeScalar& t) {
			// Create directory
			std::string folder = "time/" + std::to_string(t);
			std::filesystem::create_directory(folder);
			// Save
			// // Static
			if (parameters.saveStaticMerge) {
				if(not sEnv->sObjects->stateStatic.empty()) {
					s0ve::saveDouble(folder + "/static.txt", sEnv->sObjects->stateStatic.data(), sEnv->sObjects->stateStatic.size());
				}
			} else {
				for(const unsigned int& staticIndex : sEnv->sObjects->sStepStatic->memberIndexs) {
					s0ve::saveDouble(folder + "/" + sEnv->sObjectsParameters->objectsStaticNames[staticIndex] + ".txt", sEnv->sObjects->sStepStatic->cMemberState(sEnv->sObjects->stateStatic.data(), staticIndex), sEnv->sObjects->sStepStatic->memberStateSizes[staticIndex]);
				}
			}
			// // Dynamic
			for(const unsigned int& dynamicIndex : sEnv->sObjects->dynamicIndexs) {
				s0ve::saveDouble(folder + "/" + sEnv->sObjectsParameters->objectsDynamicNames[dynamicIndex] + ".txt", sEnv->sObjects->statesDynamic[dynamicIndex].data(), sEnv->sObjects->statesDynamic[dynamicIndex].size());
			}
			// // Manager
			for(const unsigned int& managerIndex : sEnv->sObjects->managerIndexs) {
				
				std::filesystem::create_directory(folder + "/" + sEnv->sObjectsParameters->objectsManagerNames[managerIndex]);
				for(unsigned int managedIndex = 0; managedIndex < sEnv->sObjects->sStepsManager[managerIndex]->number(); managedIndex++) {
					s0ve::saveDouble(folder + "/" + sEnv->sObjectsParameters->objectsManagerNames[managerIndex] + "/" + std::to_string(managedIndex) + ".txt", sEnv->sObjects->statesManager[managerIndex][managedIndex].data(), sEnv->sObjects->statesManager[managerIndex][managedIndex].size());
				}
			}
		}
		
		void load(const TypeScalar& t) {
			// Get directory
			std::string folder = "time/" + std::to_string(t);
			// Load
			// // Static
			if (parameters.saveStaticMerge) {
				if(not sEnv->sObjects->stateStatic.empty()) {
					l0ad::ascii::loadDouble(folder + "/static.txt", sEnv->sObjects->stateStatic.data(), sEnv->sObjects->stateStatic.size());
				}
			} else {
				for(const unsigned int& staticIndex : sEnv->sObjects->sStepStatic->memberIndexs) {
					l0ad::ascii::loadDouble(folder + "/" + sEnv->sObjectsParameters->objectsStaticNames[staticIndex] + ".txt", sEnv->sObjects->sStepStatic->memberState(sEnv->sObjects->stateStatic.data(), staticIndex), sEnv->sObjects->sStepStatic->memberStateSizes[staticIndex]);
				}
			}
			// // Dynamic
			for(const unsigned int& dynamicIndex : sEnv->sObjects->dynamicIndexs) {
				l0ad::ascii::loadVectorDouble(folder + "/" + sEnv->sObjectsParameters->objectsDynamicNames[dynamicIndex] + ".txt", sEnv->sObjects->statesDynamic[dynamicIndex]);
				sEnv->sObjects->sStepsDynamic[dynamicIndex]->registerState(sEnv->sObjects->statesDynamic[dynamicIndex]);
			}
			// // Manager
			for(const unsigned int& managerIndex : sEnv->sObjects->managerIndexs) {
				unsigned int managedIndex = 0;
				for (const std::filesystem::directory_entry& dir_entry : std::filesystem::directory_iterator(folder + "/" + sEnv->sObjectsParameters->objectsManagerNames[managerIndex])) {
					if(sEnv->sObjects->statesManager[managerIndex].size() == managedIndex) {
						sEnv->sObjects->statesManager[managerIndex].emplace_back();
					}
					l0ad::ascii::loadVectorDouble(dir_entry.path(), sEnv->sObjects->statesManager[managerIndex][managedIndex]);
					sEnv->sObjects->sStepsManager[managerIndex]->registerStates(sEnv->sObjects->statesManager[managerIndex]);
					managedIndex += 1;
				}
			}
			// Set time
			sEnv->sObjects->t = t;
			sEnv->sFlow->init(t);
		}
};

}

#endif
