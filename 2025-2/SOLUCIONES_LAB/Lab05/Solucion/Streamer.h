//
// Created by Daniel Sanchez on 19/10/25.
//

#ifndef SOLUCION_STREAMER_H
#define SOLUCION_STREAMER_H

#include <fstream>

class Streamer {
public:
    Streamer();

    virtual ~Streamer();

    void get_cuenta(char *cstr) const;

    void set_cuenta(const char *cstr);

    long long get_tiempo_total() const;

    void set_tiempo_total(long long x);

    float get_promedio_espectadores() const;

    void set_promedio_espectadores(float x);

    int get_n_seguidores() const;

    void set_n_seguidores(int x);

    void get_categoria(char *cstr) const;

    void set_categoria(const char *cstr);

    void copiar(const Streamer &s);

    bool leer_streamer(std::ifstream &f);

    void mostrar_streamer(std::ostream &os);

private:
    char *cuenta;
    long long tiempo_total;
    float promedio_espectadores;
    int n_seguidores;
    char *categoria;
};


#endif //SOLUCION_STREAMER_H
