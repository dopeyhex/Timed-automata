#pragma once

#include "clock.h"

class ClockConstraint {
private:
    Clock clock;
    std::string op = "";
    int clockVal;
    bool prevClosed = false;

public:
    ClockConstraint(const Clock& c, const std::string& s);
    ~ClockConstraint() {};

    Clock& getClock();
    std::string& getOp();
    int getClockVal();

    bool isPrevClosed();

    std::string ccToString();
};