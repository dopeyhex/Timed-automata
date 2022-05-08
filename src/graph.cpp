#include "../headers/graph.h"

auto comparator = [](const Loc& state1, const Loc& state2) -> bool {
    return true;
};

// construct a graph from ta
// give each state a number
Graph::Graph(TA& ta) {
    std::vector<Loc> locs = ta.getLocs();
    
};

/*
bool Graph::isReachable(Loc& src, Loc& dest) {
    std::vector<bool> discovered(this->adj.size());
    std::queue<Loc> q;
    discovered[this->loceval[src]] = true;
    q.push(src);
    while (!q.empty()) {
        Loc v = q.front();
        q.pop();
        if (v == dest) {
            return true;
        }
        for (Loc u: this->adj[this->loceval[v]])
        {
            if (!discovered[this->loceval[u]])
            {
                discovered[this->loceval[u]] = true;
                q.push(u);
            }
        }
    }

    return false;
}*/