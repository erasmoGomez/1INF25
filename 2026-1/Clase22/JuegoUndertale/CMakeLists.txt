cmake_minimum_required(VERSION 4.0)
project(JuegoUndertale)

set(CMAKE_CXX_STANDARD 20)

add_executable(JuegoUndertale main.cpp
        Fuentes/Personaje.cpp
        Fuentes/Personaje.hpp
        Fuentes/Utils2.hpp
        Fuentes/Juego.cpp
        Fuentes/Juego.hpp
        Fuentes/Mapa.cpp
        Fuentes/Mapa.hpp
        Fuentes/Casilla.cpp
        Fuentes/Casilla.hpp
        Fuentes/Utils.cpp
        Fuentes/Utils.hpp
        Fuentes/Guerrero.cpp
        Fuentes/Guerrero.hpp
        Fuentes/Mago.cpp
        Fuentes/Mago.hpp
        Fuentes/Arma.cpp
        Fuentes/Arma.hpp
        Fuentes/Item.cpp
        Fuentes/Item.hpp
        Fuentes/Armadura.cpp
        Fuentes/Armadura.hpp
        Fuentes/Consumible.cpp
        Fuentes/Consumible.hpp
        Fuentes/Mochila.cpp
        Fuentes/Mochila.hpp
        Fuentes/Lista/NodoLista.cpp
        Fuentes/Lista/NodoLista.hpp
        Fuentes/Lista/EquipoLista.cpp
        Fuentes/Lista/EquipoLista.hpp
        Fuentes/Arbol/NodoArbol.cpp
        Fuentes/Arbol/NodoArbol.hpp
        Fuentes/Arbol/EquipoArbol.cpp
        Fuentes/Arbol/EquipoArbol.hpp
        Fuentes/Grafo/NodoVertice.cpp
        Fuentes/Grafo/NodoVertice.hpp
        Fuentes/Grafo/EquipoGrafo.cpp
        Fuentes/Grafo/EquipoGrafo.hpp
)
