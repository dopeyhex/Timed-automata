#include "../../headers/ta/clock.h"

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

const bool Clock::operator==(Clock rhs) const{
    if (rhs.clockToString() == "")
        return false;
    else
        return rhs.cl == this->cl;
}

const std::string Clock::clockToString() const {
    return this->cl;
}

const size_t Clock::getClockValue() const {
    return this->value;
}

void setClockValue(Clock& clock, size_t val) {
    clock.value = val;
}
