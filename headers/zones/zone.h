#pragma once

#include "../ta/ta.h"

struct BoundedState {
    size_t min_bound = 0;
    size_t max_bound = 0;
    Clock clock;
    bool reset = 0;
};

struct Zone {
    std::vector<std::vector<int64_t> > dbm;
    std::string location;

    Zone(std::string loc, size_t N_clocks, std::vector<BoundedState> bs);
    Zone() {};
    ~Zone() {};

    friend bool operator== (const Zone& lhs, const Zone& rhs);
    friend bool operator>= (const Zone& lhs, const Zone& rhs);
};