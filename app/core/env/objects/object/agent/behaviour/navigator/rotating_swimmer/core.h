#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_ROTATING_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_ROTATING_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/navigator/rotating_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorDirection, typename TypeSensorVelocityGradients, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourNavigatorRotatingSwimmer : public sl0::sa0::Behaviour<AgentActiveStep> {
	public:
		using Type = sl0::sa0::Behaviour<AgentActiveStep>;
		using TypeStateVectorDynamic = typename AgentActiveStep::TypeStateVectorDynamic;
	public:
		TypeParameters parameters;
		// sensors
		TypeSensorDirection sensorDirection;
		TypeSensorVelocityGradients sensorVelocityGradients;
		// sub behaviours
		TypeBehaviourDirection behaviourDirection;
		TypeBehaviourVelocity behaviourVelocity;
	public:
		AgentBehaviourNavigatorRotatingSwimmer(std::shared_ptr<Objects> sObjects) : sensorDirection(sObjects) {
		}
	public:
		TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const override {
			TypeContainer<TypeSpaceVector> result;
			// sensors
			const TypeContainer<TypeSpaceVector> positionsSensorDirection = sensorDirection.positions(pState, stepActive);
			result.insert(result.end(), positionsSensorDirection.begin(), positionsSensorDirection.end());
			const TypeContainer<TypeSpaceVector> positionsSensorVelocityGradients = sensorVelocityGradients.positions(pState, stepActive);
			result.insert(result.end(), positionsSensorVelocityGradients.begin(), positionsSensorVelocityGradients.end());
			// sub behaviours
			const TypeContainer<TypeSpaceVector> positionsBehaviourDirection = behaviourDirection.positions(pState, stepActive);
			result.insert(result.end(), positionsBehaviourDirection.begin(), positionsBehaviourDirection.end());
			const TypeContainer<TypeSpaceVector> positionsBehaviourVelocity = behaviourVelocity.positions(pState, stepActive);
			result.insert(result.end(), positionsBehaviourVelocity.begin(), positionsBehaviourVelocity.end());
			// return
			return result;
		}
	public:
		void operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const override {
			// sensors
			const TypeSpaceVector direction = sensorDirection(pState, t, stepActive);
			// // velocity gradients
			const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(pState, t, stepActive);
			const TypeSpaceMatrix skewVelocityGradients = 0.5 * (velocityGradients - velocityGradients.transpose());
			const TypeSpaceVector vorticity = 2.0 * TypeSpaceVector({-skewVelocityGradients(1, 2), skewVelocityGradients(0, 2), -skewVelocityGradients(0, 1)});
			const TypeSpaceMatrix symVelocityGradients = 0.5 * (velocityGradients + velocityGradients.transpose());
			// input
			const TypeSpaceVector swimmingDirection = stepActive.cAxis(pState);
			const TypeSpaceVector targetDirection = behaviourDirection(pState, t, stepActive, direction, velocityGradients).normalized();
			// control theory
			const double errorAngle = std::atan2(swimmingDirection.cross(targetDirection).norm(), swimmingDirection.dot(targetDirection));
			const TypeSpaceVector angularVelocityAxis = swimmingDirection.cross(targetDirection).normalized();
			TypeSpaceVector angularVelocity = errorAngle / parameters.time * angularVelocityAxis;
			// exploiting flow measure
			angularVelocity -= 0.5 * (vorticity - vorticity.dot(swimmingDirection) * swimmingDirection);
			angularVelocity -= stepActive.factor * swimmingDirection.cross(symVelocityGradients * swimmingDirection);
			const double angularVelocityNorm = angularVelocity.norm();
			// // set actuators
			if (angularVelocityNorm > 0.0){
				if (angularVelocityNorm > parameters.maxSwimmingAngularVelocity) {
					stepActive.sStepAxisRotate->angularVelocity = angularVelocity;
				} else {
					stepActive.sStepAxisRotate->angularVelocity = parameters.maxSwimmingAngularVelocity * angularVelocity / angularVelocityNorm;
				}
			} else {
				stepActive.sStepAxisRotate->angularVelocity = angularVelocity;
			}
			stepActive.sStepLocalAxisSwim->velocity = behaviourVelocity(pState, t, stepActive, direction, velocityGradients, swimmingDirection) * stepActive.parameters.velocity;
		}
};


}

#endif
