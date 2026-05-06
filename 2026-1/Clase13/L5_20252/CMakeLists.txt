cmake_minimum_required(VERSION 4.0)
project(L5_20252)

set(CMAKE_CXX_STANDARD 20)

add_executable(L5_20252 main.cpp
        Librerias/BibliotecaGenerica.cpp
        Librerias/BibliotecaGenerica.hpp
        Librerias/Utils.hpp
        Librerias/ListaConEnteros.cpp
        Librerias/ListaConEnteros.hpp
        Librerias/ListaConRegistros.hpp
        Librerias/ListaConRegistros.cpp)
