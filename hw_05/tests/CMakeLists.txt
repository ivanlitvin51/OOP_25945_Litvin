# ============================================================================
# CMakeLists.txt для сборки Google Tests (Задания 5.III, 5.IV, 5.V)
# ============================================================================

# Отключаем строгую проверку сертификатов для скачивания архива googletest на Windows
set(CMAKE_TLS_VERIFY 0)

# Подключаем стандартный модуль CMake FetchContent для загрузки внешних библиотек
include(FetchContent)

# Объявляем зависимость от Google Test из официального репозитория на GitHub
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    TLS_VERIFY FALSE
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Для Windows: настраиваем общую CRT, чтобы параметры компиляции совпадали
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Скачиваем и добавляем исходники Google Test в дерево сборки CMake
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл для запуска тестов
add_executable(hypo_tests test_hypo.cpp)

# Подключаем к тестам:
# 1) Нашу библиотеку hypo_lib (чтобы видеть hypo.hpp и hypo_mod.hpp)
# 2) gtest_main из Google Test (содержит стандартную функцию main для запуска тестов)
target_link_libraries(hypo_tests PRIVATE
    hypo_lib
    gtest_main
)

# Подключаем модуль GoogleTest для интеграции с CTest (запуск тестов через команду ctest)
include(GoogleTest)
gtest_discover_tests(hypo_tests)
