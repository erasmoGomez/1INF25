cmake_minimum_required(VERSION 4.0)
project(Laboratorio09_STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio09_STL main.cpp
        Bibliotecas/Categoria.cpp
        Bibliotecas/Categoria.hpp
        Bibliotecas/Comentario.cpp
        Bibliotecas/Comentario.hpp
        Bibliotecas/Etiqueta.cpp
        Bibliotecas/Etiqueta.hpp
        Bibliotecas/SistemaDeGestion.cpp
        Bibliotecas/SistemaDeGestion.hpp
        Bibliotecas/Streamer.cpp
        Bibliotecas/Streamer.hpp)
