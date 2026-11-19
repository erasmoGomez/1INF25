cmake_minimum_required(VERSION 3.20)
project(MinecraftSurvivalSTL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MinecraftSurvivalSTL
    main.cpp
    model/Utils.cpp
    model/MiningStack.cpp
    model/VillagerQueue.cpp
    model/Region.cpp
    model/WorldGraph.cpp
    model/CsvRecords.cpp
    model/DataLoader.cpp
    model/GestorJuego.cpp
    view/GameView.cpp
)
target_include_directories(MinecraftSurvivalSTL PRIVATE model view)
target_compile_definitions(MinecraftSurvivalSTL PRIVATE PROJECT_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
