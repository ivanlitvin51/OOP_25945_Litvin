# Задание 5.1: Сборка библиотеки и исполняемого файла в одной директории
cmake_minimum_required(VERSION 3.14)
project(Step5_1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем статическую библиотеку из исходников hypo.cpp и hypo_mod.cpp
add_library(hypo_lib STATIC hypo.cpp hypo_mod.cpp)

# Собираем исполняемый файл
add_executable(main_app main.cpp)

# Подключаем библиотеку к исполняемому файлу
target_link_libraries(main_app PRIVATE hypo_lib)
