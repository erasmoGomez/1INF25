cmake_minimum_required(VERSION 4.0)
project(VideoGames)

set(CMAKE_CXX_STANDARD 20)

add_executable(VideoGames main.cpp
        Libraries/Model/Players.hpp
        Libraries/Utils/Utils.hpp
        Libraries/Controller/VideoGamesController.cpp
        Libraries/Controller/VideoGamesController.hpp
        Libraries/Utils/AuxiliaryFunctions.hpp
        Libraries/Utils/AuxiliaryFunctions.cpp)
