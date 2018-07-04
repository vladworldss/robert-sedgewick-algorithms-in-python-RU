cmake_minimum_required(VERSION 2.8)
# Проверка версии CMake.
# Если версия установленой программы
# старее указаной, произайдёт аварийный выход.
project(Chapter03)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_EXE main.c)

add_library(avg STATIC ex3_2.c)
add_library(point STATIC ex3_3.c)

add_executable(main ${SOURCE_EXE})
target_link_libraries(main avg point m)
