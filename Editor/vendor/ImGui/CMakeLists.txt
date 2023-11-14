cmake_minimum_required(VERSION 3.10)
project(ImGui)

set(headers
        imconfig.h
        imgui.h
        imgui_internal.h
        imstb_rectpack.h
        imstb_textedit.h
        imstb_truetype.h
        backends/imgui_impl_glfw.h
        backends/imgui_impl_opengl3.h
)

set(sources
        imgui.cpp
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp
        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_opengl3.cpp
)

add_library(ImGui STATIC ${headers} ${sources})
target_include_directories(ImGui PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(ImGui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ImGui PRIVATE ../glfw/include)
