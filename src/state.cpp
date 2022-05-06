#include "../headers/state.h"

std::string State::getState() {
    return state;
}

bool State::operator==(State rhs) {
    if (rhs.getState() == "")
        return false;
    else 
        return this->state != "" ? this->state == rhs.state : rhs.state == "";
}

void State::addInv(ClockConstraint& constraint) {
    if (constraint.isPrevClosed())
        this->inv.push_back(constraint);
    else
        throw std::runtime_error("CC was not closed");
}

std::string State::stateToString() {
    if (this->inv.size() == 0)
        return this->state;
    std::string tmp = "";
    for (std::size_t i = 0; i < this->inv.size() - 1; ++i)
        tmp += this->inv[i].ccToString() + "&&";
    tmp += this->inv[this->inv.size()-1].ccToString();
    return this->state + ": " + tmp;
}