//
// Created by USUARIO on 3/06/2026.
//

#include "EstanteVertical.hpp"

EstanteVertical::EstanteVertical(){
    inicializar();
}

int EstanteVertical::get_cantidad_enciplopedias() const{
    return cantidad_enciplopedias;
}

void EstanteVertical::set_cantidad_enciplopedias(int cantidad_enciplopedias){
    this->cantidad_enciplopedias = cantidad_enciplopedias;
}

void EstanteVertical::inicializar(){
    cantidad_enciplopedias = 0;
}

EstanteVertical& EstanteVertical::operator=(const class EstanteVertical& ev){
    if (this != &ev){
        Estante::operator=(ev);
        this->cantidad_enciplopedias = ev.get_cantidad_enciplopedias();
    }
    return *this;
}

int EstanteVertical::calcular_ancho_utilizado(){
    int ancho = 0;
    for(int i = 0; i < cantidad_enciplopedias; i++){
        ancho += enciclopedias[i].get_ancho();
    }
    return ancho;
}

void EstanteVertical::operator+=(const class Enciclopedia& enciclopedia){
    enciclopedias[cantidad_enciplopedias] = enciclopedia;
    cantidad_enciplopedias++;
    set_peso_actual(get_peso_actual() + enciclopedia.get_peso());
}



void EstanteVertical::posicionar_enciclopedia_grafico_fisico(const class Enciclopedia &enciclopedia, int ancho_utilizado){
    char caracter = Utils::obtener_caracter_no_repetir();
    if (esta_vacio()) reservar_memoria_espacios();
    for (int i = 0; i < enciclopedia.get_alto(); i++){
        for (int j = 0; j < enciclopedia.get_ancho(); j++){
            pintar_vertical(i, j, ancho_utilizado, caracter);
        }
    }
}

bool EstanteVertical::enciclopedia_entra(const Enciclopedia& enciclopedia){
    int ancho_utilizado = calcular_ancho_utilizado();
    int altura_max = get_altura();
    int anchura_max = get_anchura();

    int alto = enciclopedia.get_alto();
    int ancho = enciclopedia.get_ancho();

    return (alto <= altura_max) && (ancho <= (anchura_max - ancho_utilizado));
}

void EstanteVertical::verificar_posicionar_estante_vertical(Enciclopedia& enciclopedia){

    if (!enciclopedia.is_colocado()){
        if (enciclopedia_entra(enciclopedia)){
            int ancho_utilizado = calcular_ancho_utilizado();
            enciclopedia.set_colocado(true);
            *this += enciclopedia;
            posicionar_enciclopedia_grafico_fisico(enciclopedia, ancho_utilizado);
        }
    }

}

void EstanteVertical::imprimir_cabecera_enciclopedias(ofstream& out) const{
    out << left << setw(13) << " CODIGO";
    out << left << setw(30) << "NOMBRE";
    out << left << setw(10) << "ANCHO";
    out << left << setw(9) << "ALTO";
    out << left << setw(10) << "PESO";
    out << endl;
}

void EstanteVertical::imprimir_enciclopedias(ofstream& out) const{
    imprimir_cabecera_enciclopedias(out);
    for (int i = 0; i < cantidad_enciplopedias; i++){
        enciclopedias[i].imprimir_data_enciclopedia(out);
    }
    Utils::imprimir_linea(out, '-');
}

void EstanteVertical::imprimir_data_estante(ofstream& out) const{
    char *codigo = get_codigo();
    out << "CODIGO ESTANTE: " << codigo << endl;
    delete [] codigo;
    out << "ANCHURA X ALTURA: " << get_anchura() << " X " << get_altura() << endl;
    out << "TIPO: VERTICAL" << endl;
    out << "CANTIDAD DE LIBROS: " << get_cantidad_enciplopedias() << endl;
    out << "PESO TOTAL: " << get_peso_actual() << endl;
    Utils::imprimir_linea(out, '-');
}

void EstanteVertical::imprimir_informe_vertical(ofstream& out) const{
    imprimir_data_estante(out);
    imprimir_grafico_fisico(out);
    imprimir_enciclopedias(out);
}
