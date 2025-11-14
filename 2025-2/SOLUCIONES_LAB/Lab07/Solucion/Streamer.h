//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_STREAMER_H
#define SOLUCION_STREAMER_H

#include <fstream>

#define MAX_METRICS_COUNT 100

class Streamer {
private:
    int id;
    char *cuenta;
    int n_seguidores;
    char *categoria;

public:
    Streamer();

    ~Streamer();

    Streamer &operator=(const Streamer &other);

    int get_id() const;

    void set_id(int id);

    void get_cuenta(char *buffer) const;

    void set_cuenta(const char *buffer);

    int get_n_seguidores() const;

    void set_n_seguidores(int n);

    void get_categoria(char *buffer) const;

    void set_categoria(const char *buffer);

    void leer(std::ifstream &arch);

    std::ostream &imprimir(std::ostream &arch) const;
};


#endif //SOLUCION_STREAMER_H
