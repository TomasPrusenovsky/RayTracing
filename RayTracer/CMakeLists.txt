cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 23)
set(GLM_DIRS vendor/glm)

add_subdirectory(${GLM_DIRS})

add_library(RayTracer
        src/RayTracer.cpp
        src/RayTracer.h
        src/Utils/Ray.cpp
        src/Utils/Ray.h
        src/Camera.cpp
        src/Camera.h
        src/Image/Image.cpp
        src/Image/Image.h
        src/Utils/Shapes/Shape.h
        src/Utils/Material.h
        src/Utils/Shapes/Sphere.cpp
        src/Utils/Shapes/Sphere.h
        src/Math/Math.cpp
        src/Math/Math.h
        src/Scene/Scene.cpp
        src/Scene/Scene.h
        src/Math/Random.cpp
        src/Math/Random.h
)

target_link_libraries(RayTracer PRIVATE glm)
target_include_directories(RayTracer PRIVATE ${GLM_DIRS})