//
// Created by erasmo on 6/17/26.
//

#include "Demo.hpp"

void Demo::demo_vector_lectura() {
    cout << "Demo Lectura en Vectors" << endl;
    //Funciona como un arreglo dinámico
    int codigo;
    codigos.push_back(codigo);
    cout << "El size del vector es:" << codigos.size() << endl;
    cout << "La capacidad del vector es:" << codigos.capacity() << endl;
    codigos.push_back(codigo);
    codigos.push_back(codigo);
    codigos.push_back(codigo);
    codigos.push_back(codigo);
    cout << "El size del vector es:" << codigos.size() << endl;
    cout << "La capacidad del vector es:" << codigos.capacity() << endl;
    codigos.shrink_to_fit();
    cout << "El size del vector es:" << codigos.size() << endl;
    cout << "La capacidad del vector es:" << codigos.capacity() << endl;

    //string
    string nombre;
    nombre = "erasmo gomez";
    nombres.push_back(nombre);
    char *nombre_ptr;
    nombre_ptr = new char[nombre.length() + 1];
    strcpy(nombre_ptr, nombre.c_str());
    nombres.push_back(nombre_ptr);
    char nombre_buffer[30] = "Erasmo Gomez";
    nombres.push_back(nombre_buffer);

    //Objetos
    Alumno alumno{};
    alumno.set_codigo(20082060);
    alumno.set_nombre("Erasmo Gomez");
    alumno.set_aprobado(true); //obvio ?
    alumnos.push_back(alumno);
}

void Demo::demo_list_lectura() {
    // Lista de lista de listas
    semestre_informatica = {
        {
            // Curso 1: Programacion 2
            {{"Carlos", "Maria", "Erasmo"}}, // Horario 583
            {{"Lucia", "Jose", "Rony"}} // Horario 582
        },
        {
            // Curso 2: Tecnicas Programacion
            {{"Diana", "Rafael", "Esteban"}}, // Horario 431
            {{"Martina", "Kevin", "Camila"}} // Horario 432
        },
        {
            // Curso 3: Algoritmia
            {{"Rosa", "Jorge", "Patricia"}},
            {{"Pedro", "Andrea", "Valeria"}}
        }
    };

    //list<list<list<string>>>
    string nombre_alumno_1 = "erasmo gomez";
    string nombre_alumno_2 = "evaristo montoya";
    list<string> horario_431;
    horario_431.push_back(nombre_alumno_1);
    horario_431.push_back(nombre_alumno_2);
    list<list<string>> curso;
    curso.push_back(horario_431);
    semestre_informatica.push_back(curso);

    // Leer desde un archivo y guardar en Lista
    ifstream input_alumnos("ArchivosDeDatos/alumnos.csv", ios::in);
    // while (true) {
    //     Alumno *alumno = new Alumno();
    //     input_alumnos >> *alumno;
    //     if (input_alumnos.eof()) break;
    //     lista_alumnos.push_back(alumno);
    //     //lista_alumnos.push_front(alumno);
    // }
    while (true) {
        Alumno alumno;
        input_alumnos >> alumno;
        if (input_alumnos.eof()) break;
        lista_alumnos.push_back(alumno);
        //lista_alumnos.push_front(alumno);
    }
    list<list<int>> cola_prioridad_eventos_2;
    list<int>cola_prioridad_eventos;
    // //Encolar
    cola_prioridad_eventos.push_back(1);
    cola_prioridad_eventos.push_back(5);
    cola_prioridad_eventos.push_back(10);
    // //Desencolar
    // int desencolado;
    cola_prioridad_eventos.pop_front();

    lista_alumnos.sort();
}

void Demo::demo_map_lectura() {
    //Inserciones map<string, Alumno>
    // Para trabajar con MAP tienes q tener declarado y definido lo siguiente:
    // CC, Sobrecarga =, sobrecarga <
    Alumno alumno_erasmo;
    alumno_erasmo.set_codigo(20082060);
    alumno_erasmo.set_aprobado(true);
    alumno_erasmo.set_nombre("Erasmo Gomez");
    dicionario_alumnos.insert({"erasmo", alumno_erasmo});
    Alumno alumno_evaristo;
    alumno_evaristo.set_codigo(20241365);
    alumno_evaristo.set_aprobado(false);
    alumno_evaristo.set_nombre("Evaristo Montoya");
    dicionario_alumnos.insert({"evaristo", alumno_evaristo});
    cout<<"impresion map"<<endl;
    dicionario_alumnos["evaristo"].imprimir(cout);

    map<Alumno, int> dicionario_alumnos_codigo;
    dicionario_alumnos_codigo[alumno_erasmo] = alumno_erasmo.get_codigo();

    //iterator<pair<string, Alumno>> it= dicionario_alumnos.find("evaristo");
    auto it = dicionario_alumnos.find("evaristo");
    cout<<"El codigo del senhor Evaristo es: " << it->second.get_codigo() << endl;

    auto it2 = dicionario_alumnos.find("coca");
    cout<<"El codigo del senhor Coca es: " << it2->second.get_codigo() << endl;
}

void Demo::demo_lectura() {
    cout << "Demo Lectura" << endl;
    demo_vector_lectura();
    demo_list_lectura();
    demo_map_lectura();
}

void Demo::demo_vector_escritura() {
    cout << "Demo Escritura en Vectors" << endl;
    for (Alumno &alumno: alumnos) {
        cout << alumno;
    }
    cout << endl;
    // for (int i= 0; i<alumnos.size(); i++)
    //     cout << alumnos[i];
    // cout << endl;
}

void Demo::demo_list_escritura() {
    cout<<"DEMO ESCRITURA LIST"<<endl;
    for (auto& alumno: lista_alumnos) {
        cout << alumno;
    }
}

void Demo::demo_map_escritura() {
    cout<<"impresion de los alumnos MAP"<<endl;
    for (auto& elemento: dicionario_alumnos) {
        cout<<setw(20)<<elemento.first; //Key -> Nombre de Alumno
        cout<<elemento.second; //Value -> Alumno
    }
}

void Demo::demo_escritura() {
    demo_vector_escritura();
    demo_list_escritura();
    demo_map_escritura();
}
