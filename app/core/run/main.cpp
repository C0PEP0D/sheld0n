// app includes
// // env
#include "param/env/parameters.h"
#include "core/env/core.h"
// // objects
#include "param/env/objects/parameters.h"
#include "core/env/objects/core.h"
// // init
#include "param/init/parameters.h"
#include "param/init/objects/parameters.h"
#include "core/init/core.h"
// // run
#include "param/run/parameters.h"
#include "core/run/core.h"

int main () { 
    c0p::Run<c0p::RunParameters, c0p::Env<c0p::EnvParameters, c0p::Objects<c0p::ObjectsParameters>>, c0p::Init<c0p::InitParameters, c0p::InitObjectsParameters, c0p::Env<c0p::EnvParameters, c0p::Objects<c0p::ObjectsParameters>>>> run;
}
