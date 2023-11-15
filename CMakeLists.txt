cmake_minimum_required(VERSION 3.10)
project(Editor)

set(CMAKE_CXX_STANDARD 23)
set(PRECOMPILED_HEADER Editor/src/rtpch.h)

add_subdirectory(Editor/vendor/ImGui)
add_subdirectory(Editor/vendor/glfw)
add_subdirectory(Editor/vendor/glad)
add_subdirectory(RayTracer)

add_executable(Editor Editor/src/main.cpp
        Editor/src/Window.cpp
        Editor/src/Window.h
        Editor/src/Editor.cpp
        Editor/src/Editor.h
        Editor/src/ImGui/ImGuiLayer.cpp
        Editor/src/ImGui/ImGuiLayer.h
)

target_link_libraries(Editor PRIVATE ImGui)
target_link_libraries(Editor PRIVATE glfw)
target_link_libraries(Editor PRIVATE glad)
target_link_libraries(Editor PRIVATE RayTracer)

target_include_directories(Editor PRIVATE Editor/vendor/ImGui)
target_include_directories(Editor PRIVATE Editor/vendor/ImGui/backends)
target_include_directories(Editor PRIVATE Editor/vendor/glad/include)
target_include_directories(Editor PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(Editor PRIVATE RayTracer/src)

target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

#if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
#    target_precompile_headers(RayTracing PRIVATE ${PRECOMPILED_HEADER})
#else()
#    set_source_files_properties(${PRECOMPILED_HEADER} PROPERTIES COMPILE_FLAGS "-x c++-header")
#    target_sources(RayTracing PRIVATE ${PRECOMPILED_HEADER})
#endif()

