#include "../headers/ta.h"

void TA::setClocks(std::vector<std::string>& clocks) {
    for (auto& clock : clocks) {
        this->clocks.push_back(clock);
    }
}

void TA::setStates(std::vector<std::string>& states) {
    for (auto& state : states) {
        if (std::find(this->states.begin(), this->states.end(), state) == this->states.end()) {
            this->states.push_back(state);
        } else {
            throw std::runtime_error("State is already added");
        }
    }
}

void TA::addConstraint(std::string& cons, std::string& state) {
    if (std::find(this->states.begin(), this->states.end(), state) != this->states.end()) {
        State tmpState;
        for (auto& st : this->states) {
            if (st.getState() == state) {
                tmpState = st;
                break;
            }
        }

        //input check
        std::regex pattern("^\\s*(\\w)\\s*([<>]?=?\\s*\\d+)\\s*$");
        std::smatch sm;
        if (std::regex_search(cons, sm, pattern)) {
            Clock tmpClock(static_cast<std::string>(sm[1]));
            if (std::find(this->clocks.begin(), this->clocks.end(), tmpClock) != this->clocks.end()) {
                ClockConstraint tmpCons(tmpClock, static_cast<std::string>(sm[2]));
                tmpState.addInv(tmpCons);
            } else {
                throw std::runtime_error("Clock was not added");
            }
        } else {
            throw std::runtime_error("Added constraint is not in the right format");
        }
    } else {
        throw std::runtime_error("State was not added");
    }
}

std::vector<Clock> TA::getClocks() {
    return this->clocks;
}

std::vector<State> TA::getStates() {
    return this->states;
}

std::string TA::taToString() {
    std::string res = "clocks : ";
    for (auto& clock : this->clocks)
        res += clock.clockToString() + "; ";
    res += "\nstates : ";
    for (auto& state : this->states)
        res += state.stateToString() + "; ";
    return res;
}