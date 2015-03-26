cmake_minimum_required(VERSION 2.8.1)
project(tcp-stream-assembler)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

include(CheckCXX11Features)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_COMPILER_FLAGS}")

add_subdirectory(lib)
