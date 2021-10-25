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
        TypeEnv env;
        TypeInit inits;
    public:
        std::size_t startIndex;
    public:
        Run() : parameters(), env(), inits(env) {
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
                    startIndex = std::round(time.back() / parameters.dt);
                    if (startIndex < parameters.nt) {
                        load(time.back());
                    } else {
                        std::cout << "INFO : Computation already finished. Nothing to do." << std::endl;
                    }
                } else {
                    // Init
                    startIndex = 0;
                    inits(env);
                }
            } else {
                // Init
                startIndex = 0;
                inits(env);
                // Create time directory
                std::filesystem::create_directory("time");
            }
        }

        void update(const TypeScalar& t) {
            env.sFlow->update(t);
            env.objects.update(parameters.dt);
        }
        
        void save(const TypeScalar& t) {
            // Create directory
            std::string folder = "time/" + std::to_string(t);
            std::filesystem::create_directory(folder);
            // Save
            s0ve::saveArrayDouble(folder + "/objects.txt", env.objects.state, "\n");
        }
        
        void load(const TypeScalar& t) {
            // Get directory
            std::string folder = "time/" + std::to_string(t);
            // Load
            l0ad::ascii::loadArrayDouble(folder + "/objects.txt", env.objects.state, '\n');
            env.objects.t = t;
            env.sFlow->init(t);
        }
};

}

#endif
