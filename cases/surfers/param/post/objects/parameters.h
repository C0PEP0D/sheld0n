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
#include "param/post/objects/surfer__vs_1o0__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_4o0/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_5o0/parameters.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_6o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_4o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_5o0/parameters.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_6o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_4o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_5o0/parameters.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_6o0/parameters.h"
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
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst1O0Parameters, SurferVs1O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst1O0Parameters, SurferVs4O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst1O0Parameters, SurferVs8O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst0O0Parameters, SurferVs1O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst0O5Parameters, SurferVs1O0Surftimeconst0O5Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst1O5Parameters, SurferVs1O0Surftimeconst1O5Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst2O0Parameters, SurferVs1O0Surftimeconst2O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst2O5Parameters, SurferVs1O0Surftimeconst2O5Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst3O0Parameters, SurferVs1O0Surftimeconst3O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst4O0Parameters, SurferVs1O0Surftimeconst4O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst4O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst5O0Parameters, SurferVs1O0Surftimeconst5O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst5O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs1O0Surftimeconst6O0Parameters, SurferVs1O0Surftimeconst6O0Step>>(sObjectsParameters->sSurferVs1O0Surftimeconst6O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst0O0Parameters, SurferVs4O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst0O5Parameters, SurferVs4O0Surftimeconst0O5Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst1O5Parameters, SurferVs4O0Surftimeconst1O5Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst2O0Parameters, SurferVs4O0Surftimeconst2O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst2O5Parameters, SurferVs4O0Surftimeconst2O5Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst3O0Parameters, SurferVs4O0Surftimeconst3O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst4O0Parameters, SurferVs4O0Surftimeconst4O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst4O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst5O0Parameters, SurferVs4O0Surftimeconst5O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst5O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs4O0Surftimeconst6O0Parameters, SurferVs4O0Surftimeconst6O0Step>>(sObjectsParameters->sSurferVs4O0Surftimeconst6O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst0O0Parameters, SurferVs8O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst0O5Parameters, SurferVs8O0Surftimeconst0O5Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst1O5Parameters, SurferVs8O0Surftimeconst1O5Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst2O0Parameters, SurferVs8O0Surftimeconst2O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst2O5Parameters, SurferVs8O0Surftimeconst2O5Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst3O0Parameters, SurferVs8O0Surftimeconst3O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst4O0Parameters, SurferVs8O0Surftimeconst4O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst4O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst5O0Parameters, SurferVs8O0Surftimeconst5O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst5O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferVs8O0Surftimeconst6O0Parameters, SurferVs8O0Surftimeconst6O0Step>>(sObjectsParameters->sSurferVs8O0Surftimeconst6O0Step));
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
