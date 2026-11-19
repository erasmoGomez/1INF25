#include "Region.hpp"
#include <tuple>
using namespace std;

Region::Region(const string& name) : name(name) {}
Region::~Region() = default;
const string& Region::get_name() const { return name; }

// Identity is determined by the unique region name, regardless of subclass.
bool Region::operator==(const Region& other) const { return name == other.name; }
bool Region::operator!=(const Region& other) const { return !(*this == other); }
bool Region::operator<(const Region& other) const { return name < other.name; }

SafeRegion::SafeRegion(const string& name) : Region(name) {}
SafeRegion::~SafeRegion() = default;
string SafeRegion::get_type() const { return "Safe"; }
string SafeRegion::explore_message() const { return "Safe exploration: collect resources."; }

DangerousRegion::DangerousRegion(const string& name) : Region(name) {}
DangerousRegion::~DangerousRegion() = default;
string DangerousRegion::get_type() const { return "Dangerous"; }
string DangerousRegion::explore_message() const { return "Danger! Watch for hostile mobs."; }
