cmake_minimum_required(VERSION 4.1)
project(CreacionLibreriaEstaticaUsandoOtra)

set(CMAKE_CXX_STANDARD 20)

# add_library solo va cuando se quiere generar la libreria estatica nueva
add_library(Sobrecargas STATIC Librerias/Sobrecargas.cpp)

add_executable(CreacionLibreriaEstaticaUsandoOtra main.cpp
        Librerias/Sobrecargas.cpp
        Librerias/Sobrecargas.hpp
        Librerias/Estructuras.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Librerias")

# el target_link_libraries debe incluir ambas librerias, la primera de AperturaArchivos y la nueva creada Sobrecargas
# target_link_libraries(CreacionLibreriaEstaticaUsandoOtra PRIVATE AperturaArchivos)

target_link_libraries(CreacionLibreriaEstaticaUsandoOtra PRIVATE AperturaArchivos Sobrecargas)