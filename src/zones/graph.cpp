#include "../../headers/zones/graph.h"

auto cmp = [](const std::pair<std::string, BoundedState>& lhs,
              const std::pair<std::string, BoundedState>& rhs) {
                    return lhs.first == rhs.first &&
                            (lhs.second.clock.clockToString() == rhs.second.clock.clockToString() &&
                             lhs.second.max_bound < rhs.second.min_bound ||
                             lhs.second.clock.clockToString() < rhs.second.clock.clockToString());
                };

Graph::Graph(TA ta) {
    this->N_clocks = ta.getClocks().size();
    std::vector<std::pair<std::string, BoundedState> > constraints, prevconstraints;
    std::vector<std::pair<std::string, std::vector<BoundedState> > > locbounds, prevlocbounds;
    // This code is terrible, hopefully one day I'll rewrite it...

    // Here we obtain the proper bounds for each clock on each location

    // Firstly, we apply bounds from states
    size_t i = 0;
    for (auto& loc : ta.getLocs()) {
        for (auto& cc : loc.getCC()) {
            BoundedState bstate;
            bstate.clock = cc.getClock();
            size_t val = cc.getClockVal();

            // For the sake of simplicity, there won't be infinity values in the DBM matrix
            if (cc.getOp() == "<") {
                val--;
            }

            constraints.emplace_back(std::pair{loc.getLoc(), bstate});
            prevconstraints.emplace_back(std::pair{loc.getLoc(), bstate});

            if (i > ta.getLocs().size())
                constraints[i].second.min_bound = constraints[i-ta.getLocs().size()].second.max_bound;

            constraints[i].second.max_bound = val;
            prevconstraints[i].second.max_bound = val;
            i++;
        }
    }

    std::sort(constraints.begin(), constraints.end(), cmp);

    //Secondly, we apply bounds from trasnsitions
    for (auto& step : ta.getSteps()) {
        for (auto& cc : step.guards_) {
            size_t val = cc.getClockVal();
            Clock clock = cc.getClock();
            std::string loc = step.now_.getLoc(),
                        op = cc.getOp();

            // For the sake of simplicity, there won't be infinity values in the DBM matrix
            if (op == "<") {
                val--;
            } else if (op == ">") {
                val++;
            }

            auto pos = std::find_if(constraints.begin(), constraints.end(),
                                    [&loc, &clock](const std::pair<std::string, BoundedState>& elem) {
                                        return elem.second.clock == clock && elem.first == loc;
                                    });
            if (pos != constraints.end()) {
                if (op[0] == '<' && pos->second.max_bound > val) {
                    pos->second.max_bound = val;
                }

                if (op[0] == '>' && pos->second.min_bound < val) {
                    pos->second.min_bound = val;
                }
            }
        }

        // Applying resets
        std::string loc1 = step.next_.getLoc();
        for (auto& clock : ta.getClocks()) {
            auto pos = std::find_if(constraints.begin(), constraints.end(),
                                [&loc1, &clock](const std::pair<std::string, BoundedState>& elem) {
                                    return elem.second.clock == clock && elem.first == loc1;
                                });
            auto res = std::find(step.reset_.begin(), step.reset_.end(), clock);
            if (res != step.reset_.end()) {
                pos->second.reset = 1;
            }
        }
    }

    for (size_t i = ta.getClocks().size(); i < constraints.size(); ++i) {
        if (!constraints[i].second.reset)
            constraints[i].second.min_bound = constraints[i-ta.getClocks().size()].second.max_bound;
        else
            constraints[i].second.min_bound = 0;
    }

    for (size_t i = 0; i < constraints.size(); i += N_clocks) {
        std::vector<BoundedState> tmp;
        for (size_t j = i; j < i + N_clocks; ++j) {
            tmp.emplace_back(constraints[j].second);
        }

        locbounds.emplace_back(std::pair{constraints[i].first, tmp});
    }

    for (size_t i = 0; i < locbounds.size(); i++) {
        this->zta.emplace_back(Zone(locbounds[i].first, N_clocks, locbounds[i].second));
    }

    for (size_t i = 0; i < constraints.size(); i += N_clocks) {
        std::vector<BoundedState> tmp;
        for (size_t j = i; j < i + N_clocks; ++j) {
            tmp.emplace_back(prevconstraints[j].second);
        }

        prevlocbounds.emplace_back(std::pair{prevconstraints[i].first, tmp});
    }

    for (size_t i = 0; i < prevlocbounds.size(); i++) {
        this->prevzta.emplace_back(Zone(prevlocbounds[i].first, N_clocks, prevlocbounds[i].second));
    }
}

bool Graph::isReachable(State& dest) {
    //Firstly, we construct a dbm matrix for the destination, and then compare it to the dbm matrices of locations before and after transitions
    std::pair<std::string, std::vector<BoundedState> > locbound;
    locbound.first = dest.getLoc();
    size_t i = 0;
    for (auto& cc : dest.getCC()) {
        BoundedState bstate;
        bstate.clock = cc.getClock();
        size_t val = cc.getClockVal();

        if (cc.getOp() == "<") {
            val--;
        }

        locbound.second.emplace_back(bstate);
        locbound.second[i].max_bound = val;
        i++;
    }

    Zone destzone(locbound.first, this->N_clocks, locbound.second);

    for (size_t i = 0; i < this->zta.size(); ++i) {
        if (zta[i] >= destzone || prevzta[i] >= destzone) return true;
    }

    return false;
}
