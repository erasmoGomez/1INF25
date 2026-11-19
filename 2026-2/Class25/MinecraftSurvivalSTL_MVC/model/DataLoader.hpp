#pragma once
#include "Utils.hpp"
#include "MiningStack.hpp"
#include "VillagerQueue.hpp"
#include "WorldGraph.hpp"
#include <map>
#include <string>
bool load_blocks(const string& path, MiningStack& stack);
bool load_requests(const string& path, VillagerQueue& queue);
bool load_regions(const string& path, WorldGraph& graph);
bool load_paths(const string& path, WorldGraph& graph);
bool load_resources(const string& path, map<string, int>& resources);
