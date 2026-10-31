# ============================================================================
# Задание 5.II: Библиотека в отдельной поддиректории
# ============================================================================
cmake_minimum_required(VERSION 3.14)
project(Step5_2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем поддиректорию hypo_lib
add_subdirectory(hypo_lib)

# Создаем приложение
add_executable(main_app main.cpp)

# Связываем с библиотекой
target_link_libraries(main_app PRIVATE hypo_lib)
