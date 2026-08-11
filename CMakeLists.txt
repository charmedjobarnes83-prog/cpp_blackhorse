cmake_minimum_required(VERSION 3.20)

project(black_horse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(black_horse main.cpp)

target_compile_options(black_horse PRIVATE
    -finput-charset=UTF-8
    -fexec-charset=UTF-8
)