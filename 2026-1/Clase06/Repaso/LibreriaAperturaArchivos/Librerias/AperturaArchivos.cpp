//
// Created by erasm on 9/04/2026.
//

#include "AperturaArchivos.hpp"

void open_file_read(ifstream &input, const char *file_name) {
    cout<<file_name<<endl;
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