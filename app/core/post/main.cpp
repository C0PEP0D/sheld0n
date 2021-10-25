// app includes
// // env
#include "core/env/core.h"
#include "param/env/parameters.h"
// // objects
#include "core/env/objects/core.h"
#include "param/env/objects/parameters.h"
// // post
#include "core/post/core.h"
#include "param/post/parameters.h"
// // post objects
#include "param/post/objects/parameters.h"
// // post mesh
#include "param/post/mesh/parameters.h"
// // post flow
#include "param/post/flow/parameters.h"

int main () { 
    c0p::Post<c0p::PostParameters, c0p::PostObjectsParameters, c0p::PostMeshParameters, c0p::PostFlowParameters, c0p::Env<c0p::EnvParameters, c0p::Objects<c0p::ObjectsParameters>>> post;
}
