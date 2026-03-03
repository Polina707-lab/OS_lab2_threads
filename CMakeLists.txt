cmake_minimum_required(VERSION 3.20)
project(lab_threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Аналог "Debug Multithreaded" из методички:
# Debug -> /MTd, Release -> /MT
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

enable_testing()
add_executable(lab_tests tests/test_core.cpp)
target_link_libraries(lab_tests PRIVATE lab_lib)
add_test(NAME CoreTests COMMAND lab_tests)