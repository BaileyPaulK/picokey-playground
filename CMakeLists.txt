cmake_minimum_required(VERSION 3.12)
set(NAME picokey)
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
#include($ENV{PICO_SDK_PATH}/lib/tinyusb/hw/bsp/family_support.cmake)

project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${NAME}
    src/main.cpp # <-- Add source files here!
    src/usb_descriptors.c
    src/button.cpp
    src/digitalPin.cpp
    src/gamepad_controller.cpp
)

target_include_directories(${NAME} PRIVATE 
    src
)

# Include required libraries
#include($ENV{PICO_SDK_PATH})
target_link_libraries(${NAME}
    pico_stdlib
    pico_stdio
    tinyusb_device 
    tinyusb_board
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)