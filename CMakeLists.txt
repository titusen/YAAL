cmake_minimum_required(VERSION 3.10.0)
project(YAAL VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
    
add_library(YAAL YAAL.hpp)
set_target_properties(YAAL PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

add_executable(
    ChunkAllocatorTest
    tests/ChunkAllocatorTest.cpp
)

target_link_libraries(ChunkAllocatorTest
    GTest::gtest_main
    YAAL
)

target_include_directories(
    ChunkAllocatorTest
    PUBLIC
    .
)

include(GoogleTest)
gtest_discover_tests(ChunkAllocatorTest)

FetchContent_MakeAvailable(googletest)