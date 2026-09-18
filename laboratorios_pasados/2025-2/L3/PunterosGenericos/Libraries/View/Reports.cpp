//
// Created by erasmo on 9/17/26.
//
#include "../Controller/Streamers.hpp"
#include "Reports.hpp"


void print_headers(ofstream &output, const char **headers) {
    int column_width = REPORT_WIDTH / N_COLUMNS;

    for (int i = 0; i < N_COLUMNS; i++)
        output << setw(column_width) << left << headers[i];

    output << endl;
}

void print_streamer_comments(ofstream &output_file, void *comments) {
    void** registro = static_cast<void **>(comments);
    if (registro != nullptr)
        for (int i = 0; registro[i]; i++) {
            void **comment = static_cast<void **>(registro[i]);
            output_file << left << setw(REPORT_WIDTH/N_COLUMNS)
                        << static_cast<char *>(comment[COMMENT_RECEIVER])
                        << static_cast<char *>(comment[COMMENT_TEXT]) << endl;
        }
}

void print_streamer(ofstream &output_file, void *streamer) {
    void **registro = static_cast<void **>(streamer);
    print_line(output_file, '=', REPORT_WIDTH);
    const char *headers[2] = {"CUENTA", "SEGUIDORES"};
    print_headers(output_file, headers);
    output_file << left << setw(REPORT_WIDTH / N_COLUMNS) << static_cast<char *>(registro[ACCOUNT])
            << setw(REPORT_WIDTH / N_COLUMNS) << *static_cast<int *>(registro[FOLLOWERS]) << endl;
    print_line(output_file, '-', REPORT_WIDTH);
    output_file << "Comentarios emitidos:" << endl;
    print_line(output_file, '-', REPORT_WIDTH);
    const char *headers2[2] = {"RECEPTOR", "TEXTO"};
    print_headers(output_file, headers2);
    print_line(output_file, '-', REPORT_WIDTH);
    print_streamer_comments(output_file, registro[COMMENTS]);
}

void print_report(void *streamers,
                  const char *filename) {
    ofstream output_file;
    open_file_write(output_file, filename);
    void **data = static_cast<void **>(streamers);
    for (int i = 0; data[i]; i++)
        print_streamer(output_file, data[i]);
}

void print_comments(void *comentarios, const char *filename) {
    ofstream output_file;open_file_write(output_file, filename);
    void **data = static_cast<void **>(comentarios);
    for (int i = 0; data[i]; i++) {
        void **comment = static_cast<void **>(data[i]);
        output_file<<setw(20)<<(char*)comment[CODE];
        output_file<<setw(80)<<(char*)comment[TEXT];
        output_file<<setw(20)<<(char*)comment[SENDER];
        output_file<<setw(20)<<(char*)comment[RECEIVER]<<endl;
    }
}
