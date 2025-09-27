cmake_minimum_required(VERSION 3.31)
project(Juego)

set(CMAKE_CXX_STANDARD 20)

add_executable(Juego main.cpp
        src/Heroe.cpp
        src/Heroe.hpp
        src/Utils.hpp
        src/Juego.cpp
        src/Juego.hpp)
