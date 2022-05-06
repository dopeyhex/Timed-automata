#pragma once

#include <regex>
#include <stdexcept>
#include <string>

class Clock {
private:
    std::string cl = "";

public:
    Clock() {};
    Clock(const std::string& str);
    ~Clock() {};

    std::string clockToString();

    bool operator==(Clock rhs);
};
