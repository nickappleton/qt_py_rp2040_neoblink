cmake_minimum_required(VERSION 3.12)

if(NOT DEFINED ENV{PICO_EXAMPLES_PATH} OR NOT DEFINED ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "you must set both the PICO_EXAMPLES_PATH and PICO_SDK_PATH environment variables")
endif()

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(neo_example C CXX ASM)

pico_sdk_init()

add_executable(blink blink.c)

# Create a directory in our build location to put generated artefacts
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/autogen)

# Generate the ws2812 controller PIO header from the pico examples.
pico_generate_pio_header(blink $ENV{PICO_EXAMPLES_PATH}/pio/ws2812/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/autogen)

target_link_libraries(blink hardware_pio pico_stdlib)

pico_add_extra_outputs(blink)

