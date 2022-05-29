#include "../../headers/ta/cc.h"

#include <iostream>

ClockConstraint::ClockConstraint(Clock& c, const std::string& cons) {
    //input check
    std::regex pattern("^([<>]?=?)\\s*(\\d+)$");
    std::smatch sm;
    if (std::regex_search(cons, sm, pattern)) {
        this->op = static_cast<std::string>(sm[1]);
        this->maxClockVal = std::stoi(static_cast<std::string>(sm[2]));
        this->clock = c;
        size_t val = this->clock.getClockValue();
    } else {
        throw std::runtime_error("Added constraint is not in the right format");
    }
};

ClockConstraint::ClockConstraint(const std::string& cons) {
    std::regex pattern("^\\s*(\\w)\\s*([<>]?=?\\s*\\d+)\\s*$");
        std::smatch sm;
        if (std::regex_search(cons, sm, pattern)) {
            Clock tmpClock(static_cast<std::string>(sm[1]));
            *this = ClockConstraint(tmpClock, static_cast<std::string>(sm[2]));
        } else {
            throw std::runtime_error("Added constraint is not in the right format");
        }
}

const Clock& ClockConstraint::getClock() const {
    return this->clock;
}

const std::string& ClockConstraint::getOp() const {
    return this->op;
}

const int ClockConstraint::getClockVal() const {
    return this->maxClockVal;
}

std::string ClockConstraint::ccToString() {
    return this->clock.clockToString() + this->op + std::to_string(this->maxClockVal);
}

bool operator> (const ClockConstraint& rhs, const ClockConstraint& lhs) {
    if ((rhs.getClock() == lhs.getClock()) &&
        (rhs.getOp() == lhs.getOp()) && 
        (rhs.getClockVal() > lhs.getClockVal())) {
            return true;
    } else {
        return false;
    }
}