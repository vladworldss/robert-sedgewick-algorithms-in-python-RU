cmake_minimum_required(VERSION 2.8)
# Проверка версии CMake.
# Если версия установленой программы
# старее указаной, произайдёт аварийный выход.
project(ex3.6)
set(SOURCE_EXE main.c)

#set(SOURCE_LIB avg.c)
#add_library(avg STATIC ${SOURCE_LIB})
#add_library(point STATIC point.c)
#add_library(sieve STATIC eratosthenes_sieve.c)

add_executable(main ${SOURCE_EXE})
#target_link_libraries(main avg point sieve)
