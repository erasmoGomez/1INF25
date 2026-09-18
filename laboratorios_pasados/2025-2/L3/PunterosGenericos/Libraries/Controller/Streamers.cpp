//
// Created by erasmo on 9/17/26.
//
#include "Streamers.hpp"

void *read_streamer(ifstream &input_file) {
    //xQcOW,6196161750,27716,3246298,QA1080
    char *account = read_str(input_file, ',');
    if (input_file.eof()) return nullptr;
    input_file.ignore(20, ','); // total time
    input_file.ignore(20, ','); // average viewers
    int followers = read_int(input_file, true);
    char *category = read_str(input_file, '\r');
    input_file.get(); // \n

    void **streamer = new void *[4]{}; //registro streamer
    int *ptr_followers = new int;
    *ptr_followers = followers;
    streamer[ACCOUNT] = account;
    streamer[FOLLOWERS] = ptr_followers;
    streamer[CATEGORY] = category;
    streamer[COMMENTS] = nullptr;
    return streamer;
}

void increase_capacity(void **&data, int &capacity, int &num_data) {
    capacity += INCREMENT;
    if (data == nullptr) {
        data = new void *[capacity]{};
        num_data = 1;
    } else {
        void **aux_data = new void *[capacity + 1]{};
        for (int i = 0; i < num_data; i++)
            aux_data[i] = data[i];
        delete[] data;
        data = aux_data;
    }
}

void add_streamer(void * &streamers, void *streamer, int &num_data, int &capacity) {
    void **data = static_cast<void **>(streamers);
    if (num_data == capacity)
        increase_capacity(data, capacity, num_data);
    data[num_data - 1] = streamer;
    num_data++;
    streamers = data;
}

void load_streamers(void *&streamers, const char *filename) {
    ifstream input_file;
    open_file_read(input_file, filename);
    int num_data = 0, capacity = 0;
    //xQcOW,6196161750,27716,3246298,QA1080
    while (true) {
        void *streamer = read_streamer(input_file);
        if (input_file.eof())break;
        add_streamer(streamers, streamer, num_data, capacity);
    }
}

void *read_comment(ifstream &input_file) {
    //ab7f2910,Can someone please help me understand [Castro_1021 loltyler1]
    char *code = read_str(input_file, ',');
    if (input_file.eof())return nullptr;
    char *text = read_str(input_file, '[');
    char *sender = read_str(input_file, ' ');
    char *receiver = read_str(input_file, ']');
    input_file.get(); //\r
    input_file.get(); //\n
    //cout << code << "  " << text << "  " << sender << "  " << receiver << endl;
    void **comment = new void *[4]{};
    comment[CODE] = code;
    comment[TEXT] = text;
    comment[SENDER] = sender;
    comment[RECEIVER] = receiver;
    return comment;
}

void add_comment(void *&comments, void *comment,
                 int &num_data, int &capacity) {
    void **data = static_cast<void **>(comments);
    if (num_data == capacity)
        increase_capacity(data, capacity, num_data);
    data[num_data - 1] = comment;
    num_data++;
    comments = data;
}

void load_comments(void *&comments, const char *filename) {
    ifstream input_file;
    open_file_read(input_file, filename);
    int num_data = 0, capacity = 0;
    while (true) {
        void *comment = read_comment(input_file);
        if (input_file.eof())break;
        add_comment(comments, comment, num_data, capacity);
    }
    //print_comments(comments, "ReportFiles/comentarios_before.txt");
}

bool same_text(const char *first, void *comment) {
    char *second = static_cast<char *>(comment);
    return strcmp(first, second) == 0;
}

void *create_streamer_comment(void **comment) {
    void **reg_comment = new void *[2]{};
    reg_comment[COMMENT_RECEIVER] = assign_str(static_cast<char *>(comment[RECEIVER]));
    reg_comment[COMMENT_TEXT] = assign_str(static_cast<char *>(comment[TEXT]));
    // data[COMMENT_TEXT] = static_cast<char *>(comment[TEXT]); // no es correcto para el ejercicio
    return reg_comment;
}

void add_streamer_comment(void **&streamer_comments, void **comment,
                          int &num_data, int &capacity) {
    if (num_data == capacity)
        increase_capacity(streamer_comments, capacity, num_data);
    streamer_comments[num_data - 1] = create_streamer_comment(comment);
    num_data++;
}

void add_comments_by_streamer(void *streamer, void **comments) {
    void **reg_streamer = static_cast<void **>(streamer);
    char *account = static_cast<char *>(reg_streamer[ACCOUNT]);
    void **streamer_comments = nullptr;
    int num_data = 0, capacity = 0;

    for (int i = 0; comments[i]; i++) {
        void **comment = static_cast<void **>(comments[i]);
        if (same_text(account, comment[SENDER]))
            add_streamer_comment(streamer_comments, comment,
                                 num_data, capacity);
    }
    reg_streamer[COMMENTS] = streamer_comments;
}

void update_comments(void *streamers, void *comments) {
    void **streamers_data = static_cast<void **>(streamers);
    void **comments_data = static_cast<void **>(comments);
    for (int i = 0; streamers_data[i]; i++)
        add_comments_by_streamer(streamers_data[i], comments_data);
}
