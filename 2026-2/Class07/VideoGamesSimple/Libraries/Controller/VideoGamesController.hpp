//
// Created by erasmo on 9/2/26.
//

#ifndef VIDEOGAMES_VIDEOGAMESCONTROLLER_HPP
#define VIDEOGAMES_VIDEOGAMESCONTROLLER_HPP
#include "../Model/Players.hpp"
#include "../Utils/AuxiliaryFunctions.hpp"

void load_players(struct Players &, const char *, const char *);

void load_videgames(struct Players &);

void display_players(const struct Players &, const char *);

void calculate_print_stats(struct Players &);
#endif //VIDEOGAMES_VIDEOGAMESCONTROLLER_HPP
