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
#include "param/post/objects/surfer__us_0o05__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o05__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o05__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o05__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o05__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o05__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o05__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o2__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o4__surftimeconst_3o0/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o8__surftimeconst_3o0/parameters.h"
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
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst1O0Parameters, SurferUs0O05Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst1O0Parameters, SurferUs0O1Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst1O0Parameters, SurferUs0O2Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst1O0Parameters, SurferUs0O4Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst1O0Parameters, SurferUs0O8Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst1O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst0O0Parameters, SurferUs0O05Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst0O5Parameters, SurferUs0O05Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst1O5Parameters, SurferUs0O05Surftimeconst1O5Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst2O0Parameters, SurferUs0O05Surftimeconst2O0Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst2O5Parameters, SurferUs0O05Surftimeconst2O5Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O05Surftimeconst3O0Parameters, SurferUs0O05Surftimeconst3O0Step>>(sObjectsParameters->sSurferUs0O05Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O0Parameters, SurferUs0O1Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O5Parameters, SurferUs0O1Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst1O5Parameters, SurferUs0O1Surftimeconst1O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst2O0Parameters, SurferUs0O1Surftimeconst2O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst2O5Parameters, SurferUs0O1Surftimeconst2O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst3O0Parameters, SurferUs0O1Surftimeconst3O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst0O0Parameters, SurferUs0O2Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst0O5Parameters, SurferUs0O2Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst1O5Parameters, SurferUs0O2Surftimeconst1O5Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst2O0Parameters, SurferUs0O2Surftimeconst2O0Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst2O5Parameters, SurferUs0O2Surftimeconst2O5Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O2Surftimeconst3O0Parameters, SurferUs0O2Surftimeconst3O0Step>>(sObjectsParameters->sSurferUs0O2Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst0O0Parameters, SurferUs0O4Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst0O5Parameters, SurferUs0O4Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst1O5Parameters, SurferUs0O4Surftimeconst1O5Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst2O0Parameters, SurferUs0O4Surftimeconst2O0Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst2O5Parameters, SurferUs0O4Surftimeconst2O5Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O4Surftimeconst3O0Parameters, SurferUs0O4Surftimeconst3O0Step>>(sObjectsParameters->sSurferUs0O4Surftimeconst3O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst0O0Parameters, SurferUs0O8Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst0O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst0O5Parameters, SurferUs0O8Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst0O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst1O5Parameters, SurferUs0O8Surftimeconst1O5Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst1O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst2O0Parameters, SurferUs0O8Surftimeconst2O0Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst2O0Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst2O5Parameters, SurferUs0O8Surftimeconst2O5Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst2O5Step));
		sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O8Surftimeconst3O0Parameters, SurferUs0O8Surftimeconst3O0Step>>(sObjectsParameters->sSurferUs0O8Surftimeconst3O0Step));
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
