/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sobrecargas.hpp"


ostream& operator << (ostream& out, const struct Papeleta& p){
//    out<<"Datos de la Papeleta"<<endl;
//    out<<"Codigo: "<<setw(10)<<p.codigo<<setw(10)<<"Fecha: "<<setw(10)<<p.fecha<<endl;
//    out<<"Monto: "<<setw(10)<<p.monto<<setw(10)<<"Gravedad: "<<setw(10)<<p.gravedad<<endl;
//    out<<"Descripcion: "<<setw(10)<<p.descripcion<<endl;
    out<<setprecision(2)<<fixed;
    out<<setw(ESP_COL)<<p.codigo<<setw(ESP_COL)<<p.fecha<<setw(ESP_COL)<<p.monto;
    out<<setw(ESP_COL)<<p.gravedad<<setw(ESP_COL*2)<<p.descripcion<<endl;
}


ofstream& operator << (ofstream& out, const struct Papeleta& p){
//    out<<"Datos de la Papeleta"<<endl;
//    out<<"Codigo: "<<setw(10)<<p.codigo<<setw(10)<<"Fecha: "<<setw(10)<<p.fecha<<endl;
//    out<<"Monto: "<<setw(10)<<p.monto<<setw(10)<<"Gravedad: "<<setw(10)<<p.gravedad<<endl;
//    out<<"Descripcion: "<<setw(10)<<p.descripcion<<endl;
    out<<setprecision(2)<<fixed;
    out<<setw(ESP_COL)<<p.codigo<<setw(ESP_COL)<<p.fecha<<setw(ESP_COL)<<p.monto;
    out<<setw(ESP_COL)<<p.gravedad<<setw(ESP_COL*2)<<p.descripcion<<endl;
}


int leer_fecha(ifstream& input){
    //2024-03-01,
    int fecha, aa, mm, dd;
    char extra;
    input>>aa>>extra>>mm>>extra>>dd;
    input.get();
    fecha = aa*10000+mm*100+dd;
    return fecha;
}

char* leer_cadena(ifstream& input, char car_lim){
    char* cadena, buffer[MAX_CADENA];
    input.getline(buffer, MAX_CADENA, car_lim); //Lee un const char *
    cadena = new char[strlen(buffer)+1]; //+1 es x el caracter terminante
    strcpy(cadena, buffer);
    return cadena;
}

ifstream& operator >> (ifstream& in, struct Papeleta& p){
    //DNI,CodigoFalta,Fecha,Monto,Gravedad,Descripción
    //12345678,F001,2024-03-01,350.35,Grave,Paso de luz roja
    //12254455,
//    int id;
//    in>>id;
//    in.get(); //Leer la coma
    p.codigo = leer_cadena(in); //char*
    p.fecha = leer_fecha(in);
    in>>p.monto;
    in.get(); //Leer la coma
    p.gravedad = leer_cadena(in);
    p.descripcion = leer_cadena(in, '\n');
    return in;
}

ifstream& operator >> (ifstream& in, struct Conductor& c){
    //12345678,Juan Perez
    in>>c.dni;
    in.get();
    c.nombre = leer_cadena(in, '\n');
    return in;
}

ostream& operator << (ostream& out, const struct Conductor& c){
    out<<setw(ESP_COL)<<c.dni<<setw(ESP_COL*2)<<c.nombre<<endl;
    if(c.n_papeletas != 0){
        for(int i=0; i<c.n_papeletas; i++)
            out<<c.papeletas[i];
    }
}

ofstream& operator << (ofstream& out, const struct Conductor& c){
    out<<setw(ESP_COL)<<c.dni<<setw(ESP_COL*2)<<c.nombre<<endl;
    if(c.n_papeletas != 0){
        for(int i=0; i<c.n_papeletas; i++)
            out<<c.papeletas[i];
    }
}

bool operator<(const Conductor& c, int dni){
    return c.dni < dni;
}

void operator+=(Conductor& c,const Papeleta& p){
    if(c.n_papeletas<MAX_PAPELETAS){
        c.papeletas[c.n_papeletas]=p; // xq ya tiene memoria reservada el arreglo de papeletas
        c.n_papeletas++;
    }else{
        cout<<"No se pudo ingresar la papeleta al conductor"<<endl;
    }
}