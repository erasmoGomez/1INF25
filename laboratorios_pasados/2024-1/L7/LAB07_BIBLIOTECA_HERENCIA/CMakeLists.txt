cmake_minimum_required(VERSION 4.0.2)
project(LAB07_BIBLIOTECA_HERENCIA)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB07_BIBLIOTECA_HERENCIA main.cpp
        Bibliotecas/Utils.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.hpp
        Bibliotecas/Enciclopedia.cpp
        Bibliotecas/Enciclopedia.hpp
        Bibliotecas/Novela.cpp
        Bibliotecas/Novela.hpp
        Bibliotecas/Biblioteca.cpp
        Bibliotecas/Biblioteca.hpp
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.hpp
        Bibliotecas/Espacio.cpp
        Bibliotecas/Espacio.hpp
        Bibliotecas/EstanteVertical.cpp
        Bibliotecas/EstanteVertical.hpp
        Bibliotecas/EstanteHorizontal.cpp
        Bibliotecas/EstanteHorizontal.hpp
        main.cpp)
