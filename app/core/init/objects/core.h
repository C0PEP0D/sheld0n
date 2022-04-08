#ifndef C0P_CORE_INIT_OBJECTS_CORE_H
#define C0P_CORE_INIT_OBJECTS_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <string>
#include <map>
// app includes
#include "core/init/objects/prop.h"

namespace c0p {

template<typename TypeParameters>
class InitObjects {
	public:
		TypeParameters parameters;
		std::shared_ptr<TypeObjects> sObjects;
	public:
		InitObjects(std::shared_ptr<TypeObjects> p_sObjects, std::shared_ptr<TypeObjectsParameters> sObjectsParameters) : parameters(sObjectsParameters), sObjects(p_sObjects) {
		}
	public:
		void operator()(std::vector<double>& stateStatic, std::vector<std::vector<double>>& statesDynamic, std::vector<std::vector<std::vector<double>>>& statesManager) {
			// static
			for(const unsigned int& memberIndex : sObjects->sStepStatic->memberIndexs) {
				(*parameters.sInitsStatic[memberIndex])(sObjects->sStepStatic->memberState(stateStatic.data(), memberIndex));
			}
			sObjects->sStepStatic->update(stateStatic, 0.0);
			// dynamic
			for(const unsigned int& dynamicIndex : sObjects->dynamicIndexs) {
				(*parameters.sInitsDynamic[dynamicIndex])(statesDynamic[dynamicIndex]);
				sObjects->sStepsDynamic[dynamicIndex]->update(statesDynamic[dynamicIndex], 0.0);
			}
			// manager
			for(const unsigned int& managerIndex : sObjects->managerIndexs) {
				(*parameters.sInitsManager[managerIndex])(statesManager[managerIndex]);
				sObjects->sStepsManager[managerIndex]->update(statesManager[managerIndex], 0.0);
			}
		}
};

}

#endif
