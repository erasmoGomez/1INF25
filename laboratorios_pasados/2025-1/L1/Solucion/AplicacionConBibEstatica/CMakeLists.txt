cmake_minimum_required(VERSION 4.1)
project(AplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicacionConBibEstatica main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(AplicacionConBibEstatica PRIVATE Sobrecargas)
