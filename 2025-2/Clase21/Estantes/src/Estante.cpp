//
// Created by Erasmo on 22/10/25.
//

#include "Estante.hpp"

Estante::Estante() {
    codigo = nullptr;
    cantidad_libros = 0;
    espacios = nullptr;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
    delete codigo;
    delete[] espacios;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Estante::GetCodigo(char*codigo) const {
    if (this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Estante::leer(ifstream& input) {
    char _codigo[10], c;
    //AAA, 6, 4, 3
    input.getline(_codigo, 10, ',');
    input >> anchura >> c>>altura;
    input.get();
    input>>peso_soportado;
    SetCodigo(_codigo);
    //Importante
    this->espacios = new Espacio[anchura * altura]{};
}

void Estante::imprime_linea(ofstream& output, int n, char c) const{
    output << setfill(c) << setw(n) << " " << endl;
    output << setfill(' ');
}

void Estante::pinta_estante(ofstream& output) const{
    imprime_linea(output, 50, '-');
    output << endl;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < anchura; j++) {
            output<<espacios[i * anchura + j]; // output<<espacio
        }
        output << endl;
    }
}

//void Estante::mostrar(ofstream &output) const{
//    imprime_linea(output, 50, '-');
//    output << setw(15) << left << "Codigo Estante: " << setw(10) << codigo << setw(20) << "Cantidad de Libros: " << cantidad_libros << endl;
//    output << setw(15) << left << "Anchura del Estante: " << setw(5) << anchura << setw(15) << "Altura del Estante: " << altura << endl;
//
//    pinta_estante(output);
//
//    output << endl;
//    output << setw(11) << "CODIGO" << setw(27) << "NOMBRE" << setw(8) << "ANCHO" << setw(5) << "ALTO" << endl;
//    imprime_linea(output, 50, '.');
//    for (int i = 0; i < cantidad_libros; i++)
//        output << libros[i];
//}

int Estante::get_espacios_restantes() {
    int ancho_utilizado = 0;
    for (int i = 0; i < cantidad_libros; i++)
        ancho_utilizado += libros[i].GetAncho();
    return ancho_utilizado;
}

void Estante::colocar_libro(int ancho_utilizado, Libro&l) {
    //Pintar en Espacios
    for (int i = altura - 1; i > (altura - l.GetAlto()-1); i--) {
        for (int j = ancho_utilizado; j < ancho_utilizado + l.GetAncho(); j++) {
            espacios[i * anchura + j].SetPosX(i);
            espacios[i * anchura + j].SetPosY(j);
            espacios[i * anchura + j].SetContenido('*');
        }
    }
    //Actualizar Libro
    l.SetColocado(true);
    //Actualizar estante con Libro
    libros[cantidad_libros] = l;
    cantidad_libros++;
}

bool Estante::operator+=(Libro&l) {
    int alto_libro = l.GetAlto();
    int ancho_libro = l.GetAncho();
    int ancho_utilizado = get_espacios_restantes();
    if (alto_libro <= altura and ancho_libro <= (anchura - ancho_utilizado)) {
        colocar_libro(ancho_utilizado, l);
        return true;
    } else
        return false;
}

double Estante::getPesoSoportado() const {
    return peso_soportado;
}

void Estante::setPesoSoportado(double pesoSoportado) {
    peso_soportado = pesoSoportado;
}

double Estante::getPesoActual() const {
    return peso_actual;
}

void Estante::setPesoActual(double pesoActual) {
    peso_actual = pesoActual;
}

void Estante::setEspacioContenido(int i, char c) {
    espacios[i].SetContenido(c);
}

void Estante::setEspacioPos(int i, int x, int y) {
    espacios[i].SetPosX(x);
    espacios[i].SetPosY(y);
}

void Estante::muestra_espacio(int i, int j, ofstream &output) const {
    output<<espacios[i*anchura+j];
}

void operator>>(ifstream& input, Estante & e) {
    e.leer(input);
}

//void operator<<(ofstream& output, const Estante &e) {
//    e.mostrar(output);
//}
