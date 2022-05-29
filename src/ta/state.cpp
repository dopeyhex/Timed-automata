#include "../../headers/ta/state.h"

const std::string State::getLoc() const {
    return this->loc_;
}

const std::vector<ClockConstraint> State::getCC() const {
    return this->inv_;
};

const bool State::operator==(State rhs) const {
    if (rhs.getLoc() == "")
        return false;
    else 
        return this->loc_ != "" ? this->loc_ == rhs.loc_ : rhs.loc_ == "";
}

void State::addCC(ClockConstraint& constraint) {
    for (auto& cc : this->inv_) {
        if (cc > constraint) {
            cc = constraint;
        }
    }
}

std::string State::locToString() {
    if (this->inv_.size() == 0)
        return this->loc_;
    std::string tmp = "";
    for (size_t i = 0; i < this->inv_.size() - 1; ++i)
        tmp += this->inv_[i].ccToString() + " && ";
    tmp += this->inv_[this->inv_.size()-1].ccToString();
    return this->loc_ + ": " + tmp;
}