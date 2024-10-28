#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_CIRCLE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_CIRCLE_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/circle/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupCircle : public InitInitInitStatic<TypeObjectStep> {
	public:
		TypeParameters parameters;
	public:
		using InitInitInitStatic<TypeObjectStep>::sObjectStep;
	public:
		InitInitGroupCircle(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep) {
		}
	public:
		using InitInitInitStatic<TypeObjectStep>::operator();
		void operator()(double* pState) override {
			std::for_each(std::execution::seq, sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, pState](const unsigned int& memberIndex){
				const double s = double(memberIndex) / double(sObjectStep->size()); 
				sObjectStep->sMemberStep->x(sObjectStep->memberState(pState, memberIndex)) = parameters.center + parameters.rx * std::cos(2 * M_PI * s) + parameters.ry * std::sin(2 * M_PI * s);
				sObjectStep->sMemberStep->axis(sObjectStep->memberState(pState, memberIndex)) = (parameters.rx * std::cos(2 * M_PI * s) + parameters.ry * std::sin(2 * M_PI * s)).normalized();
				*sObjectStep->sMemberStep->scalar(sObjectStep->memberState(pState, memberIndex)) = s;
			});
		};
};

}

#endif
