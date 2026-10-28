cmake_minimum_required(VERSION 3.31)
project(Estantes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Estantes main.cpp
        src/Biblioteca.cpp
        src/Biblioteca.hpp
        src/Libro.cpp
        src/Libro.hpp
        src/Utils.hpp
        src/Estante.cpp
        src/Estante.hpp
        src/Espacio.cpp
        src/Espacio.hpp
        src/Enciclopedia.cpp
        src/Enciclopedia.hpp
        src/Novela.cpp
        src/Novela.hpp)
