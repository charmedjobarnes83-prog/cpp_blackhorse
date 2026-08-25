cmake_minimum_required(VERSION 3.20)

project(black_horse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 所有可执行文件统一输出到 bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 自动发现 code/ 下的 cpp 文件，并为每个文件生成同名可执行文件。
# 新增 cpp 后重新运行 CMake 配置即可，不需要修改本文件。
file(GLOB CPP_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/code/*.cpp")

foreach(CPP_FILE ${CPP_FILES})
    get_filename_component(TARGET_NAME ${CPP_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${CPP_FILE})
    target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/head)

    # 全链路统一 UTF-8（配合工作区终端 profile 的 chcp 65001；F5 调试管道也按 UTF-8 解读）
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${TARGET_NAME} PRIVATE
            -finput-charset=UTF-8
            -fexec-charset=UTF-8
        )
    endif()
endforeach()
