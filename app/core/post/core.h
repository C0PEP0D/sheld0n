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
// lib include
#include "l0ad/ascii/double.h"
#include "s0ve/double.h"

namespace c0p {

template<typename tParameters>
class Post {
	public:
		std::vector<std::string> time;
	public:
		Post() {
			std::cout << "INFO : Running post-processing" << std::endl;
			// Init time and processed
			init();
			// PostProcess case
			for(const auto& t : time) {
				std::string folder = "post_process/time/" + t;
				if(not std::filesystem::exists(folder)) {
					std::filesystem::create_directory(folder);
					// // load
					load(t);
					// // solutions
					Env::solutions.post(std::stod(t));
					// // msg
					std::cout << "INFO : Processed " << t << "/" << time.back() << std::endl;
				}
				// // // mesh
				// if(tParameters::IsPostProcessingMesh) {
					// s0ve::saveMapToCsvDouble("post_process/mesh.csv", postMesh(), ",", "#");
				// }
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
					time.emplace_back(entry.path().filename());
				}
				if(time.size() > 0) {
					std::sort(time.begin(), time.end());
					// deal with parameters
					unsigned int number = tParameters::Number;
					unsigned int indexStep = tParameters::IndexStep;
					if(number == 0) {
						if(indexStep == 0) {
							indexStep = 1;
						}
						number = (time.size() - tParameters::IndexStart)/indexStep + 1;
					}
					if(indexStep == 0) {
						indexStep = (time.size() - tParameters::IndexStart)/(number - 1);
					}
					for(int i = time.size() - 1; i > -1; i--) {
						if(not ((i >= tParameters::IndexStart) && (i < tParameters::IndexStart + number * indexStep) && ((i - tParameters::IndexStart) % indexStep == 0))) {
							time.erase(time.begin() + i);
						}
					}
				} else {
					std::cout << "INFO : No data. Nothing to do." << std::endl;
				}
			} else {
				std::cout << "INFO : No data. Nothing to do." << std::endl;
			}
		}

		void load(const std::string& t) {
			// Get directory
			std::string folder = "time/" + t;
   			// Load
   			// Static
   			if (tParameters::IsStaticMerged) {
   				if(not Env::solutions.solutionsStatic.state.empty()) {
   					l0ad::ascii::loadDouble(folder + "/static.txt", Env::solutions.solutionsStatic.state.data(), Env::solutions.solutionsStatic.state.size());
   				}
   			} else {
   				_loadStatic(Env::solutions.solutionsStatic, folder);
   			}
   			_loadStatic(Env::solutions.solutionsStatic, folder);
   			SolutionsParameters::loadDynamic(folder);
			SolutionsParameters::loadGroups(folder);
			// Set time
			Env::solutions.solutionsStatic.t = std::stod(t);
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
