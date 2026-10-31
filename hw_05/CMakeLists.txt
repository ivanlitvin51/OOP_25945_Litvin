cmake_minimum_required(VERSION 3.14)
project(hypo_project CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(hypo_lib)

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE hypo_lib)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
