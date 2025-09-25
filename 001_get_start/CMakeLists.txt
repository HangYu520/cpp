# cmake 最低版本
cmake_minimum_required(VERSION 3.11)

# 项目名
project(001_get_start)

# 获取目录下所有源文件并存在 SRC_LIST 中
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 创建可执行文件
add_executable(main main.cpp ${SRC_LIST})