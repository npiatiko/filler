cmake_minimum_required(VERSION 3.12)
project(filler C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)
add_executable(filler ${LIBA} main.c filler.h calc_distmap.c piece.c search_place.c)
link_libraries(libft/libft.a)