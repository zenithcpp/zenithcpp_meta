cmake_minimum_required(VERSION 3.28)

project(ZENITH_META LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(orchestrator
    src/orchestrator.cpp
)

target_include_directories(orchestrator PRIVATE
    core_ref/src
    brain
    reflection26/include
    reflection26/backends
    reflection26/meta
    reflection26/engine
    targets/include
    src
)

target_compile_options(orchestrator PRIVATE
    -Wall
    -Wextra
    -Werror
    -O3
)
