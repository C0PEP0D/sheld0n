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
#include "param/post/objects/tracers__e3_1o0/parameters.h"
#include "param/post/objects/tracers__e3_0o01/parameters.h"
#include "param/post/objects/tracers__e3_0o1/parameters.h"
#include "param/post/objects/tracers__e3_10o0/parameters.h"
#include "param/post/objects/tracers__e1_0o01/parameters.h"
#include "param/post/objects/tracers__e1_0o1/parameters.h"
#include "param/post/objects/tracers__e1_1o0/parameters.h"
#include "param/post/objects/tracers__e1_10o0/parameters.h"
#include "param/post/objects/tracers__e2_0o01/parameters.h"
#include "param/post/objects/tracers__e2_0o1/parameters.h"
#include "param/post/objects/tracers__e2_1o0/parameters.h"
#include "param/post/objects/tracers__e2_10o0/parameters.h"
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
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE31O0Parameters, TracersE31O0Step>>(sObjectsParameters->sTracersE31O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE30O01Parameters, TracersE30O01Step>>(sObjectsParameters->sTracersE30O01Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE30O1Parameters, TracersE30O1Step>>(sObjectsParameters->sTracersE30O1Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE310O0Parameters, TracersE310O0Step>>(sObjectsParameters->sTracersE310O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE10O01Parameters, TracersE10O01Step>>(sObjectsParameters->sTracersE10O01Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE10O1Parameters, TracersE10O1Step>>(sObjectsParameters->sTracersE10O1Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE11O0Parameters, TracersE11O0Step>>(sObjectsParameters->sTracersE11O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE110O0Parameters, TracersE110O0Step>>(sObjectsParameters->sTracersE110O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE20O01Parameters, TracersE20O01Step>>(sObjectsParameters->sTracersE20O01Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE20O1Parameters, TracersE20O1Step>>(sObjectsParameters->sTracersE20O1Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE21O0Parameters, TracersE21O0Step>>(sObjectsParameters->sTracersE21O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostTracersE210O0Parameters, TracersE210O0Step>>(sObjectsParameters->sTracersE210O0Step));
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
