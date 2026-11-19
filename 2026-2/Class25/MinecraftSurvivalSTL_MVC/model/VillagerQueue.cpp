#include "VillagerQueue.hpp"
#include "Utils.hpp"
#include <iostream>
#include <tuple>
using namespace std;

VillagerRequest::VillagerRequest() {
    quantity = 0;
}

string VillagerRequest::get_villager() const {
    return villager;
}

void VillagerRequest::set_villager(const string &villager) {
    this->villager = villager;
}

string VillagerRequest::get_resource() const {
    return resource;
}

void VillagerRequest::set_resource(const string &resource) {
    this->resource = resource;
}

int VillagerRequest::get_quantity() const {
    return quantity;
}

void VillagerRequest::set_quantity(const int quantity) {
    this->quantity = quantity;
}

bool VillagerRequest::valid() {
    return !villager.empty() && !resource.empty() && quantity > 0;
}

bool VillagerRequest::read(ifstream &input) {
    //Farmer,Wood,8
    getline(input, villager, ',');
    if (input.eof())return false;
    getline(input, resource, ',');
    input>>quantity;
    return true;
}

VillagerQueue::VillagerQueue() = default;
VillagerQueue::~VillagerQueue() = default;

void VillagerQueue::enqueue(const VillagerRequest& request) {
    requests.push_back(request);
}
bool VillagerQueue::dequeue(VillagerRequest& removed) {
    if (requests.empty()) return false;
    removed = requests.front();
    requests.pop_front();
    return true;
}
bool VillagerQueue::front(VillagerRequest& request) const {
    if (requests.empty()) return false;
    request = requests.front();
    return true;
}
bool VillagerQueue::empty() const { return requests.empty(); }
void VillagerQueue::display() const {
    cout << "Villager requests (front -> rear):\n";
    if (requests.empty()) cout << "  (empty)\n";
    for (auto it = requests.cbegin(); it != requests.cend(); ++it)
        cout << "  " << it->get_villager() << " requests "
                  << it->get_quantity() << " " << it->get_resource() << '\n';
}

