cmake_minimum_required(VERSION 4.0)
project(Solucion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solucion main.cpp
        Biblioteca/BibliotecaGenerica.cpp
        Biblioteca/BibliotecaGenerica.h
        Biblioteca/BibliotecaEnteros.cpp
        Biblioteca/BibliotecaEnteros.h
        Biblioteca/BibliotecaRegistros.cpp
        Biblioteca/BibliotecaRegistros.h)
