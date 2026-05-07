cmake_minimum_required(VERSION 3.31)
project(SolucionLab05_2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(SolucionLab05_2025_1 main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/BibliotecaConductores.cpp
        Bibliotecas/BibliotecaConductores.hpp
        Bibliotecas/BibliotecaInfracciones.cpp
        Bibliotecas/BibliotecaInfracciones.hpp
)
