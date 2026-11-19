#pragma once
#include <string>
using namespace std;

class Region {
protected:
    string name;
public:
    explicit Region(const string& name);
    virtual ~Region();
    Region(const Region&) = default;
    Region& operator=(const Region&) = default;

    const string& get_name() const;
    virtual string get_type() const = 0;
    virtual string explore_message() const = 0;

    bool operator==(const Region& other) const;
    bool operator!=(const Region& other) const;
    bool operator<(const Region& other) const;
};

class SafeRegion : public Region {
public:
    explicit SafeRegion(const string& name);
    ~SafeRegion() override;
    string get_type() const override;
    string explore_message() const override;
};

class DangerousRegion : public Region {
public:
    explicit DangerousRegion(const string& name);
    ~DangerousRegion() override;
    string get_type() const override;
    string explore_message() const override;
};
