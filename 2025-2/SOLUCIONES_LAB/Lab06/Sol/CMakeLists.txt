cmake_minimum_required(VERSION 4.0)
project(Sol)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sol main.cpp Canal.cpp Categoria.cpp Comunes.cpp Etiqueta.cpp
        GestorCanales.cpp)
