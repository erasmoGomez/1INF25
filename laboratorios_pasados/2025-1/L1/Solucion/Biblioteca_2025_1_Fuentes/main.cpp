#include "Bibliotecas/Sobrecargas.hpp"

int main() {
    int dni[10];
    struct CadenaDeCaracteres nomb[10],placa[10];
    struct CadenaDeCaracteres buff;
    int numDat=0;
    ifstream arch("Data/Infracciones.txt",ios::in);
    if(not arch.is_open()) exit(1);
    while(true){
        !nomb[numDat];
        !placa[numDat];
        arch>>dni[numDat];
        if(arch.eof()) break;
        int i=0;
        !buff;
        while((arch>>buff)==0){
            if(i==0) nomb[numDat]<=buff;
            else {
                nomb[numDat]+="_";
                nomb[numDat]+=buff;
            }
            i++;
        }
        arch>>placa[numDat];

        if(numDat==3) break;
        numDat++;
    }
    if(placa[0]>placa[1] or placa[0]>"W7C-957")
        placa[0]&&placa[1];
    if(placa[0]<placa[1] or placa[0]<"W7C-957")
        placa[0]&&placa[2];
    if(placa[0]==placa[1] or placa[0]=="W7C-957")
        placa[1]&&placa[2];

    ofstream archR("Reports/RepPrueba.txt",ios::out);
    archR<<dni[0]<<endl;
    archR<<nomb[0]<<endl;
    archR<<placa[0]<<endl;
    return 0;
}