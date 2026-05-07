cmake_minimum_required(VERSION 4.0.2)
project(Solucion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solucion main.cpp
        Biblioteca/Hospital.cpp
        Biblioteca/Hospital.h)
