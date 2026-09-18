#include "Libraries/Controller/Streamers.hpp"

int main() {
    void *streamers = nullptr,*comentarios = nullptr;
    load_streamers(streamers, "DataFiles/streamers.csv");
    load_comments(comentarios, "DataFiles/comentarios.csv");
    print_comments(comentarios, "ReportFiles/report_comments.txt");
    update_comments(streamers,comentarios);
    print_report(streamers, "ReportFiles/report.txt");

    return 0;
}
