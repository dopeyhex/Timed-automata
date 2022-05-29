#include "../../headers/ta/ta.h"

void TA::addInv(std::string& cons, std::string& state) {
    for (auto& l : this->states) {
        if (l.getLoc() == state) {
            // input check
            std::regex pattern("^\\s*(\\w)\\s*([<>]?=?\\s*\\d+)\\s*$");
            std::smatch sm;
            if (std::regex_search(cons, sm, pattern)) {
                Clock tmpClock(static_cast<std::string>(sm[1]));
                if (std::find(this->clocks.begin(), this->clocks.end(), tmpClock) != this->clocks.end()) {
                    ClockConstraint tmpCons(tmpClock, static_cast<std::string>(sm[2]));
                    if (tmpCons.getOp()[0] == '<')
                        l.addCC(tmpCons);
                    else
                        throw std::runtime_error("Added constraint is not in the right format");
                } else {
                    throw std::runtime_error("Clock was not added");
                }
            } else {
                throw std::runtime_error("Added constraint is not in the right format");
            }
            break;
        }
    }
}

void TA::addTransition(const State& now, const State& next,
        const std::vector<ClockConstraint>& guards,
        const std::vector<Clock>& reset,
        const std::string& action) {
        //check the transition so each clock behaves accordingly to the states
        bool flag = 0;
        for (auto lhs : now.getCC()) {
            for (auto rhs : guards) {
                if ((rhs.getClock() == lhs.getClock()) &&
                    (rhs.getOp()[0] == '>') &&
                    (lhs.getClockVal() < rhs.getClockVal())) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }

        if (!flag) {
            for (auto lhs : next.getCC()) {
                for (auto rhs : guards) {
                    if ((rhs.getClock() == lhs.getClock()) &&
                        (rhs.getOp()[0] == '>') &&
                        (lhs.getClockVal() < rhs.getClockVal())) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
        }

        if (!flag)
            this->transitions.emplace_back(now, next, guards, reset, action);
        else
            throw std::runtime_error("This transition is impossible");
}

void TA::setClocks(std::vector<std::string>& clocks) {
    for (auto& clock : clocks) {
        this->clocks.push_back(clock);
    }
}

/*
void TA::setLocs(std::vector<std::string>& locs) {
    for (auto& state : states) {
        if (std::find(this->states.begin(), this->states.end(), state) == this->states.end()) {
            this->states.push_back(state);
        } else {
            throw std::runtime_error("State is already added");
        }
    }
}*/

void TA::setStates(std::vector<State>& states) {
        for (auto& state : states) {
        if (std::find(this->states.begin(), this->states.end(), state) == this->states.end()) {
            bool flag = 0;
            for (const auto& cc : state.getCC()) {
                if (cc.getOp()[0] != '<')
                    flag = 1;
                    break;
            }
            if (!flag) this->states.push_back(state);
            else throw std::runtime_error("Added constraint is not in the right format");
        } else {
            throw std::runtime_error("State is already added");
        }
    }
}

const std::vector<Clock> TA::getClocks() const{
    return this->clocks;
}

const std::vector<State> TA::getLocs() const{
    return this->states;
}

const std::vector<Step> TA::getSteps() const{
    return this->transitions;
}

std::string TA::taToString() {
    std::string res = "Clocks:\n";
    for (auto& clock : this->clocks)
        res += clock.clockToString() + "; ";
    res += "\n\nStates (Locations X Eval(C)):\n";
    for (auto& state : this->states) {
        res += state.locToString() + ";\n";
    }
    res += "\nTransitions:\n";
    for (auto& step : this->transitions) {
        res += step.stepToString() + ";\n\n";
    }
    return res;
}
