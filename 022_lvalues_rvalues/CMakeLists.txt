cmake_minimum_required(VERSION 4.0)

project(022_lvalues_rvalues)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(main main.cpp ${SRC_LIST})