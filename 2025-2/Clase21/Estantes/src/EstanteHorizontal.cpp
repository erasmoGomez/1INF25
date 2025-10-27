//
// Created by Erasmo on 26/10/25.
//

#include "EstanteHorizontal.hpp"

EstanteHorizontal::EstanteHorizontal() {
    cantidad_novelas = 0;
}

EstanteHorizontal::EstanteHorizontal(const EstanteHorizontal& orig) {

}

EstanteHorizontal::~EstanteHorizontal() {

}

void EstanteHorizontal::leer(ifstream &input) {
    Estante::leer(input);
}

int EstanteHorizontal::get_espacios_restantes() {
    int alto_utilizado = 0;
    for (int i = 0; i < cantidad_novelas; i++)
        alto_utilizado += novelas[i].GetAncho();
    return alto_utilizado;
}

bool EstanteHorizontal::operator+=( const Novela &n) {
    int alto_libro = n.GetAlto();
    int ancho_libro = n.GetAncho();
    int alto_utilizado = get_espacios_restantes();
    if (alto_libro <= Estante::GetAnchura() and ancho_libro <= (Estante::GetAltura() - alto_utilizado)) {
        colocar_libro(alto_utilizado, n);
        return true;
    } else{
        return false;
    }


}

void EstanteHorizontal::colocar_libro(int alto_utilizado, const Novela &n) {
    //Pintar en Espacios
    for (int i = Estante::GetAltura() - alto_utilizado - 1; i > (Estante::GetAltura() - n.GetAncho() - alto_utilizado -1); i--) {
        for (int j = Estante::GetAnchura()-n.GetAlto(); j < Estante::GetAnchura(); j++) {
            Estante::setEspacioPos(i * Estante::GetAnchura() + j,i,j);
            Estante::setEspacioContenido(i * Estante::GetAnchura() + j, '*');
        }
    }
    //Actualizar estante con Novela
    novelas[cantidad_novelas] = n;
    cantidad_novelas++;
}

void EstanteHorizontal::pinta_estante(ofstream& output) const{
    imprime_linea(output, 50, '-');
    output << endl;
    for (int i = 0; i < GetAltura(); i++) {
        for (int j = 0; j < GetAnchura(); j++) {
            Estante::muestra_espacio(i, j, output);
            //output<<espacios[i * anchura + j];
        }
        output << endl;
    }
}

void EstanteHorizontal::mostrar(ofstream &output) const{
    imprime_linea(output, 50, '-');
    char buffer[40];
    GetCodigo(buffer);
    output << setw(15) << left << "Codigo Estante: " << setw(10) << buffer << setw(20) << "Novelas Agregadas: " << cantidad_novelas << endl;
    output << setw(15) << left << "Anchura del Estante: " << setw(5) << GetAnchura() << setw(15) << "Altura del Estante: " << GetAltura() << endl;

    pinta_estante(output);

    output << endl;
    output << setw(11) << "CODIGO" << setw(27) << "NOMBRE" << setw(8) << "ANCHO" << setw(5) << "ALTO" << endl;
    imprime_linea(output, 50, '.');
    for (int i = 0; i < cantidad_novelas; i++)
        output << novelas[i];
}

void EstanteHorizontal::setEstadoColocado(int index, bool estado) {
    novelas[index].SetColocado(estado);
}

void operator<<(ofstream& output,  const EstanteHorizontal &e) {
    e.mostrar(output);
}