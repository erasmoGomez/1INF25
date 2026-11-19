#include "CsvRecords.hpp"

// Un registro por linea. CSV simple: no admite campos entrecomillados con comas.
static bool read_row(ifstream &input, string &line) {
    if (!getline(input, line)) return false;
    if (!line.empty() && line.back() == '\r') line.pop_back();
    return true;
}

static bool split_two(const string &line, string &first, string &second) {
    size_t comma = line.find(',');
    if (comma == string::npos || line.find(',', comma + 1) != string::npos) return false;
    first = line.substr(0, comma);
    second = line.substr(comma + 1);
    return !first.empty() && !second.empty();
}

bool BlockRecord::read(ifstream &input) {
    if (!read_row(input, name)) return false;
    return true;
}

const string &BlockRecord::get_name() const { return name; }

bool RegionRecord::read(ifstream &input) {
    string line;
    if (!read_row(input, line)) return false;
    if (!split_two(line, name, type) || (type != "Safe" && type != "Dangerous")) {
        input.setstate(ios::failbit);
        return false;
    }
    return true;
}

const string &RegionRecord::get_name() const { return name; }
const string &RegionRecord::get_type() const { return type; }

bool PathRecord::read(ifstream &input) {
    string line;
    if (!read_row(input, line)) return false;
    if (!split_two(line, origin, destination)) {
        input.setstate(ios::failbit);
        return false;
    }
    return true;
}

const string &PathRecord::get_origin() const { return origin; }
const string &PathRecord::get_destination() const { return destination; }

bool ResourceRecord::read(ifstream &input) {
    string line, number;
    if (!read_row(input, line)) return false;
    if (!split_two(line, name, number) || !Utils::parse_positive_int(number, quantity)) {
        input.setstate(ios::failbit);
        return false;
    }
    return true;
}

const string &ResourceRecord::get_name() const { return name; }
int ResourceRecord::get_quantity() const { return quantity; }
