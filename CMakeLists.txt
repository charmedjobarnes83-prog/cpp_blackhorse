cmake_minimum_required(VERSION 3.20)

project(black_horse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# exe 统一输出到 bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(black_horse main.cpp)

# 头文件统一从 head/ 查找
target_include_directories(black_horse PRIVATE ${CMAKE_SOURCE_DIR}/head)

target_compile_options(black_horse PRIVATE
    -finput-charset=UTF-8
    -fexec-charset=UTF-8
)