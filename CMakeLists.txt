cmake_minimum_required(VERSION 3.20)
project(learning-gtest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_executable(app src/main.cpp)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests 
test/test.cpp
)

target_link_libraries(tests
  GTest::gmock
  GTest::gtest
)
gtest_discover_tests(tests)