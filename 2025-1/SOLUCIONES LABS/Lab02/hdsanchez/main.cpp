#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct Conductores {
  int *dnis;
  char **nombres;
  int cantidad;
};

struct Infracciones {
  int *codigos;
  char **descripciones;
  char **tipos;
  double *valores;
  int cantidad;
};

struct Faltas {
  Conductores conductores;
  Infracciones infracciones;

  char ***placas;
  int *capacidades;
};

char *leer_cadena_exacta(ifstream &arch, char delim) {
  constexpr int BUFFER_SIZE = 200;
  char buffer[BUFFER_SIZE];
  arch.getline(buffer, BUFFER_SIZE, delim);
  if (arch.eof()) {
    return nullptr;
  }
  char *cadena = new char[strlen(buffer) + 1];
  strcpy(cadena, buffer);
  return cadena;
}

void operator+=(struct Conductores &conductores, const char *file_name) {
  ifstream arch;
  arch.open(file_name, ios::in);
  if (not arch.is_open()) {
    cerr << "[ERROR] Cannot open the file: " << file_name << endl;
    exit(1);
  }
  // Arreglos auxiliares
  int aux_dnis[150]{};
  char *aux_nombres[150]{};
  int cant = 0;
  // Leer data de archivo
  while (true) {
    arch >> aux_dnis[cant];
    if (arch.eof()) {
      break;
    }
    arch.get();
    aux_nombres[cant] = leer_cadena_exacta(arch, '\n');
    cant += 1;
  }
  // Recortar memoria
  conductores.dnis = new int[cant];
  conductores.nombres = new char *[cant];
  for (int i = 0; i < cant; i += 1) {
    conductores.dnis[i] = aux_dnis[i];
    conductores.nombres[i] = aux_nombres[i];
  }
  conductores.cantidad = cant;
}

void operator+=(struct Infracciones &infracciones, const char *file_name) {
  ifstream arch;
  arch.open(file_name, ios::in);
  if (not arch.is_open()) {
    cerr << "[ERROR] Cannot open the file: " << file_name << endl;
    exit(1);
  }
  // Arreglos auxiliares
  int codigos[120];
  char *descripciones[120];
  char *tipos[120];
  double valores[120];
  int cant = 0;
  // Leer data de archivo
  while (true) {
    arch >> codigos[cant];
    if (arch.eof()) {
      break;
    }
    arch.get();
    descripciones[cant] = leer_cadena_exacta(arch, ';');
    tipos[cant] = leer_cadena_exacta(arch, ';');
    arch >> valores[cant] >> ws;
    cant += 1;
  }
  // Recortar memoria
  infracciones.codigos = new int[cant];
  infracciones.descripciones = new char *[cant];
  infracciones.tipos = new char *[cant];
  infracciones.valores = new double[cant];
  for (int i = 0; i < cant; i += 1) {
    infracciones.codigos[i] = codigos[i];
    infracciones.descripciones[i] = descripciones[i];
    infracciones.tipos[i] = tipos[i];
    infracciones.valores[i] = valores[i];
  }
  infracciones.cantidad = cant;
}

int buscar_posicion_conductor(struct Conductores &conductores, int dni) {
  for (int i = 0; i < conductores.cantidad; i += 1) {
    if (conductores.dnis[i] == dni) {
      return i;
    }
  }
  return -1;
}

int numero_de_placas(char **placas) {
  if (placas == nullptr) {
    return -1;
  }
  int i;
  for (i = 0; placas[i] != nullptr; i += 1)
    ;
  return i;
}

void incrementar_memoria(char **&placas, int &capacidad) {
  capacidad += 5;
  if (placas == nullptr) {
    placas = new char *[capacidad] {};
    placas[capacidad - 1] = nullptr;
  } else {
    char **aux_placas = new char *[capacidad] {};
    for (int i = 0; placas[i] != nullptr; i += 1) {
      aux_placas[i] = placas[i];
    };
    delete[] placas;
    placas = aux_placas;
  }
}

void insertar_placa(char **&placas, int &capacidad, char *placa) {
  if (capacidad == numero_de_placas(placas) + 1) {
    incrementar_memoria(placas, capacidad);
  }
  int i;
  for (i = 0; placas[i] != nullptr; i += 1) {
    if (strcmp(placas[i], placa) == 0) {
      return;
    }
  }
  placas[i] = placa;
}

void cargar_faltas_de_los_conductores(struct Faltas &faltas) {
  // Cargar conductores e infracciones, e inicializar placas y capacidades
  faltas.conductores += "conductores.csv";
  faltas.infracciones += "infracciones.csv";
  faltas.placas = new char **[faltas.conductores.cantidad] {};
  faltas.capacidades = new int[faltas.conductores.cantidad]{};

  ifstream arch;
  arch.open("faltas.csv", ios::in);
  if (not arch.is_open()) {
    cerr << "[ERROR] Cannot open the file 'faltas.csv'." << endl;
    exit(1);
  }

  while (true) {
    int dni;
    arch >> dni;
    if (arch.eof()) {
      break;
    }
    arch.get();
    int pos_conductor = buscar_posicion_conductor(faltas.conductores, dni);
    if (pos_conductor == -1) {
      // No se encuentra conductor en archivo "conductores.csv"
      // Leer toda la línea y continuar con el siguiente
      cout << "[WARN] Cannot find the driver " << dni << endl;
    } else {
      char *placa = leer_cadena_exacta(arch, ';');
      insertar_placa(faltas.placas[pos_conductor],
                     faltas.capacidades[pos_conductor], placa);
    }
    while (arch.get() != '\n')
      ;
  }
}

void imprimir_separador(ofstream &arch, char c, int n) {
  for (int i = 0; i < n; i += 1) {
    arch << c;
  }
  arch << endl;
}

void imprimir_faltas_de_los_conductores(struct Faltas &faltas) {
  ofstream arch;
  arch.open("reporte.txt", ios::out);
  if (not arch.is_open()) {
    cerr << "[ERROR] Cannot open the file 'reporte.txt'" << endl;
    exit(1);
  }

  imprimir_separador(arch, '=', 70);
  arch << "  DNI     CLIENTE                               CANT VEHICULOS"
       << endl;
  imprimir_separador(arch, '-', 70);
  for (int i = 0; i < faltas.conductores.cantidad; i += 1) {
    if (faltas.placas[i] == nullptr) {
      continue;
    }
    arch << left << setw(10) << faltas.conductores.dnis[i];
    arch << left << setw(45) << faltas.conductores.nombres[i];
    arch << left << setw(10) << numero_de_placas(faltas.placas[i]) << endl;
  }
  imprimir_separador(arch, '=', 70);
}

int main(int argc, char *argv[]) {
  struct Faltas faltas;
  cargar_faltas_de_los_conductores(faltas);
  imprimir_faltas_de_los_conductores(faltas);
  return 0;
}
