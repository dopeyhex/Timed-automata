#include "../headers/clock.h"

Clock::Clock(const std::string& str) {
    // input check
    std::regex pattern("^\\s*(\\w+)\\s*$");
    std::smatch sm;
    if (std::regex_search(str, sm, pattern)) {
        this->cl = static_cast<std::string>(sm[1]);
    } else {
        throw std::runtime_error("Wrong input for clock");
    }
};

bool Clock::operator==(Clock rhs) {
    if (rhs.clockToString() == "")
        return false;
    else
        return rhs.cl == this->cl;
}

std::string Clock::clockToString() {
    return this->cl;
}

size_t Clock::getClockValue() {
    return this->value;
}

void Clock::setClockValue(size_t val) {
    this->value = val;
}
