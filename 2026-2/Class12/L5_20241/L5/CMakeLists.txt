cmake_minimum_required(VERSION 3.31)
project(L5)

set(CMAKE_CXX_STANDARD 20)

add_executable(L5 main.cpp
        src/utils.hpp
        src/BibliotecaGenerica.hpp
        src/BibliotecaGenerica.cpp
        src/FuncionesEnteros.hpp
        src/FuncionesEnteros.cpp
        src/FuncionesRegistros.hpp
        src/FuncionesRegistros.cpp)
