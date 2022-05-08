#pragma once

#include <regex>
#include <stdexcept>
#include <string>

class Clock {
private:
    std::string cl = "";
    size_t value = 0;
public:
    Clock() {};
    Clock(const std::string& str);
    ~Clock() {};

    void setClockValue(size_t val);
    size_t getClockValue();

    bool operator==(Clock rhs);

    std::string clockToString();
};
