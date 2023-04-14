/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void crear_archivo_binario(const char * nombre_arch_lectura, const char * nombre_binario){
    ofstream arch_bin_out(nombre_binario, ios::out|ios::binary);
    if(not arch_bin_out.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo " << nombre_arch_lectura <<endl;
        exit(1);
    }
    ifstream arch_texto_in(nombre_arch_lectura, ios::in);
    
    int dni;
    char nombre[60];
    double sueldo;
    
    while(true){
        arch_texto_in>>dni;
        if(arch_texto_in.eof())break;
        arch_texto_in>>nombre>>sueldo;
        
        arch_bin_out.write(reinterpret_cast<const char*>(&dni), sizeof(int));
        arch_bin_out.write(reinterpret_cast<const char*>(nombre), sizeof(char)*60);
        arch_bin_out.write(reinterpret_cast<const char*>(&sueldo), sizeof(double));
    }
    arch_bin_out.close();
}

void leer_archivo_binario(const char* nombre_binario){
    ifstream archivo_binario_in(nombre_binario, ios::in|ios::binary);
    if(not archivo_binario_in.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo " << nombre_binario <<endl;
        exit(1);
    }
    
    int dni, n=0;
    char nombre[60];
    double sueldo;
    while(true){
        archivo_binario_in.read(reinterpret_cast<char *>(&dni),sizeof(int));
        if(archivo_binario_in.eof())break;
        archivo_binario_in.read(reinterpret_cast<char *>(nombre),sizeof(char)*60);
        archivo_binario_in.read(reinterpret_cast<char *>(&sueldo),sizeof(double));
        cout<<left<<setw(3)<<++n<<setw(10)<<dni<<setw(60)<<nombre<<right<<setw(10)<<sueldo<<endl;
    }
    archivo_binario_in.close();
}

int verificar_criterio(char * nombre){
    char slash= '/';
    int n = 0, nw = 0;
    int i=0;
    for(i; nombre; i++){
        if(nombre[i] == slash)
            n++;
        if(n==2)break;
    }
    for(int k = i; nombre; k++){
        if(nombre[k] == 'a')
            nw++;
        if(nw == 2) return 1;
    }
    return 0;
}

void busqueda_modificacion_datos_binario(const char * nombre_binario){
    fstream archivo_binario_in(nombre_binario, ios::in|ios::out|ios::binary);
    if(not archivo_binario_in.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo " << nombre_binario <<endl;
        exit(1);
    }
    int codigo;
    char nombre[60];
    double sueldo;
    int criterio;
    
    tam_registro = sizeof(int) + sizeof(char)*60 + sizeof(double);
    archivo_binario_in.seekg(0, ios::end);
    tam_archivo = archivo_binario_in.tellg();
    archivo_binario_in.seekg(0, ios::beg);
    cantidad_registros = tam_archivo/tam_registro;
    
    for (int i = 0; i<cantidad_registros; i++){
        archivo_binario_in.seekg(i*tam_registro,ios::beg);
        archivo_binario_in.seekg(sizeof(codigo),ios::cur);//Avanzado el codigo
        archivo_binario_in.read(reinterpret_cast<char*>(nombre),sizeof(char)*60);
        criterio = verificar_criterio(nombre);
        if(criterio){
            //lectura
            archivo_binario_in.read(reinterpret_cast<char*>(&sueldo),sizeof(double));
            //modificacion
            sueldo = sueldo + 50/100*sueldo;
            //reubicarme
            archivo_binario_in.seekg(i*tam_registro + sizeof(codigo) + sizeof(nombre),ios::beg);
            //guardar
            archivo_binario_in.write(reinterpret_cast<const char*>(&sueldo), sizeof(double));
        }
        else{
            archivo_binario_in.seekg(sizeof(sueldo),ios::cur);
        }
    }
    
}

void acceso_directo_datos(const char * nombre_binario, int pos){
    ifstream archivo_binario_in(nombre_binario, ios::in|ios::binary);
    if(not archivo_binario_in.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo " << nombre_binario <<endl;
        exit(1);
    }
    int dni, tam_registro, tam_archivo, cantidad_registros;
    char nombre[60];
    double sueldo;
    
    tam_registro = sizeof(int) + sizeof(char)*60 + sizeof(double);
    archivo_binario_in.seekg(0, ios::end);
    tam_archivo = archivo_binario_in.tellg();
    archivo_binario_in.seekg(0, ios::beg);
    cantidad_registros = tam_archivo/tam_registro;

    archivo_binario_in.seekg((pos-1)*tam_registro, ios::beg);
    
    //Leo el registro en la pos 10
    archivo_binario_in.read(reinterpret_cast<char *>(&dni),sizeof(int));
    archivo_binario_in.read(reinterpret_cast<char *>(nombre),sizeof(char)*60);
    archivo_binario_in.read(reinterpret_cast<char *>(&sueldo),sizeof(double));
    
    //Imprimo el registro de la pos 10
    
    cout<<left<<setw(3)<<pos<<setw(10)<<dni<<setw(60)<<nombre<<right<<setw(10)<<sueldo<<endl;
    archivo_binario_in.close();
}