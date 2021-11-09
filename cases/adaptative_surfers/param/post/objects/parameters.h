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
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_1o0/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_1o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_0o25/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_0o75/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o25/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o75/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o25/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o75/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o25/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o75/parameters.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_4o0/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o25/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o75/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_1o25/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_1o75/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o25/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o75/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o25/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o75/parameters.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_4o0/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o25/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o5/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o75/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_1o25/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_1o5/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_1o75/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_2o0/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_2o25/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_2o5/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_2o75/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o0/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o25/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o5/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o75/parameters.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_4o0/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

// Post processing parameters
struct PostObjectsParameters {
    // make data
    std::vector<std::shared_ptr<PostPostBase>> data;
    PostObjectsParameters(const TypeObjects& objects) {
        // FLAG: MAKE OBJECT BEGIN
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor1O0Parameters, SurferUs1O0Surftimeprefactor1O0Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor1O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor1O0Parameters, SurferUs4O0Surftimeprefactor1O0Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor1O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor1O0Parameters, SurferUs8O0Surftimeprefactor1O0Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor1O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor0O25Parameters, SurferUs1O0Surftimeprefactor0O25Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor0O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor0O5Parameters, SurferUs1O0Surftimeprefactor0O5Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor0O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor0O75Parameters, SurferUs1O0Surftimeprefactor0O75Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor0O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor1O25Parameters, SurferUs1O0Surftimeprefactor1O25Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor1O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor1O5Parameters, SurferUs1O0Surftimeprefactor1O5Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor1O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor1O75Parameters, SurferUs1O0Surftimeprefactor1O75Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor1O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor2O0Parameters, SurferUs1O0Surftimeprefactor2O0Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor2O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor2O25Parameters, SurferUs1O0Surftimeprefactor2O25Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor2O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor2O5Parameters, SurferUs1O0Surftimeprefactor2O5Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor2O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor2O75Parameters, SurferUs1O0Surftimeprefactor2O75Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor2O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor3O0Parameters, SurferUs1O0Surftimeprefactor3O0Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor3O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor3O25Parameters, SurferUs1O0Surftimeprefactor3O25Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor3O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor3O5Parameters, SurferUs1O0Surftimeprefactor3O5Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor3O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor3O75Parameters, SurferUs1O0Surftimeprefactor3O75Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor3O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs1O0Surftimeprefactor4O0Parameters, SurferUs1O0Surftimeprefactor4O0Step>>(objects.parameters.sSurferUs1O0Surftimeprefactor4O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor0O25Parameters, SurferUs4O0Surftimeprefactor0O25Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor0O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor0O5Parameters, SurferUs4O0Surftimeprefactor0O5Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor0O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor0O75Parameters, SurferUs4O0Surftimeprefactor0O75Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor0O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor1O25Parameters, SurferUs4O0Surftimeprefactor1O25Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor1O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor1O5Parameters, SurferUs4O0Surftimeprefactor1O5Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor1O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor1O75Parameters, SurferUs4O0Surftimeprefactor1O75Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor1O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor2O0Parameters, SurferUs4O0Surftimeprefactor2O0Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor2O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor2O25Parameters, SurferUs4O0Surftimeprefactor2O25Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor2O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor2O5Parameters, SurferUs4O0Surftimeprefactor2O5Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor2O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor2O75Parameters, SurferUs4O0Surftimeprefactor2O75Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor2O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor3O0Parameters, SurferUs4O0Surftimeprefactor3O0Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor3O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor3O25Parameters, SurferUs4O0Surftimeprefactor3O25Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor3O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor3O5Parameters, SurferUs4O0Surftimeprefactor3O5Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor3O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor3O75Parameters, SurferUs4O0Surftimeprefactor3O75Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor3O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs4O0Surftimeprefactor4O0Parameters, SurferUs4O0Surftimeprefactor4O0Step>>(objects.parameters.sSurferUs4O0Surftimeprefactor4O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor0O25Parameters, SurferUs8O0Surftimeprefactor0O25Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor0O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor0O5Parameters, SurferUs8O0Surftimeprefactor0O5Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor0O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor0O75Parameters, SurferUs8O0Surftimeprefactor0O75Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor0O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor1O25Parameters, SurferUs8O0Surftimeprefactor1O25Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor1O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor1O5Parameters, SurferUs8O0Surftimeprefactor1O5Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor1O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor1O75Parameters, SurferUs8O0Surftimeprefactor1O75Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor1O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor2O0Parameters, SurferUs8O0Surftimeprefactor2O0Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor2O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor2O25Parameters, SurferUs8O0Surftimeprefactor2O25Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor2O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor2O5Parameters, SurferUs8O0Surftimeprefactor2O5Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor2O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor2O75Parameters, SurferUs8O0Surftimeprefactor2O75Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor2O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor3O0Parameters, SurferUs8O0Surftimeprefactor3O0Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor3O0Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor3O25Parameters, SurferUs8O0Surftimeprefactor3O25Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor3O25Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor3O5Parameters, SurferUs8O0Surftimeprefactor3O5Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor3O5Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor3O75Parameters, SurferUs8O0Surftimeprefactor3O75Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor3O75Step));
        data.push_back(std::make_shared<PostPost<PostSurferUs8O0Surftimeprefactor4O0Parameters, SurferUs8O0Surftimeprefactor4O0Step>>(objects.parameters.sSurferUs8O0Surftimeprefactor4O0Step));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
