#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_LINE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_LINE_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/line/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupLine : public InitInitInitStatic<TypeObjectStep> {
	public:
		TypeParameters parameters;
	public:
		using InitInitInitStatic<TypeObjectStep>::sObjectStep;
	public:
		InitInitGroupLine(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep) {
		}
	public:
		using InitInitInitStatic<TypeObjectStep>::operator();
		void operator()(double* pState) override {
			std::for_each(std::execution::seq, sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, pState](const unsigned int& memberIndex){ 
				sObjectStep->sMemberStep->x(sObjectStep->memberState(pState, memberIndex)) = parameters.origin + parameters.l * double(memberIndex) / double(sObjectStep->size() - 1);
				*sObjectStep->sMemberStep->scalar(sObjectStep->memberState(pState, memberIndex)) = parameters.l.norm() * double(memberIndex) / double(sObjectStep->size() - 1);
			});
		};
};

}

#endif
