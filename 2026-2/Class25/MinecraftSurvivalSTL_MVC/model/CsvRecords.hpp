#pragma once
#include "Utils.hpp"

class BlockRecord {
private:
    string name;
public:
    bool read(ifstream& input);
    const string& get_name() const;
};

class RegionRecord {
private:
    string name;
    string type;
public:
    bool read(ifstream& input);
    const string& get_name() const;
    const string& get_type() const;
};

class PathRecord {
private:
    string origin;
    string destination;
public:
    bool read(ifstream& input);
    const string& get_origin() const;
    const string& get_destination() const;
};

class ResourceRecord {
private:
    string name;
    int quantity = 0;
public:
    bool read(ifstream& input);
    const string& get_name() const;
    int get_quantity() const;
};
