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

char **load_info_str(char *buffer_nickname, char *buffer_country, char *buffer_platform) {
    char **info_str = new char *[3]{};
    info_str[0] = buffer_nickname;
    info_str[1] = buffer_country;
    info_str[2] = buffer_platform;
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
    players.info_str = new char **[n_players]{};
    players.videogames = new char **[n_players]{};
    players.info_doubles = new double **[n_players]{};

    /// Paso de DATOS
    for (int i = 0; buffer_codes[i]; i++) {
        players.info_int[i] = load_info_int(buffer_codes[i], buffer_ages[i]);
        players.info_str[i] = load_info_str(buffer_nicknames[i], buffer_countries[i], buffer_platforms[i]);
        players.videogames[i] = nullptr;
        players.info_doubles[i] = nullptr;
    }
}


int lookup(int **source, int to_look) {
    for (int i = 0; source[i]; i++) {
        // ATERRIZAJE
        const int *arr = source[i];
        if (arr[0] == to_look) return i;
    }
    return -1;
}

void allocate_inc_memory(char ** &player_videogames,
                         double ** &player_stats,
                         int &siz,
                         int &capacity) {
    capacity += INC;
    if (player_videogames == nullptr) {
        player_videogames = new char *[capacity]{};
        player_stats = new double *[capacity]{};
        siz = 1;
    } else {
        char **aux = new char *[capacity]{};
        double **aux2 = new double *[capacity]{};
        for (int i = 0; i < siz; i++) {
            aux[i] = player_videogames[i];
            aux2[i] = player_stats[i];
        }
        delete [] player_videogames; //Rompo conexion a segundo nivel
        delete [] player_stats;
        player_videogames = aux; //Vuelvo a conectar a segundo nivel
        player_stats = aux2;
    }
}

double *read_player_stats(ifstream &input) {
    //1001,Tekken 8,Fighting,239.9,27.7,PLAYING
    double *stats = new double[2]{};
    input.ignore(50, ',');
    double played_hours = read_double(input, true);
    double achievement_percent = read_double(input, true);
    input.ignore(50, '\r');
    stats[0] = played_hours;
    stats[1] = achievement_percent;
    return stats;
}

void add_videogame_info(ifstream &input,
                        double ** &player_stats,
                        char ** &player_videogames,
                        int &siz,
                        int &capacity) {
    //1001,Dota 2,MOBA,90.7,77.7,COMPLETED
    char *videogame = read_str(input);
    double *stats = read_player_stats(input);
    if (siz == capacity)
        allocate_inc_memory(player_videogames,
                            player_stats,
                            siz,
                            capacity);
    player_videogames[siz - 1] = videogame;
    player_stats[siz - 1] = stats;
    siz++;
    input.ignore(100, '\n');
}

int get_size(const struct Players &players) {
    int i = 0;
    for (i = 0; players.info_int[i]; i++) {
    }
    return i;
}

void cut_videogames_stats(char **&videogames,
                          double **&info_double,
                          int siz) {
    char** aux_videogames = new char *[siz]{};
    double** aux_double = new double *[siz]{};
    for (int i = 0; i < siz; i++) {
        aux_double[i] = info_double[i];
        aux_videogames[i] = videogames[i];
    }
    delete [] info_double;
    delete [] videogames;
    info_double = aux_double;
    videogames = aux_videogames;
}

void cut_videogames(struct Players &players,
                    int *capacities,
                    int *sizes) {
    for (int i = 0; players.info_int[i]; i++) {
        cut_videogames_stats(players.videogames[i],
                             players.info_doubles[i],
                             sizes[i]);
    }
}

void load_videogames_memoria_incremental(struct Players &players, ifstream &input_videogames) {
    int capacities[PLAYERS_SIZE]{};
    int sizes[PLAYERS_SIZE]{};
    //1001,Tekken 8,Fighting,239.9,27.7,PLAYING
    int code_read = 0, index = 0;
    while (true) {
        code_read = read_int(input_videogames);
        if (input_videogames.eof())break;
        input_videogames.ignore();
        index = lookup(players.info_int, code_read);
        if (index != -1) {
            add_videogame_info(input_videogames,
                               players.info_doubles[index],
                               players.videogames[index],
                               sizes[index],
                               capacities[index]);
        } else
            input_videogames.ignore(200, '\n');
        //players.info_str[index] = info_str_player;
    }
    cut_videogames(players, capacities, sizes);
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

    //HACER TODAS LAS COMBINACIONES!
}

void display_players(const struct Players &players, const char *filename) {
    ofstream output_players;
    open_file_write(output_players, filename);
    output_players << fixed;
    output_players.precision(2);
    for (int i = 0; players.info_int[i]; ++i) {
        int *info_int_player = players.info_int[i];
        char **info_str_player = players.info_str[i];
        char **info_videogames_player = players.videogames[i];
        double **info_stats_player = players.info_doubles[i];
        output_players << setw(10) << right << info_int_player[0];
        output_players << setw(20) << right << info_str_player[0];
        output_players << setw(20) << right << info_str_player[1];
        output_players << setw(20) << right << info_str_player[2];
        output_players << setw(10) << info_int_player[1] << endl;
        //Imprimir Video Games
        if (info_videogames_player) {
            for (int j = 0; info_videogames_player[j] != nullptr; ++j) {
                double *info_doubles = info_stats_player[j];
                output_players << setw(10) << right << j + 1 << ") "
                        << setw(30) << left << info_videogames_player[j]
                        << setw(10) << left << info_doubles[0]
                        << setw(10) << left << info_doubles[1]
                        << '\n';
            }
        } else {
            output_players << setw(12) << ""
                    << "This player has no video games :("
                    << '\n';
        }
    }
}

double calculate_stats_by_player(double ** info_double) {
    double sum_average = 0;
    int n_videogames = 0;
    for (int i = 0; info_double[i] != nullptr; ++i) {
        double *info_stats = info_double[i];
        double promedio = (info_stats[0] + info_stats[1])/2;
        sum_average += promedio;
        n_videogames++;
    }

    return sum_average?sum_average/(double)n_videogames:0.0;
}

void calculate_print_stats(struct Players &players) {
    const int n_players = get_size(players);
    players.stats = new double[n_players];
    for (int i=0; i < n_players; i++) {
        players.stats[i] = calculate_stats_by_player(players.info_doubles[i]);
        cout<<fixed<<endl;
        cout<<i+1<<") "<<setw(6)<<setprecision(2)<<players.stats[i]<<endl;
    }
}
