cmake_minimum_required(VERSION 3.14)

project(c0p LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT DEFINED C0P_PROJECT_DIR)
    set(C0P_PROJECT_DIR ../..)
endif()
message(INFO " C0P_PROJECT_DIR " ${C0P_PROJECT_DIR})

## PACKAGES
list(APPEND CMAKE_MODULE_PATH ${C0P_PROJECT_DIR}/cmake/modules) # maybe unecessary ?
find_package(TBB REQUIRED)

### turblib (JHTDB)
list(APPEND TURB_LIB_SRC_FILES "${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/turblib/soapC.c" "${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/turblib/soapClient.c" "${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/turblib/stdsoap2.c" "${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/turblib/turblib.c")

# Build run
add_executable(run ${C0P_PROJECT_DIR}/app/core/run/main.cpp ${TURB_LIB_SRC_FILES})
## Link Libraries
target_link_libraries(run TBB::tbb)
## Include
target_include_directories(run PRIVATE .)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/app)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/thirdparty/eigen)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/s0s/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/sp0ce/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/d0t/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/p0l/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/m0sh/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/l0ad/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/s0ve/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/fl0p/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/v0l/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/turblib)
## Compile features
target_compile_features(run PUBLIC cxx_std_23)

# Build post
add_executable(post ${C0P_PROJECT_DIR}/app/core/post/main.cpp ${TURB_LIB_SRC_FILES})
## Libraries
target_link_libraries(post TBB::tbb)
## Include
target_include_directories(post PRIVATE .)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/app)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/thirdparty/eigen)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/s0s/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/sp0ce/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/d0t/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/p0l/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/m0sh/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/l0ad/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/s0ve/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/fl0p/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/v0l/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/turblib)
## Compile features
target_compile_features(post PUBLIC cxx_std_23)
