cmake_minimum_required(VERSION 3.10)
project(RayTracing)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(vendor/ImGui)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

add_executable(RayTracing main.cpp)
target_link_libraries(RayTracing PRIVATE ImGui)
target_link_libraries(RayTracing PRIVATE glfw)
target_link_libraries(RayTracing PRIVATE glad)

target_include_directories(RayTracing PRIVATE vendor/imgui)
target_include_directories(RayTracing PRIVATE vendor/imgui/backends)
target_include_directories(RayTracing PRIVATE vendor/glad/include)
target_include_directories(RayTracing PRIVATE ${GLFW_INCLUDE_DIRS})

target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")