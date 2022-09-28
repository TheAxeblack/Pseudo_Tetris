cmake_minimum_required(VERSION 3.13)
project(Pseudo_Tetris C)

set(CMAKE_C_STANDARD 90)

add_executable(Pseudo_Tetris main.c tetris.c tetris.h game.c menu.c menu.h save.c save.h)
