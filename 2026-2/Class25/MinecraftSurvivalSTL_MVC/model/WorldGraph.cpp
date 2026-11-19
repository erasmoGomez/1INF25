#include "WorldGraph.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;
WorldGraph::WorldGraph() = default;
WorldGraph::~WorldGraph() = default;

void WorldGraph::add_region(const string& region, const string& type) {
    if (region.empty()) return;
    adjacency.try_emplace(region);
    if (!regions.count(region)) {
        if (type == "Dangerous") regions[region] = make_unique<DangerousRegion>(region);
        else regions[region] = make_unique<SafeRegion>(region);
    }
}
bool WorldGraph::add_path(const string& origin, const string& destination) {
    if (!regions.count(origin) || !regions.count(destination) ||
        *regions.at(origin) == *regions.at(destination))
        return false;
    auto& a = adjacency.at(origin);
    auto& b = adjacency.at(destination);
    if (find(a.begin(), a.end(), destination) == a.end()) a.push_back(destination);
    if (find(b.begin(), b.end(), origin) == b.end()) b.push_back(origin);
    return true;
}
void WorldGraph::show_regions() const {
    cout << "World regions:\n";
    for (auto it = adjacency.cbegin(); it != adjacency.cend(); ++it)
        cout << "  " << it->first << " [" << regions.at(it->first)->get_type() << "]\n";
}
void WorldGraph::show_connections(const string& region) const {
    auto it = adjacency.find(region);
    if (it == adjacency.end()) { cout << "Unknown region.\n"; return; }
    cout << region << " -> ";
    for (auto neighbor = it->second.cbegin(); neighbor != it->second.cend(); ++neighbor) {
        if (neighbor != it->second.cbegin()) cout << ", ";
        cout << *neighbor;
    }
    cout << '\n';
}