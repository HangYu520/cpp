cmake_minimum_required(VERSION 3.11)

project(001_get_start)

aux_source_directory(. SRC_LIST)

add_executable(main ${SRC_LIST})