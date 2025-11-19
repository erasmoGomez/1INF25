cmake_minimum_required(VERSION 3.31)
project(RuletaRusa)

set(CMAKE_CXX_STANDARD 20)

add_executable(RuletaRusa main.cpp
        src/Utils.hpp
        src/Jugador.cpp
        src/Jugador.hpp
        src/Deudor.cpp
        src/Deudor.hpp
        src/Pagador.cpp
        src/Pagador.hpp
        src/BibliotecaListaCircularDoble/Nodo.cpp
        src/BibliotecaListaCircularDoble/Nodo.hpp
        src/BibliotecaListaCircularDoble/ListaCircularDoble.cpp
        src/BibliotecaListaCircularDoble/ListaCircularDoble.hpp
        src/GestorRussianRoulette.cpp
        src/GestorRussianRoulette.hpp)
