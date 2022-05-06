#include "../headers/graph.h"

auto comparator = [](const State& state1, const State& state2) -> bool {
    return true;
};

void Graph::addEdge(const State& now, const State& next,
        const std::vector<ClockConstraint>& guard,
        const std::vector<Clock>& resets,
        const std::string& action) {
        this->edges.emplace_back(now, next, guard, resets, action);
}

// construct a graph from ta
// give each state a number
Graph::Graph(TA& ta) {
    ta.getStates();
    ta.getClocks();
};

/*
bool Graph::isReachable(State& src, State& dest) {
    std::vector<bool> discovered(this->adj.size());
    std::queue<State> q;
    discovered[this->statenums[src]] = true;
    q.push(src);
    while (!q.empty()) {
        State v = q.front();
        q.pop();
        if (v == dest) {
            return true;
        }
        for (State u: this->adj[this->statenums[v]])
        {
            if (!discovered[this->statenums[u]])
            {
                discovered[this->statenums[u]] = true;
                q.push(u);
            }
        }
    }

    return false;
}*/