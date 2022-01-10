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
                    startIndex = std::round(time.back() / parameters.dt);
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
            if(not sEnv->sObjects->stateStatic.empty()) {
                s0ve::saveArrayDouble(folder + "/static.txt", sEnv->sObjects->stateStatic, "\n");
            }
            for(const unsigned int& dynamicIndex : sEnv->sObjects->dynamicIndexs) {
                s0ve::saveArrayDouble(folder + "/dynamic_" + std::to_string(dynamicIndex) + ".txt", sEnv->sObjects->statesDynamic[dynamicIndex], "\n");
            }
        }
        
        void load(const TypeScalar& t) {
            // Get directory
            std::string folder = "time/" + std::to_string(t);
            // Load
            if(not sEnv->sObjects->stateStatic.empty()) {
                l0ad::ascii::loadArrayDouble(folder + "/static.txt", sEnv->sObjects->stateStatic, '\n');
            }
            for(const unsigned int& dynamicIndex : sEnv->sObjects->dynamicIndexs) {
                l0ad::ascii::loadArrayDouble(folder + "/dynamic_" + std::to_string(dynamicIndex) + ".txt", sEnv->sObjects->statesDynamic[dynamicIndex], '\n');
            }
            sEnv->sObjects->t = t;
            sEnv->sFlow->init(t);
        }
};

}

#endif
