//
// Created by erasmo on 10/7/26.
//

#include "Map.hpp"

Map::Map() {
    ancho = 40;
    largo = 40;
    altura = 40;
    n_players = 0;
    n_mobs = 0;
    bloques = new Block[ancho*largo];
}
