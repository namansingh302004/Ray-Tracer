cmake_minimum_required(VERSION 3.20)

project(SimpleRayTracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SimpleRayTracer creating_image.cpp)
