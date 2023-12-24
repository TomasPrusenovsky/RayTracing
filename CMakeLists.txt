cmake_minimum_required(VERSION 3.10)
project(Editor)

set(CMAKE_CXX_STANDARD 23)
set(PRECOMPILED_HEADER Editor/src/rtpch.h)

add_subdirectory(Editor/vendor/ImGui)
add_subdirectory(Editor/vendor/glfw)
add_subdirectory(Editor/vendor/glad)
add_subdirectory(RayTracer)

file(GLOB_RECURSE SOURCES "Editor/src/*.cpp" "Editor/src/*/*.cpp" "Editor/src/*/*/*.cpp" "Editor/src/*/*/*/*.cpp")


add_executable(Editor)
target_sources(Editor PRIVATE ${SOURCES})

target_link_libraries(Editor PRIVATE ImGui)
target_link_libraries(Editor PRIVATE glfw)
target_link_libraries(Editor PRIVATE glad)
target_link_libraries(Editor PRIVATE glm)
target_link_libraries(Editor PRIVATE RayTracer)

target_include_directories(Editor PRIVATE Editor/vendor/ImGui)
target_include_directories(Editor PRIVATE Editor/vendor/ImGui/backends)
target_include_directories(Editor PRIVATE Editor/vendor/glad/include)
target_include_directories(Editor PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(Editor PRIVATE RayTracer/src)

target_include_directories(RayTracer PRIVATE Editor/vendor/ImGui)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets" DESTINATION ${CMAKE_BINARY_DIR}/bin)


target_precompile_headers(Editor PRIVATE ${PRECOMPILED_HEADER})

target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Configuring for Windows")
    target_compile_definitions(${PROJECT_NAME} PUBLIC "PLATFORM_WINDOWS=1")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Configuring for Linux")
    find_package(X11 REQUIRED)
    target_include_directories(Editor PRIVATE ${X11_INCLUDE_DIR})
    target_link_libraries(Editor PRIVATE ${X11_LIBRARIES})
    target_compile_definitions(${PROJECT_NAME} PUBLIC "PLATFORM_LINUX=1")
else()
    message(FATAL_ERROR "Unsupported operating system: ${CMAKE_SYSTEM_NAME}")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE "EDEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE "ERELEASE")
endif()