//
// Created by Erasmo on 22/08/25.
//

#include "AuxiliaryFunctions.hpp"

void open_file_read(ifstream &input, const char *file_name) {
    //cout<<file_name<<endl;
    input.open(file_name, ios::in);
    if(!input.is_open()){
        cout<<"The file can not open: "<<file_name;
        exit(1);
    }
}

void open_file_write(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if(!output.is_open()){
        cout<<"The file can not open: "<<file_name;
        exit(1);
    }
}

int read_date(ifstream & input){
    int date, aa, mm, dd;
    char c;
    input>>aa;
    if (input.eof())return 0;
    input>>c>>mm>>c>>dd;
    date = aa*10000+mm*100+dd;
    return date;
}

char * read_str(ifstream &input, char dlm) {
    char* str, buffer[REVIEW_SIZE];
    input.getline(buffer, REVIEW_SIZE, dlm);
    str = new char[strlen(buffer)+1];
    strcpy(str, buffer);
    return str;
}

double read_double(ifstream &input, bool read_delim) {
    double d;
    input>>d;
    if(read_delim) input.get();
    return d;
}
