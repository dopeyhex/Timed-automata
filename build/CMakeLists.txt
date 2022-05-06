cmake_minimum_required(VERSION 3.5)

project(bruh LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set (DCMAKE_CXX_COMPILER "g++-11")
    set(OPENMP_LIBRARIES "/usr/local/Cellar/llvm/13.0.0_1/lib")
    set(OPENMP_INCLUDES "/usr/local/Cellar/llvm/13.0.0_1/include")
    include_directories("${OPENMP_INCLUDES}")
    link_directories("${OPENMP_LIBRARIES}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(../src)
include_directories(../headers)

set(SOURCE
    ../src/main.cpp
    ../src/clock.cpp
    ../src/cc.cpp
    ../src/state.cpp
    ../src/ta.cpp
    ../src/graph.cpp
)

add_executable(main ${SOURCE})