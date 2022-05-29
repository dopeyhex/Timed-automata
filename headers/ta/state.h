#pragma once

#include "cc.h"

class State {
private:
    std::string loc_ = "";
    std::vector<ClockConstraint> inv_;

public:
    State() {};
    State(const std::string& state) : loc_(state) {};
    State(const std::string& state, std::vector<ClockConstraint> inv) : loc_(state), inv_(inv) {};
    ~State() {};

    const std::string getLoc() const;
    const std::vector<ClockConstraint> getCC() const;

    const bool operator==(State rhs) const;

    void addCC(ClockConstraint& constraint);

    std::string locToString();
};
