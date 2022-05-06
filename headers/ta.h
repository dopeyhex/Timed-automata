#pragma once

#include "state.h"

class TA {
private:
    std::vector<Clock> clocks;
    std::vector<State> states;
public:
    TA() {};
    ~TA() {};

    void setClocks(std::vector<std::string>& clocks);
    void setStates(std::vector<std::string>& states);

    void addConstraint(std::string& cons, std::string& state);

    std::vector<Clock> getClocks();
    std::vector<State> getStates();

    std::string taToString();
};
