#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/custom/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of a custom behaviour
template<typename AgentActiveStep>
struct ObjectAgentBehaviourTrackerBehaviourDirectionCustomParameters {
	const double vorticityThreshold0 = 1.0 / Parameters::cTime / 3.0;
	const double vorticityThreshold1 = 1.0 / Parameters::cTime;
	// Function that returns the preferred swimming direction
	TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const {
		// Implements the behaviour of Alageshan et al 2020.
		// extract vorticity from gradients
		const TypeSpaceMatrix skewVelocityGradients = 0.5 * (velocityGradients - velocityGradients.transpose());
		const TypeSpaceVector vorticity = (TypeSpaceVector() << -2.0 * skewVelocityGradients(1, 2), 2.0 * skewVelocityGradients(0, 2), -2.0 * skewVelocityGradients(0, 1)).finished();
		// build cartesian system
		const TypeSpaceVector targetDirection = (position - stepActive.cX(pState)).normalized();
		const TypeSpaceVector targetDirectionCrossVorticity = targetDirection.cross(vorticity).normalized();
		const TypeSpaceVector targetDirectionPerp = targetDirection.cross(targetDirectionCrossVorticity).normalized();
		// extract orientation axis
		const TypeSpaceVector orientationAxis = stepActive.cAxis(pState);
		// if no error
		//const double x = orientationAxis.dot(targetDirectionPerp);
		//const double y = orientationAxis.dot(-targetDirectionCrossVorticity);
		//const double z = orientationAxis.dot(targetDirection);
		// if error
		const double x = orientationAxis.dot(targetDirectionCrossVorticity);
		const double y = orientationAxis.dot(targetDirectionPerp);
		const double z = orientationAxis.dot(targetDirection);
		// extract the three scalars that define the state
		const double vorticityNorm = vorticity.norm();
		const double theta = std::atan(z / std::sqrt(x*x + y*y + z*z));
		const double phi = std::atan2(y, x);
		// define actions
		const TypeSpaceVector action0 = targetDirection;
		const TypeSpaceVector action1 = -targetDirection;
		const TypeSpaceVector action2 = targetDirectionCrossVorticity;
		const TypeSpaceVector action3 = -targetDirectionCrossVorticity;
		const TypeSpaceVector action4 = targetDirectionPerp;
		const TypeSpaceVector action5 = -targetDirectionPerp;
		// compute state
		int state = 0;
		if(vorticityNorm < vorticityThreshold0) {
			state = 1;
		} else if (vorticityNorm <= vorticityThreshold1) {
			if(theta < M_PI / 6.0) {
				state = 2;
			} else if (theta <= 5.0 / 6.0 * M_PI) {
				if(phi < M_PI / 2.0) {
					state = 6;
				} else if(phi < M_PI) {
					state = 7;
				} else if(phi < 3.0/2.0 * M_PI) {
					state = 8;
				} else {
					state = 9;
				}
			} else {
				state = 3;
			}
		} else {
			if(theta < M_PI / 6.0) {
				state = 4;
			} else if (theta <= 5.0 / 6.0 * M_PI) {
				if(phi < M_PI / 2.0) {
					state = 10;
				} else if(phi < M_PI) {
					state = 11;
				} else if(phi < 3.0/2.0 * M_PI) {
					state = 12;
				} else {
					state = 13;
				}
			} else {
				state = 5;
			}
		}
		// return action corresponding to state
		if(state == 1) {
			return action0;
		} else if(state == 2) {
			return action0;
		} else if(state == 3) {
	   		return action0;
	   	} else if(state == 4) {
	   		return action0;
	   	} else if(state == 5) {
	   		return action0;
	   	} else if(state == 6) {
	   		return action0;
	   	} else if(state == 7) {
			return action0;
		} else if(state == 8) {
	   		return action0;
	   	} else if(state == 9) {
	   		return action0;
	   	} else if(state == 10) {
	   		return action0;
	   	} else if(state == 11) {
	   		return action0;
	   	} else if(state == 12) {
	   		return action0;
	   	} else if(state == 13) {
	   		return action0;
	   	} else {
	   		std::cout << "Shouldn't happen" << std::endl;
	   		return action0;
	   	}
	}
};

}

#endif
