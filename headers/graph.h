#pragma once

#include "ta.h"
#include <queue>
#include <map>

class Graph {
private:
    std::vector<Edge> edges;
    std::vector<std::vector<Loc> > adj;
    std::map<Loc, size_t> loceval;
public:

    Graph() {};
    // construct a graph from ta
    // give each state a number
    Graph(TA& ta);
    ~Graph() {};

    bool isReachable(Loc& src, Loc& dest);
};