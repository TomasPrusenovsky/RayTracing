cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 23)

set(STB_DIRS vendor/stb_image)
set(GLM_DIRS vendor/glm)
set(SRC_DIR src)

add_subdirectory(${GLM_DIRS})
add_subdirectory(${STB_DIRS})
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp" "src/*/*/*/*.cpp")


add_library(RayTracer)
target_sources(RayTracer PRIVATE ${SOURCES})

target_link_libraries(RayTracer PRIVATE glm)
target_link_libraries(RayTracer PUBLIC stb_image)

target_include_directories(RayTracer PRIVATE ${GLM_DIRS})
target_include_directories(RayTracer PRIVATE ${SRC_DIR})
target_include_directories(RayTracer PUBLIC ${STB_DIRS})


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE "RDEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE "RRELEASE")
endif()