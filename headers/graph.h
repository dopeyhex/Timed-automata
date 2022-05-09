#pragma once

#include "ta.h"

class Graph {
private:

public:
    Graph() {};
    // construct a graph from ta
    // give each state a number
    Graph(TA& ta);
    ~Graph() {};

    bool isReachable(Loc& src, Loc& dest);
};


//for each location for each clock minimum and maximum values