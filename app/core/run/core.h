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
#include <iomanip> // setprecision
// app includes
#include "core/learn/neural_network/core.h"

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
				std::cout << "INFO : Saving and Post Processing last step " << tEnd << "/" << tEnd << "." << std::endl;
				saveAndPostProcess(tEnd);
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
		
		void saveAndPostProcess(const tScalar& t) {
			// directory
			std::ostringstream oss;
			oss << "time/" << std::fixed << std::setprecision(7) << std::setw(10) << std::setfill('0') << t;
			std::string folder = oss.str();
			std::filesystem::create_directory(folder);
			// save
			Env::solutions.save(folder);
			// post directory
			std::string postFolder = "post_process/" + folder;
			std::filesystem::create_directory(postFolder);
			// post
			Env::solutions.post(postFolder, t);
		}
		
		void load(const tScalar& t) {
			// directory
			std::ostringstream oss;
			oss << "time/" << std::fixed << std::setprecision(7) << std::setw(10) << std::setfill('0') << t;
			std::string folder = oss.str();
			// load
			Env::solutions.load(folder);
			// set time
			Env::solutions.t = t;
		}
};

}

#endif
