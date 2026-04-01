cmake_minimum_required(VERSION 4.1)
project(AplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicacionConBibEstatica main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp)
