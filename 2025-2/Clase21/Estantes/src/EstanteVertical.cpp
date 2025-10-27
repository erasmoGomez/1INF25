//
// Created by Erasmo on 26/10/25.
//

#include "EstanteVertical.hpp"

EstanteVertical::EstanteVertical() {
    cantidad_enciclopedias = 0;
}

EstanteVertical::EstanteVertical(const EstanteVertical& orig) {

}

EstanteVertical::~EstanteVertical() {

}

void EstanteVertical::leer(ifstream &input) {
    Estante::leer(input);
}

int EstanteVertical::get_espacios_restantes() {
    int ancho_utilizado = 0;
    for (int i = 0; i < cantidad_enciclopedias; i++)
        ancho_utilizado += enciclopedias[i].GetAncho();
    return ancho_utilizado;
}

bool EstanteVertical::operator+=(const Enciclopedia &e) {
    int alto_libro = e.GetAlto();
    int ancho_libro = e.GetAncho();
    int ancho_utilizado = get_espacios_restantes();
    if (alto_libro <= Estante::GetAltura() and ancho_libro <= (Estante::GetAnchura() - ancho_utilizado)) {
        colocar_libro(ancho_utilizado, e);
        return true;
    } else
        return false;
}

void EstanteVertical::colocar_libro(int ancho_utilizado, const Enciclopedia& e) {
    //Pintar en Espacios
    for (int i = Estante::GetAltura() - 1; i > (Estante::GetAltura()  - e.GetAlto()-1); i--) {
        for (int j = ancho_utilizado; j < ancho_utilizado + e.GetAncho(); j++) {
            Estante::setEspacioPos(i * Estante::GetAnchura() + j,i,j);
            Estante::setEspacioContenido(i * Estante::GetAnchura() + j, '*');
        }
    }
    //Actualizar estante con Enciclipedia
    enciclopedias[cantidad_enciclopedias] = e;
    cantidad_enciclopedias++;
}

void EstanteVertical::pinta_estante(ofstream& output) const{
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

void EstanteVertical::mostrar(ofstream &output) const{
    imprime_linea(output, 50, '-');
    char buffer[40];
    GetCodigo(buffer);
    output << setw(15) << left << "Codigo Estante: " << setw(10) << buffer << setw(20) << "Enciclopedias Agregadas: " << cantidad_enciclopedias << endl;
    output << setw(15) << left << "Anchura del Estante: " << setw(5) << GetAnchura() << setw(15) << "Altura del Estante: " << GetAltura() << endl;

    pinta_estante(output);

    output << endl;
    output << setw(11) << "CODIGO" << setw(27) << "NOMBRE" << setw(8) << "ANCHO" << setw(5) << "ALTO" << endl;
    imprime_linea(output, 50, '.');
    for (int i = 0; i < cantidad_enciclopedias; i++)
        output << enciclopedias[i];
}

void EstanteVertical::setEstadoColocado(int index, bool estado) {
    enciclopedias[index].SetColocado(estado);
}

void operator<<(ofstream& output,  const EstanteVertical &e) {
    e.mostrar(output);
}