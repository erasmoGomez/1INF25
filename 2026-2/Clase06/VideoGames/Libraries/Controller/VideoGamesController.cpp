//
// Created by erasmo on 9/2/26.
//

#include "VideoGamesController.hpp"

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
    players.codes = new int[n_players + 1]{};
    players.nicknames = new char *[n_players]{};
    players.ages = new int[n_players]{};
    players.countries = new char *[n_players]{};
    players.platforms = new char *[n_players]{};
    players.video_games = new char **[n_players]{};

    /// Paso de DATOS
    for (int i = 0; buffer_codes[i]; i++) {
        players.codes[i] = buffer_codes[i];
        players.nicknames[i] = buffer_nicknames[i];
        players.ages[i] = buffer_ages[i];
        players.countries[i] = buffer_countries[i];
        players.platforms[i] = buffer_platforms[i];
    }
}

int get_size(const struct Players &players) {
    int size = 0;
    for (size = 0; players.codes[size]; size++) {
    }
    return size;
}

int lookup(const int *source, int to_look) {
    for (int i = 0; source[i]; i++)
        if (source[i] == to_look) return i;
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

void add_videogame(ifstream &input, char ** &player_videogames, int &siz, int &capacity) {
    char *videogame = read_str(input);
    if (siz == capacity)
        allocate_inc_memory(player_videogames, siz, capacity);
    player_videogames[siz-1] = videogame;
    siz++;
    input.ignore(100, '\n');
}

void load_videogames_memoria_incremental(const struct Players &players, ifstream &input_videogames) {
    //const int n_players = get_size(players);
    int capacities[PLAYERS_SIZE]{};
    int sizes[PLAYERS_SIZE]{};
    //1001,Tekken 8,Fighting,239.9,27.7,PLAYING
    int code_read = 0, index = 0;
    while (true) {
        code_read = read_int(input_videogames);
        if (input_videogames.eof())break;
        input_videogames.ignore();
        index = lookup(players.codes, code_read);
        if (index != -1) {
            add_videogame(input_videogames, players.video_games[index], sizes[index], capacities[index]);
        } else
            input_videogames.ignore(200, '\n');
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
    for (int i = 0; players.codes[i]; ++i) {
        output_players << setw(10) << right << players.codes[i];
        output_players << setw(20) << players.nicknames[i];
        output_players << setw(20) << players.countries[i] << endl;
        //Imprimir Video Games
        if (char **videogames_player = players.video_games[i]) {
            for (int j = 0; videogames_player[j] != nullptr; ++j) {
                output_players << setw(10) << right << j + 1 << ") "
                               << setw(30) << left << videogames_player[j]
                               << '\n';
            }
        }
        else {
            output_players << setw(12) << ""
                           << "This player has no video games :("
                           << '\n';
        }
    }
}
