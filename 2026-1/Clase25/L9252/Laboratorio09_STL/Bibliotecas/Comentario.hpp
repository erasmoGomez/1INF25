//
// Created by erasmo on 6/23/26.
//

#ifndef LABORATORIO09_STL_COMENTARIO_HPP
#define LABORATORIO09_STL_COMENTARIO_HPP


class Comentario {
private:
    string canal;
    string comentario;
public:
    string get_canal() const;
    void set_canal(const string &canal);
    string get_comentario() const;
    void set_comentario(const string &comentario);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
    bool operator<(const Comentario &com) const;
};

void operator>>(ifstream &arch, class Comentario &com);
void operator<<(ofstream &arch, const class Comentario &com);


#endif //LABORATORIO09_STL_COMENTARIO_HPP