cmake_minimum_required(VERSION 3.13)
project(double_pointeur C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(double_pointeur main.c matrice.c matrice.h circ_liste.c circ_liste.h joseph.c matrix_compute.c pointer_sort.c pointer_sort.h)