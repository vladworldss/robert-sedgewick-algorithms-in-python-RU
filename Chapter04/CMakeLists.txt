cmake_minimum_required(VERSION 2.8)
project(Chapter04)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

# используем для перегрузки типа Item в Item.h
add_definitions(-DUSE_CHAR_ITEM=1)

add_library(array_stack STATIC array_stack.c)
add_library(list_stack STATIC list_stack.c)
add_library(UnionFind STATIC UnionFind.c)
add_library(array_queue STATIC array_queue.c)
add_library(list_queue STATIC list_queue.c)


add_executable(ex4_2_array ex4_2.c )
add_executable(ex4_2_list ex4_2.c )
target_link_libraries(ex4_2_array array_stack)
target_link_libraries(ex4_2_list list_stack)


add_executable(ex4_3_array ex4_3.c )
add_executable(ex4_3_list ex4_3.c )
target_link_libraries(ex4_3_array array_stack)
target_link_libraries(ex4_3_list list_stack)


add_executable(ex4_7 ex4_7.c)
target_link_libraries(ex4_7 UnionFind)


add_executable(ex4_31_array ex4_31.c)
add_executable(ex4_31_list ex4_31.c)
target_link_libraries(ex4_31_array array_queue)
target_link_libraries(ex4_31_list list_queue)

add_executable(ex4_32 ex4_32.c)
target_link_libraries(ex4_32 array_queue)

add_executable(ex4_33 ex4_33.c)
target_link_libraries(ex4_33 list_queue)