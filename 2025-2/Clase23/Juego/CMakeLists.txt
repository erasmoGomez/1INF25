cmake_minimum_required(VERSION 3.31)
project(Juego)

set(CMAKE_CXX_STANDARD 20)

add_executable(Juego main.cpp
        src/Heroe.cpp
        src/Heroe.hpp
        src/Utils.hpp
        src/Juego.cpp
        src/Juego.hpp
        src/Casilla.cpp
        src/Casilla.hpp
        src/Mapa.cpp
        src/Mapa.hpp
        src/Mochila.cpp
        src/Mochila.hpp
        src/Item.cpp
        src/Item.hpp
        src/Consumible.cpp
        src/Consumible.hpp
        src/Armadura.cpp
        src/Armadura.hpp
        src/Arma.cpp
        src/Arma.hpp
        src/Lista/NodoLista.cpp
        src/Lista/NodoLista.hpp
        src/Arbol/NodoArbol.cpp
        src/Arbol/NodoArbol.hpp
        src/Lista/EquipoLista.cpp
        src/Lista/EquipoLista.hpp
        src/Arbol/EquipoArbol.cpp
        src/Arbol/EquipoArbol.hpp)
