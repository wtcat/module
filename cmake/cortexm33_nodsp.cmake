# Name of the target
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m33)

set(MCPU_FLAGS "-mthumb -mcpu=cortex-m33+nodsp -mabi=aapcs")
set(VFP_FLAGS  "-mfpu=fpv5-sp-d16 -mfloat-abi=hard")

include (${CMAKE_CURRENT_LIST_DIR}/common_opt.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/toolchain.cmake)
