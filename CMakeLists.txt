cmake_minimum_required(VERSION 3.8)

project(app)

#############################
# Set common compile options
#############################
set(CC_FLAGS   "-O2 -Wall -Werror -Wextra -Werror -fpie -fno-plt ")
#set(CC_FLAGS   "${CC_FLAGS} -mno-pic-data-is-text-relative -msingle-pic-base")
set(SPEC_FLAGS "--specs=nosys.specs")
set(LD_FLAGS   "-Wl,-e app_entry -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/app.map -Wl,-T ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linker.ld -Wl,-nostdlib -nostartfiles")

#############################
# Import toolchain
#############################
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/cortex_m7.cmake)

#######################
# Build target
#######################
add_executable(app
    main.c
)

#######################
# Post command
#######################
add_custom_command(
    TARGET app
    POST_BUILD
    COMMAND ${OBJCOPY} -O binary app appmod.bin
    COMMAND ${OBJDUMP} -d app > app.lst
)