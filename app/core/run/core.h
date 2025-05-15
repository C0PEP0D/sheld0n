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
#include <iomanip>
// app includes
#include "core/learn/neural_network/core.h"
// lib includes
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"

namespace c0p {

template<typename tParameters>
class Run {
	public:
		std::size_t startIndex;
	public:
		Run() {
			// init saving system
			init();
			// run case
			const tScalar tEnd = tParameters::NTime * tParameters::Dt;
			for(std::size_t index = startIndex; index < tParameters::NTime; index++) {
				// step
				Env::solutions.step(tParameters::Dt);
				// post process
				if(index % (tParameters::NTime / tParameters::NSave) == 0) {
					// save
					const tScalar t = index * tParameters::Dt;
					std::cout << "INFO : Saving and Post Processing step " << t << "/" << tEnd << "." << std::endl;
					saveAndPostProcess(t);
				}
			}
			if (startIndex < tParameters::NTime) {
				// save
				std::cout << "INFO : Saving last step " << tEnd << "/" << tEnd << "." << std::endl;
				saveAndPostProcess(tEnd);
				// post process
				std::cout << "INFO : Post Processing step " << tEnd << "/" << tEnd << std::endl;
				Env::solutions.post(tEnd);
			}
		}

		void init() {
			// post processing
			if(not std::filesystem::exists("post_process")) {
				std::filesystem::create_directory("post_process");
				std::filesystem::create_directory("post_process/time");
			} else if(not std::filesystem::exists("post_process/time")) {
				std::filesystem::create_directory("post_process/time");
			}
			// saved data
			if(std::filesystem::exists("time")) {
				std::vector<double> time;
				for (const auto & entry : std::filesystem::directory_iterator("time")) {
					time.emplace_back(std::stod(entry.path().filename()));
				}
				if(time.size() > 0) {
					std::sort(time.begin(), time.end());
					startIndex = std::round(time.back() / tParameters::Dt) + 1;
					if (startIndex < tParameters::NTime) {
						load(time.back());
					} else {
						std::cout << "INFO : Computation already finished. Nothing to do." << std::endl;
					}
				} else {
					// Init
					startIndex = 1;
					Env::init();
					saveAndPostProcess(0.0);
				}
			} else {
				// Init
				startIndex = 1;
				Env::init();
				// Create time directory
				std::filesystem::create_directory("time");
				saveAndPostProcess(0.0);
			}
			// neural network
			NeuralNetwork::init();
		}

		// void step(const tScalar& t) {
		// 	Env::solutions.step(tParameters::Dt);
		// }
		
		void saveAndPostProcess(const tScalar& t) {
			// directory
			std::ostringstream oss;
			oss << "time/" << std::fixed << std::setprecision(7) << std::setw(10) << std::setfill('0') << t;
			std::string folder = oss.str();
			std::filesystem::create_directory(folder);
			// save
			if (tParameters::IsMergingStatic) {
				if(not Env::solutions.solutionsStatic.state.empty()) {
					s0ve::saveDouble(folder + "/static.txt", Env::solutions.solutionsStatic.state.data(), Env::solutions.solutionsStatic.state.size());
				}
			} else {
				_saveStatic(Env::solutions.solutionsStatic, folder);
			}
			SolutionsParameters::saveDynamic(folder);
			SolutionsParameters::saveGroups(folder);
			// post directory
			std::string postFolder = "post_process/" + folder;
			std::filesystem::create_directory(postFolder);
			// post
			Env::solutions.post(t);
		}

		template<unsigned int Index = 0>
    	static void _saveStatic(const Solutions<SolutionsParameters>::tSolutionStatic& solutionsStatic, const std::string& folder) {
    		using tStaticEquation = typename Solutions<SolutionsParameters>::tSolutionStatic::tEquation;
    		using tStaticVariable = typename Solutions<SolutionsParameters>::tSolutionStatic::tEquation::tVariable;
    		if constexpr(Index < tStaticEquation::Number) {
        		s0ve::saveDouble(folder + "/" + tStaticEquation::template tEquationComponent<Index>::type::tParameters::name + ".txt", tStaticVariable::template cState<Index>(solutionsStatic.state.data()), tStaticVariable::template tVariableComponent<Index>::type::Size);
        		// recursion
        		_saveStatic<Index+1>(solutionsStatic, folder);
        	}
        }
		
		void load(const tScalar& t) {
			// Get directory
			std::ostringstream oss;
			oss << "time/" << std::fixed << std::setprecision(7) << std::setw(10) << std::setfill('0') << t;
			std::string folder = oss.str();
			// Load
			// // Static
			if (tParameters::IsMergingStatic) {
				if(not Env::solutions.solutionsStatic.state.empty()) {
					l0ad::ascii::loadDouble(folder + "/static.txt", Env::solutions.solutionsStatic.state.data(), Env::solutions.solutionsStatic.state.size());
				}
			} else {
				_loadStatic(Env::solutions.solutionsStatic, folder);
			}
			SolutionsParameters::loadDynamic(folder);
			SolutionsParameters::loadGroups(folder);
			// set time
			Env::solutions.solutionsStatic.t = t;
		}

		template<unsigned int Index = 0>
    	static void _loadStatic(Solutions<SolutionsParameters>::tSolutionStatic& solutionsStatic, const std::string& folder) {
    		using tStaticEquation = typename Solutions<SolutionsParameters>::tSolutionStatic::tEquation;
    		using tStaticVariable = typename Solutions<SolutionsParameters>::tSolutionStatic::tEquation::tVariable;
    		if constexpr(Index < tStaticEquation::Number) {
        		l0ad::ascii::loadDouble(folder + "/" + tStaticEquation::template tEquationComponent<Index>::type::tParameters::name + ".txt", tStaticVariable::template state<Index>(solutionsStatic.state.data()), tStaticVariable::template tVariableComponent<Index>::type::Size);
        		// recursion
        		_loadStatic<Index+1>(solutionsStatic, folder);
        	}
        }
};

}

#endif
