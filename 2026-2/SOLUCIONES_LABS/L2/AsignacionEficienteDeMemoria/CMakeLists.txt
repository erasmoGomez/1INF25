cmake_minimum_required(VERSION 4.0)
project(AsignacionEficienteDeMemoria)

set(CMAKE_CXX_STANDARD 20)

add_executable(AsignacionEficienteDeMemoria main.cpp
        Libraries/Utilities/Utils.hpp
        Libraries/Controller/Sales.cpp
        Libraries/Controller/Sales.hpp
        Libraries/View/Reports.cpp
        Libraries/View/Reports.hpp
        Libraries/Utilities/AuxiliaryFunctions.cpp
        Libraries/Utilities/AuxiliaryFunctions.hpp)
