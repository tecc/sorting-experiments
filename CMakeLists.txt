cmake_minimum_required(VERSION 3.16)
project(SE)

add_executable(SE main.cpp)

add_subdirectory(lib/hayai)
target_link_libraries(SE hayai_main)
target_include_directories(SE PRIVATE lib/hayai/src/)