#ifndef C0P_PARAM_POST_OBJECTS_PARAPETERS_H
#define C0P_PARAM_POST_OBJECTS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMANDS ARE USED

// std include
#include <vector>
// app include
#include "core/post/objects/object/core.h"
#include "core/post/objects/prop.h"
// FLAG: INCLUDE OBJECT BEGIN
#include "param/post/objects/object/parameters.h"
#include "param/post/objects/dobject/parameters.h"
#include "param/post/objects/mobject/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

// Post processing parameters
struct PostObjectsParameters {
	// make data
	std::vector<std::shared_ptr<PostPostBase>> sPostsStatic;
	std::vector<std::shared_ptr<PostPostBase>> sPostsDynamic;
	std::vector<std::shared_ptr<PostPostManagerBase>> sPostsManager;
	PostObjectsParameters(std::shared_ptr<ObjectsParameters> sObjectsParameters) {
		// FLAG: MAKE OBJECT BEGIN
		sPostsStatic.push_back(std::make_shared<PostPost<PostObjectParameters, ObjectStep>>(sObjectsParameters->sObjectStep));
		sPostsDynamic.push_back(std::make_shared<PostPost<PostDobjectParameters, DobjectStep>>(sObjectsParameters->sDobjectStep));
		sPostsManager.push_back(std::make_shared<PostPostManager<PostMobjectParameters, MobjectStep>>(sObjectsParameters->sMobjectStep));
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
