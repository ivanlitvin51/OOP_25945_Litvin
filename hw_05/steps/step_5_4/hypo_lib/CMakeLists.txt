# Библиотека в отдельной поддиректории (Задание 5.II)
add_library(hypo_lib STATIC hypo.cpp hypo_mod.cpp)

# Делаем текущую папку доступной для #include "hypo.hpp" в других таргетах
target_include_directories(hypo_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
