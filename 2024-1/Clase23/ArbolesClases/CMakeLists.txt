cmake_minimum_required(VERSION 3.26)
project(juego)

set(CMAKE_CXX_STANDARD 17)

add_executable(juego main.cpp
        Juego.hpp
        Casilla.hpp
        Mapa.hpp
        Mapa.cpp
        Casilla.cpp
        Utils.hpp
        Juego.cpp
        Heroe.hpp
        Heroe.cpp
        Mochila.cpp
        Mochila.hpp
        Item.cpp
        Item.hpp
        Consumible.cpp
        Consumible.hpp
        Armadura.cpp
        Armadura.hpp
        Arma.cpp
        Arma.hpp
        Nodo.cpp
        Nodo.hpp
        Equipo.cpp
        Equipo.hpp)
