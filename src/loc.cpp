#include "../headers/loc.h"

std::string Loc::getLoc() {
    return this->loc_;
}

std::vector<ClockConstraint> Loc::getCC() {
    return this->inv_;
};

bool Loc::operator==(Loc rhs) {
    if (rhs.getLoc() == "")
        return false;
    else 
        return this->loc_ != "" ? this->loc_ == rhs.loc_ : rhs.loc_ == "";
}

void Loc::addInv(ClockConstraint& constraint) {
    if (constraint.isPrevClosed())
        this->inv_.push_back(constraint);
    else
        throw std::runtime_error("CC was not closed");
}

std::string Loc::locToString() {
    if (this->inv_.size() == 0)
        return this->loc_;
    std::string tmp = "";
    for (std::size_t i = 0; i < this->inv_.size() - 1; ++i)
        tmp += this->inv_[i].ccToString() + " && ";
    tmp += this->inv_[this->inv_.size()-1].ccToString();
    return this->loc_ + ": " + tmp;
}