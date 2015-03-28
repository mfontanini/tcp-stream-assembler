include_directories(${PROJECT_SOURCE_DIR}/lib/include)

# Find pthread library
find_package(Threads REQUIRED)

link_libraries(
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARY} 
    ${CMAKE_THREAD_LIBS_INIT}
    tcp_stream_assembler
)

# Add tests target
add_custom_target(
    tests DEPENDS
    segment_generators_test
)


# Test executables

add_executable(segment_generators_test EXCLUDE_FROM_ALL segment_generators_test.cpp)


# Actual tests
ADD_TEST(segment_generators segment_generators_test)
