#pragma once

#include "ta.h"
#include <queue>
#include <map>

class Edge {
private:
    State now_, next_;
    std::vector<ClockConstraint> guard_;
    std::vector<Clock> resets_;
    std::string action_;
public:
    Edge() {};
    Edge(const State& now, const State& next,
         const std::vector<ClockConstraint>& guard,
         const std::vector<Clock>& resets,
         const std::string& action) :
            now_(now), next_(next),
            guard_(guard), resets_(resets),
            action_(action) {};
    ~Edge() {};
};


class Graph {
private:
    std::vector<Edge> edges;
    std::vector<std::vector<State> > adj;
public:
    void addEdge(const State& now, const State& next,
         const std::vector<ClockConstraint>& guard,
         const std::vector<Clock>& resets,
         const std::string& action);

    Graph() {};
    // construct a graph from ta
    // give each state a number
    Graph(TA& ta);
    ~Graph() {};

    bool isReachable(State& src, State& dest);
};