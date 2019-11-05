cmake_minimum_required(VERSION 3.15)
project(Uno)

set(CMAKE_CXX_STANDARD 14)

add_executable(Uno main.cpp Uno.h Uno.cpp UnoGame.h UnoGame.cpp Move.h)