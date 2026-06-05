cmake_minimum_required(VERSION 4.0)
project(Figuras)

set(CMAKE_CXX_STANDARD 20)

add_executable(Figuras main.cpp
        Bibliotecas/Figura.cpp
        Bibliotecas/Figura.hpp
        Bibliotecas/Triangulo.cpp
        Bibliotecas/Triangulo.hpp
        Bibliotecas/Cuadrado.cpp
        Bibliotecas/Cuadrado.hpp)
