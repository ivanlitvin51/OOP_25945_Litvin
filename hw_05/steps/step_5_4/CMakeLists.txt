cmake_minimum_required(VERSION 3.14)
project(Step5_4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Задание 5.IV: опция управления сборкой тестов
option(BUILD_TESTS "Build tests" ON)

add_subdirectory(hypo_lib)

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE hypo_lib)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
