#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_FILTERED_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_FILTERED_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/filtered/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsFiltered : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsFiltered() {
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const override {
            // init
            TypeContainer<TypeSpaceVector> result;
            // more
            const TypeSpaceVector x = stepActive.cX(state);
            unsigned int nx = std::round(parameters.l/parameters.dx);
            result.reserve(std::pow(nx + 1, 3));
            // compute
            for(unsigned int i = 0; i < nx + 1; i++){
                for(unsigned int j = 0; j < nx + 1; j++){
                    for(unsigned int k = 0; k < nx + 1; k++){
                        // compute xTmp
                        TypeSpaceVector xTmp = x;
                        xTmp[0] += i * parameters.dx - 0.5 * parameters.l;
                        xTmp[1] += j * parameters.dx - 0.5 * parameters.l;
                        xTmp[2] += k * parameters.dx - 0.5 * parameters.l;
                        // add to results
                        result.push_back(xTmp);
                    }
                }
            }
            return result;
        }
    public:
        TypeSpaceMatrix operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive) const override {
            const TypeSpaceVector x = stepActive.cX(state);
            TypeSpaceMatrix gradients = TypeSpaceMatrix::Zero();
            unsigned int nx = std::round(parameters.l/parameters.dx);
            for(unsigned int i = 0; i < nx + 1; i++){
                for(unsigned int j = 0; j < nx + 1; j++){
                    for(unsigned int k = 0; k < nx + 1; k++){
                        // compute xTmp
                        TypeSpaceVector xTmp = x;
                        xTmp[0] += i * parameters.dx - 0.5 * parameters.l;
                        xTmp[1] += j * parameters.dx - 0.5 * parameters.l;
                        xTmp[2] += k * parameters.dx - 0.5 * parameters.l;
                        // compute gradients
                        gradients += stepActive.sFlow->getJacobian(xTmp, t);
                    }
                }
            }
            // return averaged gradient
            return gradients / std::pow(nx + 1, 3);
        }
};


}

#endif
