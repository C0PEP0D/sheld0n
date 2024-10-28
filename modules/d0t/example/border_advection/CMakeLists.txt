cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(border_advection)

## PACKAGES
### tbb
if(DEFINED TBB_DIR)
    add_library(tbb SHARED IMPORTED)
    set_target_properties(tbb PROPERTIES
        IMPORTED_LOCATION "${TBB_DIR}/lib/libtbb.so"
        INTERFACE_INCLUDE_DIRECTORIES "${TBB_DIR}/include"
    )
endif()

# Build target module
add_executable(border_advection main.cpp flow.h)

## Link Libraries
target_link_libraries(border_advection tbb)

## Include
target_include_directories(border_advection PRIVATE .)
target_include_directories(border_advection PRIVATE ../../include)
target_include_directories(border_advection PRIVATE ../../../s0s/include)
target_include_directories(border_advection PRIVATE ../../../p0l/include)
target_include_directories(border_advection PRIVATE ../../../m0sh/include)
target_include_directories(border_advection PRIVATE ../../../sp0ce/include)
target_include_directories(border_advection PRIVATE ../../../../thirdparty/eigen)

## Link options
if(NOT DEFINED TBB_DIR)
    target_link_options(border_advection PRIVATE -ltbb) # TBB used for the standard execution library (parallel execution)
endif()
