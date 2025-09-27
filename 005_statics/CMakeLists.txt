cmake_minimum_required(VERSION 3.11)

project(005_statics)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(main main.cpp ${SRC_LIST})