cmake_minimum_required(VERSION 4.0)
project(MinecraftP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(MinecraftP2 main.cpp
        Model/Player.cpp
        Model/World.cpp
        Utilities/Utils.cpp
        Utilities/Utils.hpp
        Model/Mob.cpp
        Model/Mob.hpp
        Model/Map.cpp
        Model/Map.hpp
        Model/Block.cpp
        Model/Block.hpp
        Model/Item.cpp
        Model/Item.hpp
        Model/Weapon.cpp
        Model/Weapon.hpp
        Model/Tool.cpp
        Model/Tool.hpp
        Model/Food.cpp
        Model/Food.hpp
        Model/Potion.cpp
        Model/Potion.hpp
        Model/Inventory.cpp
        Model/Inventory.hpp
)
