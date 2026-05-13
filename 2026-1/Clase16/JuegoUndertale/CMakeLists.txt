cmake_minimum_required(VERSION 4.0)
project(JuegoUndertale)

set(CMAKE_CXX_STANDARD 20)

add_executable(JuegoUndertale main.cpp
        Fuentes/Personaje.cpp
        Fuentes/Personaje.hpp
        Fuentes/Utils.hpp
        Fuentes/Juego.cpp
        Fuentes/Juego.hpp
        Fuentes/Mapa.cpp
        Fuentes/Mapa.hpp
        Fuentes/Casilla.cpp
        Fuentes/Casilla.hpp
)
