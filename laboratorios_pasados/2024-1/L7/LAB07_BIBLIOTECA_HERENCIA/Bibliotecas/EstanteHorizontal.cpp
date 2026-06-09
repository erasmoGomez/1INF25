//
// Created by USUARIO on 3/06/2026.
//

#include "EstanteHorizontal.hpp"



EstanteHorizontal::EstanteHorizontal(){
    inicializar();
}

int EstanteHorizontal::get_cantidad_novelas() const{
    return cantidad_novelas;
}

void EstanteHorizontal::set_cantidad_novelas(int cantidad_novelas){
    this->cantidad_novelas = cantidad_novelas;
}

void EstanteHorizontal::inicializar(){
    cantidad_novelas = 0;
}

EstanteHorizontal& EstanteHorizontal::operator=(const class EstanteHorizontal& eh){
    if (this != &eh){
        Estante::operator=(eh);
        this->cantidad_novelas = eh.get_cantidad_novelas();
    }
    return *this;
}

int EstanteHorizontal::calcular_alto_utilizado(){
    int alto = 0;
    for(int i = 0; i < cantidad_novelas; i++){
        alto += novelas[i].get_ancho();
    }
    return alto;
}

void EstanteHorizontal::posicionar_novelo_grafico_fisico(const Novela &novela, int alto_utilizado){
    char caracter = Utils::obtener_caracter_no_repetir();
    if (esta_vacio()) reservar_memoria_espacios();
    for (int i = 0; i < novela.get_ancho(); i++){
        for (int j = 0; j < novela.get_alto(); j++ ){
            pintar_horizontal(i, j, alto_utilizado, caracter);
        }
    }
}

bool EstanteHorizontal::novela_entra(const Novela& novela){
    int alto_utilizado = calcular_alto_utilizado();
    int anchura_max = get_anchura();
    int altura_max = get_altura();

    int alto = novela.get_alto();
    int ancho = novela.get_ancho();

    return (alto <= anchura_max) && (ancho <= (altura_max - alto_utilizado));
}

void EstanteHorizontal::operator+=(const class Novela& novela){
    novelas[cantidad_novelas] = novela;
    cantidad_novelas++;
    //ESTÁ CONFUSA LA PARTE DE PESO Y RATING D:
    //set_peso_actual(get_peso_actual() + novela.get_peso());
}

void EstanteHorizontal::imprimir_data_estante(ofstream& out) const{
    char *codigo = get_codigo();
    out << "CODIGO ESTANTE: " << codigo << endl;
    delete [] codigo;
    out << "ANCHURA X ALTURA: " << get_anchura() << " X " << get_altura() << endl;
    out << "TIPO: HORIZONTAL" << endl;
    out << "CANTIDAD DE LIBROS: " << get_cantidad_novelas() << endl;
    out << "PESO TOTAL: " << get_peso_actual() << endl;
    Utils::imprimir_linea(out, '-');
}

void EstanteHorizontal::imprimir_cabecera_novelas(ofstream& out) const{
    out << left << setw(13) << " CODIGO";
    out << left << setw(30) << "NOMBRE";
    out << left << setw(10) << "ANCHO";
    out << left << setw(9) << "ALTO";
    out << left << setw(10) << "RATING";
    out << endl;

}

void EstanteHorizontal::imprimir_novelas(ofstream& out) const{
    imprimir_cabecera_novelas(out);
    for (int i = 0; i < cantidad_novelas; i++){
        novelas[i].imprimir_data_novela(out);
    }
    Utils::imprimir_linea(out, '-');
}

void EstanteHorizontal::imprimir_informe_horizontal(ofstream& out) const{
    imprimir_data_estante(out);
    imprimir_grafico_fisico(out);
    imprimir_novelas(out);
}


void EstanteHorizontal::verificar_posicionar_novela_estante_horizontal(Novela& novela){
    if (!novela.is_colocado()){
        if (novela_entra(novela)){
            int alto_utilizado = calcular_alto_utilizado();
            novela.set_colocado(true);
            *this += novela;
            //SE USA EL alto_utilizado ANTES DE AGREGAR LA NOVELA PORQUE
            //SE PARTE DESDE LA POSICIÓN DEL LIBRO ANTERIOR AGREGADO
            posicionar_novelo_grafico_fisico(novela, alto_utilizado);
        }
    }

}




