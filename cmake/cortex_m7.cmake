# Name of the target
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m7)

set(MCPU_FLAGS "-mthumb -mcpu=cortex-m7")
set(VFP_FLAGS  "-mfloat-abi=hard -mfpu=fpv5-d16")

include (${CMAKE_CURRENT_LIST_DIR}/common_opt.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/toolchain.cmake)