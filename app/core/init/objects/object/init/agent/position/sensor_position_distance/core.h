#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_AGENT_POSITION_SENSOR_POSITION_DISTANCE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_AGENT_POSITION_SENSOR_POSITION_DISTANCE_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/init/agent/position/sensor_position_distance/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class InitInitAgentPositionSensorPositionDistance : public InitInitInitStatic<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        using InitInitInitStatic<TypeObjectStep>::InitInitInitStatic;
    public:
        void operator()(double* pState) override {
            sObjectStep->x(pState) = sObjectStep->sBehaviour->sensorPosition(pState, 0.0, *sObjectStep) + TypeSpaceVector::Random().normalized() * parameters.distance;
        };
};

}

#endif
