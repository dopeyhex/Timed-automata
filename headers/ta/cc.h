#pragma once

#include "clock.h"

class ClockConstraint {
private:
    Clock clock;
    std::string op = "";
    size_t maxClockVal;
public:
    ClockConstraint(Clock& c, const std::string& cons);
    ClockConstraint(const std::string& cons);
    ~ClockConstraint() {};

    const Clock& getClock() const;
    const std::string& getOp() const;
    const int getClockVal() const;

    bool isPrevClosed();

    friend bool operator> (const ClockConstraint& rhs, const ClockConstraint& lhs);

    std::string ccToString();
};
