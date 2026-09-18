//
// Created by erasmo on 9/17/26.
//

#ifndef PUNTEROSGENERICOS_STREAMERS_HPP
#define PUNTEROSGENERICOS_STREAMERS_HPP
#include "../View/Reports.hpp"
void load_streamers(void *&streamers, const char * filename);

void load_comments(void *&comments, const char * filename);

void update_comments(void *streamers, void *comments);


#endif //PUNTEROSGENERICOS_STREAMERS_HPP
