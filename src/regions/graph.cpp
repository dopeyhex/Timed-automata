#include "../../headers/regions/graph.h"

#include <iostream>

auto cmp = [](const std::pair<Clock, BoundedState>& a,
              const std::pair<Clock, BoundedState>& b) {
                    return a.first.clockToString() == b.first.clockToString() &&
                           a.second.max_bound < b.second.min_bound ||
                           a.first.clockToString() < b.first.clockToString();
                };

Graph::Graph(TA ta) {
    // here we gain bounds for each clock right before
    // the transition to the new location

    // This code is actually terrible, hopefully one day I'll fix it :D
    size_t i = 0;

    for (auto& loc : ta.getLocs()) {
        for (auto& cc : loc.getCC()) {
            BoundedState cProp;
            cProp.location = loc.getLoc();
            size_t val = cc.getClockVal();
            if (cc.getOp() == "<") {
                val--;
            }

            this->constraints.emplace_back(std::pair{cc.getClock(), cProp});

            if (i > loc.getCC().size())
                    this->constraints[i].second.min_bound = this->constraints[i-loc.getCC().size()].second.max_bound;

            this->constraints[i].second.max_bound = val;
            i++;
        }
    }

    std::sort(this->constraints.begin(), this->constraints.end(), cmp);

    for (auto& step : ta.getSteps()) {
        for (auto& cc : step.guards_) {
            size_t val = cc.getClockVal();
            Clock clock = cc.getClock();
            std::string loc = step.now_.getLoc(), op = cc.getOp();

            if (op == "<") {
                val--;
            } else if (op == ">") {
                val++;
            }

            auto pos = std::find_if(this->constraints.begin(), this->constraints.end(),
                                    [&loc, &clock](const std::pair<Clock, BoundedState>& elem) {
                                        return elem.second.location == loc && elem.first == clock;
                                    });
            if (pos != this->constraints.end()) {
                if (op[0] == '<' && pos->second.max_bound > val) {
                    pos->second.max_bound = val;
                }

                if (op[0] == '>' && pos->second.min_bound < val) {
                    pos->second.min_bound = val;
                }

                auto reset = std::find(step.reset_.begin(), step.reset_.end(), clock);
                if (reset != step.reset_.end()) {
                    pos->second.min_bound = 0;
                }
            }
        }
    }

    for (size_t i = 1; i < this->constraints.size(); ++i) {
        if (this->constraints[i-1].first == this->constraints[i].first) {
            this->constraints[i].second.min_bound = this->constraints[i-1].second.max_bound;
        }

        if ((i+1) % ta.getLocs().size() == 0) {
            this->globalMax.emplace_back(std::pair{this->constraints[i].first, this->constraints[i].second.max_bound});
        }
    }
};

/*
bool Graph::isReachable(State& src, State& dest) {
    std::vector<bool> discovered(this->adj.size());
    std::queue<State> q;
    discovered[this->loceval[src]] = true;
    q.push(src);
    while (!q.empty()) {
        State v = q.front();
        q.pop();
        if (v == dest) {
            return true;
        }
        for (State u: this->adj[this->loceval[v]])
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
std::string TA::run(State& start) {
    return run(start, start);
}

std::string TA::run(State& start, State& now) {
    std::string res = "";
    State next;

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

    void setClockMinValue(size_t val, std::string state);
    void setClockMaxValue(size_t val, std::string state);


    std::unordered_map<std::string, size_t> mins;
    std::unordered_map<std::string, size_t> maxs;


void Clock::setClockMinValue(size_t val, std::string state) {
    if (!this->mins.contains(state) || this->mins[state] > val) this->mins[state] = val;
}

void Clock::setClockMaxValue(size_t val, std::string state) {
    if (!this->maxs.contains(state) || this->maxs[state] < val) this->maxs[state] = val;
}

std::unordered_map<std::string, size_t> Clock::getMins() {
    return this->mins;
}

std::unordered_map<std::string, size_t> Clock::getMaxs() {
    return this->maxs;
}

    }
}*/
