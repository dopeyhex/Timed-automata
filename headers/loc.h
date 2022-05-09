#pragma once

#include "cc.h"

class Loc {
private:
    std::string loc_ = "";
    std::vector<ClockConstraint> inv_;

public:
    Loc() {};
    Loc(const std::string& loc) : loc_(loc) {};
    Loc(const std::string& loc, std::vector<ClockConstraint> inv) : loc_(loc), inv_(inv) {};
    ~Loc() {};

    std::string getLoc();
    std::vector<ClockConstraint> getCC();

    bool operator==(Loc rhs);

    void addCC(ClockConstraint& constraint);

    std::string locToString();
};
