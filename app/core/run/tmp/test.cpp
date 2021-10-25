
// std includes
#include <filesystem>
// app includes
#include "env/core.h"

int main () { 
    // Search for last time step
    std::vector<double> time;
    for (const auto & entry : std::filesystem::directory_iterator("time")) {
        time.emplace_back(std::stod(entry.path().filename()));
    }
    // Condition test
    if(time.size() > 0) {
        std::sort(time.begin(), time.end());
        // Build environnement and run case
        c0p::Env env;
        // Condition test
        if(time.back() < env.dt * env.nt > 0) {
            // Load case
            env.loadTxt(time.back());
            // Run case
            for(std::size_t i = time.back()/env.dt + 1; i < env.nt; i++) {
                // Update agents
                for(auto& agent : env.agents) {
                    agent.update();
                }
                // Save if condition is valid
                if(i % (env.nt/env.nsave) == 0) {
                    std::cout << "Saving frame " << i << "/" << env.nt << "." << std::endl;
                    env.saveTxt();
                }
            }
            // Save last time step
            std::cout << "Saving last frame." << std::endl;
            env.saveTxt();
        } else {
            std::cout << "INFO : Computation already finished. Nothing to do." << std::endl;
        }
    } else {
        std::cout << "ERROR : No directory were found in the folder 'time/'. Did you run the '0' program ?" << std::endl;
    }
}
