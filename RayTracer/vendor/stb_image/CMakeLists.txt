cmake_minimum_required(VERSION 3.10)
project(stb_image)

add_library(stb_image)
target_sources(stb_image PRIVATE stb_image_impl.cpp)