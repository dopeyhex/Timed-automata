cmake_minimum_required(VERSION 3.5)

project(ta LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set(DCMAKE_CXX_COMPILER "/usr/local/bin/g++-11")
    set(OPENMP_LIBRARIES "/usr/local/Cellar/llvm/13.0.1_1/lib")
    set(OPENMP_INCLUDES "/usr/local/Cellar/llvm/13.0.0_1/include")
    include_directories("${OPENMP_INCLUDES}")
    link_directories("${OPENMP_LIBRARIES}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(../src)
include_directories(../headers)

set(SOURCE
    ../src/ta/cc.cpp
    ../src/ta/clock.cpp
    ../src/ta/state.cpp
    ../src/ta/step.cpp
    ../src/ta/ta.cpp
    ../src/regions/graph.cpp
    ../src/main.cpp
)

add_executable(main ${SOURCE})