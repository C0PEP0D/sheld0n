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
        // output
        std::map<std::string, std::map<std::string, std::vector<TypeScalar>>> processed;
    public:
        Post() : env(), postObjects(env.objects), postMesh(mesh.sData), postFlow(env.sFlow, mesh.sData) {
            std::cout << "INFO : Running post-processing" << std::endl;
            // Init time and processed
            init();
            // PostProcess case
            for(const auto& t : time) {
                load(env, t);
                // // objects
                if(parameters.isPostProcessingObjects) {
                    for(const auto& p : postObjects(env.objects.state, t)) {
                        processed["objects"][p.first].push_back(p.second);
                    }
                }
                // // flow
                if(parameters.isPostProcessingFlow) {
                    for(const auto& p : postFlow(t)) {
                        processed["flow"][p.first].push_back(p.second);
                    }
                }
                // // msg
                std::cout << "INFO : Processed " << t << "/" << time.back() << std::endl;
            }
            // // save
            std::cout << "INFO : Saving data" << std::endl;
            for(const auto& obj : processed) {
                s0ve::saveMapToCsvDouble("post_process/" + obj.first + ".csv", obj.second, ",", "#");
            }
            std::cout << "INFO : Post-processing end" << std::endl;
        }

        void init() {
            // create post_process directory
            if(not std::filesystem::exists("post_process")) {
                std::filesystem::create_directory("post_process");
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
                            parameters.step = (time.size() - parameters.begin)/parameters.nb;
                        }
                        for(int i = time.size() - 1; i > -1; i--) {
                            if(not ((i > parameters.begin) && (i - parameters.begin < parameters.nb * parameters.step) && ((i - parameters.begin) % parameters.step == 0))) {
                                time.erase(time.begin() + i);
                            }
                        }
                    }
                    // first step
                    load(env, time.front());
                    // // objects
                    if(parameters.isPostProcessingObjects) {
                        processed["objects"] = std::map<std::string, std::vector<TypeScalar>>();
                        processed["objects"]["time"] = time;
                        for(const auto& p : postObjects(env.objects.state, time.front())) { 
                            processed["objects"][p.first] = std::vector<TypeScalar>();
                            processed["objects"][p.first].push_back(p.second);
                        }
                    }
                    // // mesh
                    if(parameters.isPostProcessingMesh) {
                        processed["mesh"] = std::map<std::string, std::vector<TypeScalar>>();
                        for(const auto& p : postMesh()) {
                            processed["mesh"][p.first].push_back(p.second);
                        }
                    }
                    // // flow
                    if(parameters.isPostProcessingFlow) {
                        processed["flow"] = std::map<std::string, std::vector<TypeScalar>>();
                        for(const auto& p : postFlow(time.front())) {
                            processed["flow"][p.first].push_back(p.second);
                        }
                    }
                    // first step done
                    time.erase(time.begin());
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
            l0ad::ascii::loadArrayDouble(folder + "/objects.txt", env.objects.state, '\n');
            env.objects.t = t;
            env.sFlow->init(t);
            if(parameters.isPreparingFlow) {
                if(parameters.isPostProcessingObjects) {
                    env.sFlow->prepare(env.objects.sStep->positions(env.objects.state), t);
                }
                if(parameters.isPostProcessingFlow) {
                    env.sFlow->prepare(mesh.sData->positionCells(), t);
                }
            }
        }
};

}

#endif
