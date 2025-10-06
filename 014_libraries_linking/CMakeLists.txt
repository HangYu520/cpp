cmake_minimum_required(VERSION 3.11)

project(014_libraries_linking)

#aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# 设置库输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 生成静态库
add_library(Log STATIC ${PROJECT_SOURCE_DIR}/src/Log.cpp)

# 寻找已经编译的静态库
#find_library(LIB_LOG Log ${PROJECT_SOURCE_DIR}/lib)

# 生成可执行文件
add_executable(main main.cpp)

# 链接静态库
target_link_libraries(main Log)