#pragma once

#include "utils.h"

class Clock {
private:
    std::string cl = "";
    size_t value = 0;
public:
    Clock() {};
    Clock(const std::string& str);
    ~Clock() {};

    friend void setClockValue(Clock& clock, size_t val);
    const size_t getClockValue() const;
    const bool operator==(Clock rhs) const;

    const std::string clockToString() const;
};
