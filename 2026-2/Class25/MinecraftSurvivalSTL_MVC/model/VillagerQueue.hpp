#pragma once
#include <list>
#include <string>
#include <fstream>
using namespace std;

class VillagerRequest {
private:
    string villager;
    string resource;
    int quantity;
public:
    VillagerRequest();

    string get_villager() const;

    void set_villager(const string &villager);

    string get_resource() const;

    void set_resource(const string &resource);

    int get_quantity() const;

    void set_quantity(const int quantity);

    bool valid();



public:
    bool read(ifstream &input);

    bool operator==(const VillagerRequest &other) const;

    bool operator!=(const VillagerRequest &other) const;

    bool operator<(const VillagerRequest &other) const;
};

class VillagerQueue {
private:
    list<VillagerRequest> requests;

public:
    VillagerQueue();

    ~VillagerQueue();

    void enqueue(const VillagerRequest &request);

    bool dequeue(VillagerRequest &removed);

    bool front(VillagerRequest &request) const;

    bool empty() const;

    void display() const;
};
