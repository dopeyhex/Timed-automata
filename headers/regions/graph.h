#pragma once

#include "../ta/ta.h"

struct BoundedState {
    size_t min_bound = 0;
    size_t max_bound = 0;
    std::string location;
};

class Graph {
private:
    std::vector<std::pair<Clock, size_t> > globalMax;
    std::vector<std::pair<Clock, BoundedState> > constraints;
    //first is minimum value, second is maximum

    //std::vector<std::vector<int> > polyhedra;
public:
    Graph() {};
    Graph(TA ta);
    ~Graph() {};

    bool isReachable(State& src, State& dest);
};


//for each location for each clock minimum and maximum values