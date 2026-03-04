cmake_minimum_required(VERSION 3.20)
project(lab_threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if (MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


add_library(lab_lib
  src/core.cpp
  src/threads.cpp
  src/win_error.cpp
)
target_include_directories(lab_lib PUBLIC src)


add_executable(lab_threads src/main.cpp)
target_link_libraries(lab_threads PRIVATE lab_lib)


include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab_tests tests/test_core_gtest.cpp)
target_link_libraries(lab_tests PRIVATE lab_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab_tests)