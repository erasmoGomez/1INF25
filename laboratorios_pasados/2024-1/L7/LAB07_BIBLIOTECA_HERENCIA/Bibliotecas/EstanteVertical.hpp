//
// Created by USUARIO on 3/06/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESTANTEVERTICAL_HPP
#define LAB07_BIBLIOTECA_HERENCIA_ESTANTEVERTICAL_HPP

#include "Enciclopedia.hpp"
#include "Estante.hpp"

class EstanteVertical : public Estante{
private:
    Enciclopedia enciclopedias[MAX_ENCICLOPEDIAS];
    int cantidad_enciplopedias;

public:


    EstanteVertical();

    int get_cantidad_enciplopedias() const;
    void set_cantidad_enciplopedias(int cantidad_enciplopedias);

    void inicializar();
    EstanteVertical& operator= (const class EstanteVertical& ev);
    int calcular_ancho_utilizado();
    void operator+=(const class Enciclopedia& enciclopedia);
    void posicionar_enciclopedia_grafico_fisico(const Enciclopedia &enciclopedia, int ancho_utilizado);
    bool enciclopedia_entra(const Enciclopedia& enciclopedia);
    void verificar_posicionar_estante_vertical(Enciclopedia& enciclopedia);
    void imprimir_cabecera_enciclopedias(ofstream& out) const;
    void imprimir_enciclopedias(ofstream& out) const;
    void imprimir_data_estante(ofstream& out) const;
    void imprimir_informe_vertical(ofstream& out) const;
};


#endif //LAB07_BIBLIOTECA_HERENCIA_ESTANTEVERTICAL_HPP