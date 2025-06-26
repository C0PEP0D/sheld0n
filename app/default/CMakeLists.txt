cmake_minimum_required(VERSION 3.14)

project(c0p LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# define local variable
if (NOT DEFINED C0P_PROJECT_DIR)
    set(C0P_PROJECT_DIR ../..)
endif()
message(INFO " C0P_PROJECT_DIR " ${C0P_PROJECT_DIR})

## SUBDIRECTORIES
### RL-TOOLS
add_subdirectory(
	${C0P_PROJECT_DIR}/thirdparty/rl-tools
	${CMAKE_BINARY_DIR}/rl-tools
)
### JHTDB
add_subdirectory(
	${C0P_PROJECT_DIR}/modules/fl0w/thirdparty/getjhtdb
	${CMAKE_BINARY_DIR}/getjhtdb
)
## PACKAGES
### TBB
list(APPEND CMAKE_MODULE_PATH ${C0P_PROJECT_DIR}/cmake/modules) # maybe unecessary ?
find_package(TBB REQUIRED)

### Python
find_package(Python COMPONENTS Interpreter Development NumPy REQUIRED)

# Additional cpp files (cython)
file(GLOB_RECURSE ADD_CPP_FILES "./param/solutions/*.cpp")

# Build run
add_executable(run ${C0P_PROJECT_DIR}/app/core/run/main.cpp ${ADD_CPP_FILES})
## Link Libraries
target_link_libraries(run TBB::tbb)
target_link_libraries(run Python::Python Python::NumPy)
target_link_libraries(run RLtools::RLtools)
target_link_libraries(run getjhtdb)


## Precompile headers
target_precompile_headers(run PUBLIC <Eigen/Dense>)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/thirdparty/pybind11/include/pybind11/embed.h)
### s0s
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/s0s/include/s0s/runge_kutta_fehlberg.h)
### sp0ce
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/sp0ce/include/sp0ce/operators.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/sp0ce/include/sp0ce/geometry.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/sp0ce/include/sp0ce/bin.h)
### d0t
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/d0t/include/d0t/variable.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/d0t/include/d0t/equation.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/d0t/include/d0t/variables/vector.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/d0t/include/d0t/variables/curve.h)
### p0l
### m0sh
### l0ad
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/l0ad/include/l0ad/ascii/load.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/l0ad/include/l0ad/ascii/double.h)
### s0ve
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/s0ve/include/s0ve/save.h)
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/s0ve/include/s0ve/double.h)
### fl0w
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/fl0w/include/fl0w/jhtdb.h)
### fl0p
### pl0f
target_precompile_headers(run PUBLIC ${C0P_PROJECT_DIR}/modules/pl0f/include/pl0f/point_vortex.h)


## Include
target_include_directories(run PRIVATE .)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/app)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/thirdparty/eigen)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/thirdparty/pybind11/include)
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
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/pl0f/include)
target_include_directories(run PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/thirdparty)
target_include_directories(run PRIVATE ${PYTHON_INCLUDE_DIRS})
## Compile features
target_compile_features(run PUBLIC cxx_std_17)

# Build post
add_executable(post ${C0P_PROJECT_DIR}/app/core/post/main.cpp ${ADD_CPP_FILES})
## Libraries
target_link_libraries(post TBB::tbb)
target_link_libraries(post Python::Python Python::NumPy)
target_link_libraries(post RLtools::RLtools)
target_link_libraries(post getjhtdb)
## Precompile headers
target_precompile_headers(post REUSE_FROM run)
## Include
target_include_directories(post PRIVATE .)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/app)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/thirdparty/eigen)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/thirdparty/pybind11/include)
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
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/pl0f/include)
target_include_directories(post PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/thirdparty)
target_include_directories(post PRIVATE ${PYTHON_INCLUDE_DIRS})
## Compile features
target_compile_features(post PUBLIC cxx_std_17)

# Build learn
add_executable(learn ${C0P_PROJECT_DIR}/app/core/learn/main.cpp ${ADD_CPP_FILES})
## Link Libraries
target_link_libraries(learn TBB::tbb)
target_link_libraries(learn Python::Python Python::NumPy)
target_link_libraries(learn RLtools::RLtools)
target_link_libraries(learn getjhtdb)
## Precompile headers
target_precompile_headers(learn REUSE_FROM run)
## Include
target_include_directories(learn PRIVATE .)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/app)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/thirdparty/eigen)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/thirdparty/pybind11/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/s0s/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/sp0ce/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/d0t/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/p0l/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/m0sh/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/l0ad/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/s0ve/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/fl0p/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/v0l/include)
target_include_directories(learn PRIVATE ${C0P_PROJECT_DIR}/modules/fl0w/thirdparty)
target_include_directories(learn PRIVATE ${PYTHON_INCLUDE_DIRS})
## Compile features
target_compile_features(learn PUBLIC cxx_std_17)
