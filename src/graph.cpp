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


/*
std::string TA::run(Loc& start) {
    return run(start, start);
}

std::string TA::run(Loc& start, Loc& now) {
    std::string res = "";
    Loc next;

    // зкште мфдгуы ща сдщсл


    for (auto& tr : this->transitions) {
        if (tr.now_ == now) {
            next = tr.next_;
            for (auto& guard : tr.guards_) {
                // Count lower and upper bounds for clocks in "now" state
                // to transit to the next state
                
            }

            for (auto& reset : tr.reset_) {
                for (auto& clock : this->clocks) {
                    if (clock == reset) {
                        clock.setClockValue(0);
                    }
                }
            }
            break;
        }
    }

    if (next == start) {
        return res;
    } else {
        return res + run(start, next);
    }

    
auto iter = std::find(this->clocks.begin(), this->clocks.end(), tmpClock);
                if (iter != this->clocks.end()) {
                    ClockConstraint tmpCons(tmpClock, static_cast<std::string>(sm[2]));
                    l.addCC(tmpCons);
                    if (tmpCons.getOp() == "<") {
                        (*iter).setClockMaxValue(tmpCons.getClockVal() - 1);
                    } else {
                        (*iter).setClockMaxValue(tmpCons.getClockVal() - 1);
                    }


    if (this->op == "<") {
            while (val < this->maxClockVal) this->clock.setClockValue(val++);
            this->prevClosed = true;
        } else if (this->op == "<=") {
            while (val <= this->maxClockVal) {
                this->clock.setClockValue(val++);
                std::cout <<this->clock.clockToString() << " " << this->clock.getClockValue() << "\n";
            }
            this->prevClosed = true;
        }
        
        
        for (auto& clock : reset) {
        for (auto& cl : this->clocks) {
            if (cl == clock)
                cl.setClockValue(0);
        }


    std::unordered_map<std::string, size_t> getMins();
    std::unordered_map<std::string, size_t> getMaxs();

    void setClockMinValue(size_t val, std::string loc);
    void setClockMaxValue(size_t val, std::string loc);


    std::unordered_map<std::string, size_t> mins;
    std::unordered_map<std::string, size_t> maxs;


void Clock::setClockMinValue(size_t val, std::string loc) {
    if (!this->mins.contains(loc) || this->mins[loc] > val) this->mins[loc] = val;
}

void Clock::setClockMaxValue(size_t val, std::string loc) {
    if (!this->maxs.contains(loc) || this->maxs[loc] < val) this->maxs[loc] = val;
}

std::unordered_map<std::string, size_t> Clock::getMins() {
    return this->mins;
}

std::unordered_map<std::string, size_t> Clock::getMaxs() {
    return this->maxs;
}

    }
}*/
