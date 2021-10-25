#include <functional>

// Lib includes
#include "environnement.h"


std::vector<std::tuple<std::string, std::function<double(const Environnement&, AgentCustom&, AgentCustom&)>>> saveData;

void post_process_data() {
    saveData.emplace_back("l.dat",
    [] (const Environnement& env, AgentCustom& agent0, AgentCustom& agent) { // Should be consts
        return (agent.step.x(agent.state) - agent0.step.x(agent0.state)).norm() / env.sFlow->eta;
    });
    saveData.emplace_back("x.dat",
    [] (const Environnement& env, AgentCustom& agent0, AgentCustom& agent) { // Should be consts
        return (agent.step.x(agent.state) - agent0.step.x(agent0.state))(0) / env.sFlow->eta;
    });
    saveData.emplace_back("us.dat",
        [] (const Environnement& env, AgentCustom& agent0, AgentCustom& agent) { // Should be consts
        agent.step.update(agent.state, agent.solver.t);
        return (agent.step.x(agent.step(agent.state, agent.solver.t)) - env.sFlow->getVelocity(agent.step.x(agent.state), agent.solver.t)).norm() / env.sFlow->uEta;
    });
}

int main () { 
    post_process_data();
    // Search for last time step
    std::vector<double> time;
    for (const auto & entry : std::filesystem::directory_iterator("time")) {
        time.emplace_back(std::stod(entry.path().filename()));
    }
    // Condition test
    if(time.size() > 0) {
        // Sort time
        std::sort(time.begin(), time.end());
        // Load 0 environnement
        Environnement env0;
        env0.loadTxt(0.0);
        // Save time
        std::ofstream timeFile("t.dat");
        // Write
        for(const auto& v : time) {
            timeFile << v / env0.sFlow->tauEta << "\n";
        }
        // Close file
        timeFile.close();
        // Post process for each data file
        for(const auto& data : saveData) {
            std::vector<std::vector<double>> post_process_result;
            for(const auto& t : time) {
                std::vector<double> sub_post_process_result;
                // Build environnement and run case
                Environnement env;
                env.loadTxt(t);
                // Update agents
                for(std::size_t i = 0; i < env0.na; i ++) {
                    sub_post_process_result.emplace_back(std::get<1>(data)(env, env0.agents[i], env.agents[i]));
                }
                post_process_result.push_back(sub_post_process_result);
            }
            // Save
            std::ofstream resultFile(std::get<0>(data));
            // Write
            for(const auto& sub : post_process_result) {
                for(const auto& v : sub) {
                    resultFile << v << " ";
                }
                resultFile << "\n";
            }
            // Close file
            resultFile.close();
        }
    } else {
        std::cout << "ERROR : No directory were found in the folder 'time/'. Did you run the '0' program ?" << std::endl;
    }
}
