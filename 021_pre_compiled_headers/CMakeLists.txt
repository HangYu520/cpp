cmake_minimum_required(VERSION 4.0)

project(021_pre_compiled_headers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(main main.cpp)

target_precompile_headers(main PRIVATE ${PROJECT_SOURCE_DIR}/src/pch.h) # PCH