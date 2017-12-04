cmake_minimum_required(VERSION 3.8)
project(TicTacToe)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c minimaxAlum.c minimaxAlum.h tictactoe.c tictactoe.h)
add_executable(TicTacToe ${SOURCE_FILES})