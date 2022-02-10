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
#include "param/post/objects/surfer__us_1o0__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o1/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o2/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o3/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o4/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o6/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o7/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o8/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o9/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o1/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o2/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o3/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o4/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o6/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o7/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o8/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o9/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o1/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o2/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o3/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o4/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o6/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o7/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o8/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o9/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o1/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o2/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o3/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o4/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o5/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o6/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o7/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o8/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o9/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

// Post processing parameters
struct PostObjectsParameters {
    // make data
    std::vector<std::shared_ptr<PostPostBase>> sPostsStatic;
    std::vector<std::shared_ptr<PostPostBase>> sPostsDynamic;
    PostObjectsParameters(std::shared_ptr<ObjectsParameters> sObjectsParameters) {
        // FLAG: MAKE OBJECT BEGIN
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst1O0Parameters, SurferUs1O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst1O0Parameters, SurferUs0O1Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst1O0Parameters, SurferUs0O5Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst1O0Parameters, SurferUs2O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O0Parameters, SurferUs0O1Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O1Parameters, SurferUs0O1Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O1Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O2Parameters, SurferUs0O1Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O2Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O3Parameters, SurferUs0O1Surftimeconst0O3Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O3Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O4Parameters, SurferUs0O1Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O4Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O5Parameters, SurferUs0O1Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O6Parameters, SurferUs0O1Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O6Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O7Parameters, SurferUs0O1Surftimeconst0O7Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O7Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O8Parameters, SurferUs0O1Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O8Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeconst0O9Parameters, SurferUs0O1Surftimeconst0O9Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O9Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O0Parameters, SurferUs0O5Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O1Parameters, SurferUs0O5Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O1Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O2Parameters, SurferUs0O5Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O2Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O3Parameters, SurferUs0O5Surftimeconst0O3Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O3Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O4Parameters, SurferUs0O5Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O4Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O5Parameters, SurferUs0O5Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O6Parameters, SurferUs0O5Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O6Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O7Parameters, SurferUs0O5Surftimeconst0O7Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O7Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O8Parameters, SurferUs0O5Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O8Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeconst0O9Parameters, SurferUs0O5Surftimeconst0O9Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O9Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O0Parameters, SurferUs1O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O1Parameters, SurferUs1O0Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O1Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O2Parameters, SurferUs1O0Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O2Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O3Parameters, SurferUs1O0Surftimeconst0O3Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O3Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O4Parameters, SurferUs1O0Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O4Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O5Parameters, SurferUs1O0Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O6Parameters, SurferUs1O0Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O6Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O7Parameters, SurferUs1O0Surftimeconst0O7Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O7Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O8Parameters, SurferUs1O0Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O8Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeconst0O9Parameters, SurferUs1O0Surftimeconst0O9Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O9Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O0Parameters, SurferUs2O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O1Parameters, SurferUs2O0Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O1Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O2Parameters, SurferUs2O0Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O2Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O3Parameters, SurferUs2O0Surftimeconst0O3Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O3Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O4Parameters, SurferUs2O0Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O4Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O5Parameters, SurferUs2O0Surftimeconst0O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O6Parameters, SurferUs2O0Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O6Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O7Parameters, SurferUs2O0Surftimeconst0O7Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O7Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O8Parameters, SurferUs2O0Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O8Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeconst0O9Parameters, SurferUs2O0Surftimeconst0O9Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O9Step));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
