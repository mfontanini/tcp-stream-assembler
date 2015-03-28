cmake_minimum_required(VERSION 2.8.1)
project(tcp-stream-assembler)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")


include(CheckCXX11Features)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_COMPILER_FLAGS}")

if(${CMAKE_BUILD_TOOL} MATCHES "(msdev|devenv|nmake)")
    add_definitions(/W2)
else ()
    add_definitions(-Wall)
endif()

enable_testing()
add_subdirectory(lib)
add_subdirectory(tests)
