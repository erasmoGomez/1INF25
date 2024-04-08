/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"

using namespace std;

char * read_hashtag(ifstream &input){
    char *hashtag;
    hashtag = new char [8];
    input.get(hashtag,8);
    return hashtag;
}

char * read_message(ifstream & input) {
    char buffer[100]{};
    char * message;
    input.getline(buffer, 100, ','); //Just saw the most beautiful sunset today!\0
    message = new char[strlen(buffer) + 1]; //Reserva de memoria
    strcpy(message, buffer); //Asignacion de valores
    return message;
}

char ** read_list_hashtags(ifstream & input) {
    char *buffer_hashtags[100]{}, **list_hashtags;
    int hashtags_size = 0;
    while(true){
        buffer_hashtags[hashtags_size] = read_hashtag(input);
        hashtags_size++;
        if(input.get()=='\n')break;
    }
    list_hashtags = new char*[hashtags_size+1]{};
    for(int i = 0; i<hashtags_size; i++)
        list_hashtags[i] = buffer_hashtags[i];
    return list_hashtags;
}

void read_tweets(int * & dates,
        char ** & messages,
        char *** & hashtags_messages,
        const char * filename) {
    int buffer_dates[20]{}, tweets_size = 0, date;
    char * buffer_messages[20]{};
    char ** buffer_hashtags_messages[20]{};

    ifstream input(filename, ios::in);
    //Validamos que el archivo exista
    if (not input.is_open()) {
        cout << "The file: " << filename << "doesnt exist" << endl;
        exit(1);
    }
    // 20230401,Just saw the most beautiful sunset today!,#sunset,#beauty
    while (true) {
        input >> date;
        if (input.eof()) break;
        input.get(); //Para leer la coma
        buffer_dates[tweets_size] = date; //OK
        buffer_messages[tweets_size] = read_message(input); //Asignar un char*
            buffer_hashtags_messages[tweets_size] = read_list_hashtags(input);
        tweets_size++;
    }
    //Devolver la informacion completa en arreglos con MEMORIA EXACTA
    dates = new int[tweets_size + 1] {};
    messages = new char * [tweets_size + 1] {};
    hashtags_messages = new char ** [tweets_size + 1] {};
    //Asignar valores
    for(int i=0;i<tweets_size; i++){
        dates[i] = buffer_dates[i];
        messages[i] = buffer_messages[i];
        hashtags_messages[i] = buffer_hashtags_messages[i];
    }
}

void display_hashtags(char **hashtags, ofstream &output){
    for(int i=0; hashtags[i]; i++){
        output<<right<<setw(25)<<hashtags[i]<<endl;
    }
}

void display_tweets(int *dates, char**messages, 
                    char***hashtags_messages, const char*filename){
    ofstream output(filename, ios::out);
    
    for(int i=0; dates[i]; i++){
        output<<left<<setw(10)<<dates[i]<<messages[i]<<endl;
        output<<left<<setw(10)<<"List of Hashtags: "<<endl;
        display_hashtags(hashtags_messages[i], output);
    }
}