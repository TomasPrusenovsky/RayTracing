cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 23)
set(GLM_DIRS vendor/glm)

add_subdirectory(${GLM_DIRS})

add_library(RayTracer
        src/RayTracer.cpp
        src/RayTracer.h
)

target_link_libraries(RayTracer PRIVATE glm)
target_include_directories(RayTracer PRIVATE ${GLM_DIRS})