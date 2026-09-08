//
// Created by erasmo on 9/2/26.
//

#include "VideoGamesController.hpp"

int *load_info_int(int buffer_code, int buffer_ages) {
    int *info_int = new int[2]{};
    info_int[0] = buffer_code;
    info_int[1] = buffer_ages;
    return info_int;
}

char ***load_info_str(char *buffer_nickname, char *buffer_country, char *buffer_platform) {
    char ***info_str = new char **[4]{};
    for (int i = 0; i < 4; i++) {
        info_str[i] = new char *[2]{};
    }
    char **nickname = info_str[0];
    char **country = info_str[1];
    char **platform = info_str[2];
    nickname[0] = buffer_nickname;
    country[0] = buffer_country;
    platform[0] = buffer_platform;
    info_str[3] = nullptr;
    return info_str;
}

void load_players_memoria_exacta(struct Players &players,
                                 ifstream &input_players) {
    // Buffers
    int buffer_codes[PLAYERS_SIZE]{}, buffer_ages[PLAYERS_SIZE]{};
    char *buffer_nicknames[PLAYERS_SIZE]{}, *buffer_countries[PLAYERS_SIZE]{}, *buffer_platforms[PLAYERS_SIZE]{};
    int n_players = 0;
    //1482,PotatoSlayer985,23,Peru,PC
    int code = 0;
    while (true) {
        input_players >> code;
        if (input_players.eof()) break;
        input_players.ignore();
        buffer_codes[n_players] = code;
        buffer_nicknames[n_players] = read_str(input_players);
        buffer_ages[n_players] = read_int(input_players, true);
        buffer_countries[n_players] = read_str(input_players);
        buffer_platforms[n_players] = read_str(input_players, '\r');
        n_players++;
    }
    // Reserva de memoria EXACTA
    //players.codes = buffer_code; GRAVE ERROR DE CONCEPTO
    players.info_int = new int *[n_players + 1]{};
    players.info_str = new char ***[n_players]{};
    players.info_stats = new double *[n_players]{};

    /// Paso de DATOS
    for (int i = 0; buffer_codes[i]; i++) {
        players.info_int[i] = load_info_int(buffer_codes[i], buffer_ages[i]);
        players.info_str[i] = load_info_str(buffer_nicknames[i], buffer_countries[i], buffer_platforms[i]);
    }
}


int lookup(int **source, int to_look) {
    for (int i = 0; source[i]; i++) {
        if (const int *arr = source[i]; arr[0] == to_look) return i;
    }
    return -1;
}

void allocate_inc_memory(char ** &player_videogames, int &siz, int &capacity) {
    capacity += INC;
    if (player_videogames == nullptr) {
        player_videogames = new char *[capacity]{};
        siz = 1;
    } else {
        char **aux = new char *[capacity]{};
        for (int i = 0; i < siz; i++) aux[i] = player_videogames[i];
        delete [] player_videogames; //Rompo conexion a segundo nivel
        player_videogames = aux; //Vuelvo a conectar a segundo nivel
    }
}

double *read_player_stats(ifstream &input) {
    //1001,Tekken 8,Fighting,239.9,27.7,PLAYING
    double *stats = new double[2]{};
    input.ignore(50, ',');
    double played_hours = read_double(input, true);
    double achievement_percent = read_double(input, true);
    input.ignore(50, '\n');
    stats[0] = played_hours;
    stats[1] = achievement_percent;
    return stats;
}

void add_videogame_info(ifstream &input, double *&player_stats, char ** &player_videogames, int &siz, int &capacity) {
    char *videogame = read_str(input);
    //double *stats = read_player_stats(input);
    if (siz == capacity)
        allocate_inc_memory(player_videogames, siz, capacity);
    player_videogames[siz - 1] = videogame;
    //player_stats = stats;
    siz++;
    input.ignore(100, '\n');
}

int get_size(const struct Players &players) {
    int i = 0;
    for (i = 0; players.info_int[i]; i++) {
    }
    return i;
}

void load_videogames_memoria_incremental(struct Players &players, ifstream &input_videogames) {
    int capacities[PLAYERS_SIZE]{};
    int sizes[PLAYERS_SIZE]{};
    //1001,Tekken 8,Fighting,239.9,27.7,PLAYING
    int code_read = 0, index = 0;
    int n_players = get_size(players);
    players.info_stats = new double *[n_players]{};
    while (true) {
        code_read = read_int(input_videogames);
        if (input_videogames.eof())break;
        input_videogames.ignore();
        index = lookup(players.info_int, code_read);
        char ***info_str_player = players.info_str[index];
        double *info_stats_player = players.info_stats[index];
        if (index != -1) {
            add_videogame_info(input_videogames, info_stats_player, info_str_player[3], sizes[index],
                               capacities[index]);
        } else
            input_videogames.ignore(200, '\n');
        //players.info_str[index] = info_str_player;
    }
}


void load_players(struct Players &players,
                  const char *players_filename,
                  const char *videogames_filename) {
    ifstream input_players;
    open_file_read(input_players, players_filename);

    ifstream input_videogames;
    open_file_read(input_videogames, videogames_filename);
    // En primer Nivel vamos a usar Memoria Exacta
    load_players_memoria_exacta(players, input_players);
    // A segundo Nivel vamos a usar Memoria Incremental
    load_videogames_memoria_incremental(players, input_videogames);
}

void display_players(const struct Players &players, const char *filename) {
    ofstream output_players;
    open_file_write(output_players, filename);
    for (int i = 0; players.info_int[i]; ++i) {
        int *info_int_player = players.info_int[i];
        char ***info_str_player = players.info_str[i];
        //double *info_stats_player = players.info_stats[i];
        char **nickname_arr = info_str_player[0];
        char **country_arr = info_str_player[1];
        char **platform_arr = info_str_player[2];
        char **videogames_arr = info_str_player[3];
        output_players << setw(10) << right << info_int_player[0];
        output_players << setw(20) << right << nickname_arr[0];
        output_players << setw(20) << right << country_arr[0];
        output_players << setw(20) << right << platform_arr[0];
        output_players << setw(10) << info_int_player[1] << endl;
        //Imprimir Video Games
        if (videogames_arr) {
            for (int j = 0; videogames_arr[j] != nullptr; ++j) {
                output_players << setw(10) << right << j + 1 << ") "
                        << setw(30) << left << videogames_arr[j]
                        << '\n';
            }
        } else {
            output_players << setw(12) << ""
                    << "This player has no video games :("
                    << '\n';
        }
    }
}

void calculate_stats(const struct Players &players) {
}
