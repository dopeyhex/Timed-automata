#pragma once

#include <vector>
#include "cc.h"

class State {
private:
    std::string state = "";
    std::vector<ClockConstraint> inv;

public:
    State() {};
    State(const std::string& st) : state(st) {};
    ~State() {};

    std::string getState();

    bool operator==(State rhs);

    void addInv(ClockConstraint& constraint);

    std::string stateToString();
};
