//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESTANTEHORIZONTAL_HPP
#define LAB07_BIBLIOTECA_HERENCIA_ESTANTEHORIZONTAL_HPP

#include "Novela.hpp"
#include "Estante.hpp"

class EstanteHorizontal : public Estante{
private:
    Novela novelas[MAX_NOVELAS];
    int cantidad_novelas;

public:


    EstanteHorizontal();

    int get_cantidad_novelas() const;
    void set_cantidad_novelas(int cantidad_novelas);

    void inicializar();
    EstanteHorizontal& operator=(const class EstanteHorizontal& eh);
    int calcular_alto_utilizado();


    void posicionar_novelo_grafico_fisico(const Novela &novela, int alto_utilizado);
    bool novela_entra(const Novela& novela);
    void verificar_posicionar_novela_estante_horizontal(Novela& novela);
    void operator+= (const class Novela &novela);

    void imprimir_data_estante(ofstream& out) const;


    void imprimir_cabecera_novelas(ofstream& out) const;
    void imprimir_novelas(ofstream& out) const;
    void imprimir_informe_horizontal(ofstream& out) const;
};


#endif //LAB07_BIBLIOTECA_HERENCIA_ESTANTEHORIZONTAL_HPP