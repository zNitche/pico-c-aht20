file(GLOB PICO_AHT20_EXECS ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

cmake_minimum_required(VERSION 3.27)

project(pico_aht20 VERSION 0.0.1)

add_library(pico_aht20 INTERFACE)

target_link_libraries(pico_aht20 INTERFACE
  pico_stdlib
  hardware_i2c
)

target_include_directories(pico_aht20 INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include")
target_sources(pico_aht20 INTERFACE ${PICO_AHT20_EXECS})
