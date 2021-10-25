// Lib includes
#include "environnement.h"
#include <random>

int main () { 
    // Random management
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> runiform(0,1.0);
    // Init
    Environnement env;
    // Define agents
    for(std::size_t i = 0; i < env.na; i++) {
        AgentCustom& agent = env.agents[i];
        // Position
        agent.step.x(agent.state) = TypeVector::Random().normalized() * std::pow(runiform(rng), 1.0/3.0) * env.ra;
    }
    // Save
    env.saveTxt();
}
