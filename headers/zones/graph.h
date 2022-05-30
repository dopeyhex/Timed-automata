#pragma once

#include "zone.h"

class Graph {
private:
    // for each location define each clock's bounds right before the transition
    size_t N_clocks;
    std::vector<Zone> zta;
    std::vector<Zone> prevzta;
public:
    Graph() {};
    Graph(TA ta);
    ~Graph() {};

    bool isReachable(State& dest);
};
