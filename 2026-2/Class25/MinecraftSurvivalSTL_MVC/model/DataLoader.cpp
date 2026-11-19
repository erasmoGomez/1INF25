#include "DataLoader.hpp"
#include "Utils.hpp"
#include "CsvRecords.hpp"

static bool skip_header(ifstream& input) {
    string header;
    return static_cast<bool>(getline(input, header));
}

static bool complete_read(ifstream& input, const string& path, int count) {
    if (input.bad() || (input.fail() && !input.eof())) {
        cerr << "Error de lectura o formato en " << path << '\n';
        return false;
    }
    cout << "Cargados " << count << " registros desde " << path << '\n';
    return true;
}

bool load_blocks(const string& path, MiningStack& stack) {
    ifstream input;
    if (!Utils::open_read_file(input, path) || !skip_header(input)) return false;
    int count = 0;
    while (true) {
        BlockRecord block;
        if (!block.read(input)) break;
        stack.push(block.get_name());
        count++;
    }
    return complete_read(input, path, count);
}

bool load_requests(const string& path, VillagerQueue& queue) {
    ifstream input;
    if (!Utils::open_read_file(input, path) || !skip_header(input)) return false;
    int count = 0;
    while (true) {
        VillagerRequest request;
        if (!request.read(input)) break;
        queue.enqueue(request);
        count++;
    }
    return complete_read(input, path, count);
}

bool load_regions(const string& path, WorldGraph& graph) {
    ifstream input;
    if (!Utils::open_read_file(input, path) || !skip_header(input)) return false;
    int count = 0;
    while (true) {
        RegionRecord region;
        if (!region.read(input)) break;
        graph.add_region(region.get_name(), region.get_type());
        count++;
    }
    return complete_read(input, path, count);
}

bool load_paths(const string& path, WorldGraph& graph) {
    ifstream input;
    if (!Utils::open_read_file(input, path) || !skip_header(input)) return false;
    int count = 0;
    while (true) {
        PathRecord path_record;
        if (!path_record.read(input)) break;
        if (!graph.add_path(path_record.get_origin(), path_record.get_destination())) {
            cerr << "Conexion invalida en " << path << '\n';
            return false;
        }
        count++;
    }
    return complete_read(input, path, count);
}

bool load_resources(const string& path, map<string, int>& resources) {
    ifstream input;
    if (!Utils::open_read_file(input, path) || !skip_header(input)) return false;
    int count = 0;
    while (true) {
        ResourceRecord resource;
        if (!resource.read(input)) break;
        resources[resource.get_name()] += resource.get_quantity();
        count++;
    }
    return complete_read(input, path, count);
}
