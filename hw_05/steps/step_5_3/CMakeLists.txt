cmake_minimum_required(VERSION 3.14)
project(Step5_3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(hypo_lib)
add_subdirectory(tests)

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE hypo_lib)
