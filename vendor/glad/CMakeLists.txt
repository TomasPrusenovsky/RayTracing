cmake_minimum_required(VERSION 3.26)
project(glad)

set(headers
        include/glad/glad.h
        include/KHR/khrplatform.h
)

set(sources
        glad.c
)

add_library(glad STATIC ${headers} ${sources})
target_include_directories(glad PRIVATE include)