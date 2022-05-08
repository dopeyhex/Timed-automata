#include "../headers/cc.h"

ClockConstraint::ClockConstraint(const Clock& c, const std::string& cons) {
    //input check
    std::regex pattern("^([<>]?=?)\\s*(\\d+)$");
    std::smatch sm;
    if (std::regex_search(cons, sm, pattern)) {
        this->op = static_cast<std::string>(sm[1]);
        this->clockVal = std::stoi(static_cast<std::string>(sm[2]));
        this->clock = c;
        if (this->op == "<" || this->op == "<=")
            this->prevClosed = true;
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

Clock& ClockConstraint::getClock() {
    return this->clock;
}

std::string& ClockConstraint::getOp() {
    return this->op;
}

int ClockConstraint::getClockVal() {
    return this->clockVal;
}

bool ClockConstraint::isPrevClosed() {
    return this->prevClosed;
}

std::string ClockConstraint::ccToString() {
    return this->clock.clockToString() + this->op + std::to_string(this->clockVal);
}