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
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_1o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_4o0/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_4o5/parameters.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_5o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_0o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_4o0/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_4o5/parameters.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_5o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_0o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_4o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_4o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_5o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_0o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_4o0/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_4o5/parameters.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_5o0/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

// Post processing parameters
struct PostObjectsParameters {
    // make data
    std::vector<std::shared_ptr<PostPostBase>> sPostsStatic;
    std::vector<std::shared_ptr<PostPostBase>> sPostsDynamic;
    PostObjectsParameters(std::shared_ptr<ObjectsParameters> sObjectsParameters) {
        // FLAG: MAKE OBJECT BEGIN
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor1O0Parameters, SurferUs1O0Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor1O0Parameters, SurferUs0O1Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor1O0Parameters, SurferUs0O5Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor1O0Parameters, SurferUs2O0Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor1O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor0O0Parameters, SurferUs0O1Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor0O5Parameters, SurferUs0O1Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor1O5Parameters, SurferUs0O1Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor1O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor2O0Parameters, SurferUs0O1Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor2O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor2O5Parameters, SurferUs0O1Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor2O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor3O0Parameters, SurferUs0O1Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor3O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor3O5Parameters, SurferUs0O1Surftimeprefactor3O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor3O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor4O0Parameters, SurferUs0O1Surftimeprefactor4O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor4O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor4O5Parameters, SurferUs0O1Surftimeprefactor4O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor4O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O1Surftimeprefactor5O0Parameters, SurferUs0O1Surftimeprefactor5O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor5O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor0O0Parameters, SurferUs0O5Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor0O5Parameters, SurferUs0O5Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor1O5Parameters, SurferUs0O5Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor1O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor2O0Parameters, SurferUs0O5Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor2O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor2O5Parameters, SurferUs0O5Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor2O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor3O0Parameters, SurferUs0O5Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor3O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor3O5Parameters, SurferUs0O5Surftimeprefactor3O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor3O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor4O0Parameters, SurferUs0O5Surftimeprefactor4O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor4O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor4O5Parameters, SurferUs0O5Surftimeprefactor4O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor4O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs0O5Surftimeprefactor5O0Parameters, SurferUs0O5Surftimeprefactor5O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor5O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor0O0Parameters, SurferUs1O0Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor0O5Parameters, SurferUs1O0Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor1O5Parameters, SurferUs1O0Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor1O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor2O0Parameters, SurferUs1O0Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor2O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor2O5Parameters, SurferUs1O0Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor2O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor3O0Parameters, SurferUs1O0Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor3O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor3O5Parameters, SurferUs1O0Surftimeprefactor3O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor3O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor4O0Parameters, SurferUs1O0Surftimeprefactor4O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor4O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor4O5Parameters, SurferUs1O0Surftimeprefactor4O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor4O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor5O0Parameters, SurferUs1O0Surftimeprefactor5O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor5O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor0O0Parameters, SurferUs2O0Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor0O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor0O5Parameters, SurferUs2O0Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor0O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor1O5Parameters, SurferUs2O0Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor1O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor2O0Parameters, SurferUs2O0Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor2O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor2O5Parameters, SurferUs2O0Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor2O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor3O0Parameters, SurferUs2O0Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor3O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor3O5Parameters, SurferUs2O0Surftimeprefactor3O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor3O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor4O0Parameters, SurferUs2O0Surftimeprefactor4O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor4O0Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor4O5Parameters, SurferUs2O0Surftimeprefactor4O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor4O5Step));
        sPostsStatic.push_back(std::make_shared<PostPost<PostSurferUs2O0Surftimeprefactor5O0Parameters, SurferUs2O0Surftimeprefactor5O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor5O0Step));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif