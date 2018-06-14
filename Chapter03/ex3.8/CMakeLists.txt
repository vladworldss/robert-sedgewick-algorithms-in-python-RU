cmake_minimum_required(VERSION 2.8)
# Проверка версии CMake.
# Если версия установленой программы
# старее указаной, произайдёт аварийный выход.

project(Chapter03)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_EXE main.c)
set(HEADERS ../point.h)
set(SOURCES ../point.c)

add_executable(${PROJECT_NAME} ${SOURCE_EXE} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} m)