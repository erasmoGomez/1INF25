#pragma once
#include "Region.hpp"
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class WorldGraph {
private:
    map<string, vector<string>> adjacency;
    map<string, unique_ptr<Region>> regions;
public:
    WorldGraph();
    ~WorldGraph();
    void add_region(const string& region, const string& type = "Safe");
    bool add_path(const string& origin, const string& destination);
    void show_regions() const;
    void show_connections(const string& region) const;
};
