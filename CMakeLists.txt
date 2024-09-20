cmake_minimum_required(VERSION 3.8)
project(app)

# Import toolchain
set(CROSS_COMPILER arm-none-eabi-)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cortex_m7.cmake)

# Build target
add_executable(app
    main.c
)
target_include_directories(app
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Post command
build_post(app)
