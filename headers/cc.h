#pragma once

#include "clock.h"

class ClockConstraint {
private:
    Clock clock;
    std::string op = "";
    size_t maxClockVal;
public:
    ClockConstraint(const Clock& c, const std::string& cons);
    ClockConstraint(const std::string& cons);
    ~ClockConstraint() {};

    Clock& getClock();
    std::string& getOp();
    int getClockVal();

    bool isPrevClosed();

    friend bool operator> (ClockConstraint& rhs, ClockConstraint& lhs);

    std::string ccToString();
};
