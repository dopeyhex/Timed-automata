#include "../headers/ta.h"

void TA::addInv(std::string& cons, std::string& loc) {
    for (auto& l : this->locs) {
        if (l.getLoc() == loc) {
            // input check
            std::regex pattern("^\\s*(\\w)\\s*([<>]?=?\\s*\\d+)\\s*$");
            std::smatch sm;
            if (std::regex_search(cons, sm, pattern)) {
                Clock tmpClock(static_cast<std::string>(sm[1]));
                if (std::find(this->clocks.begin(), this->clocks.end(), tmpClock) != this->clocks.end()) {
                    ClockConstraint tmpCons(tmpClock, static_cast<std::string>(sm[2]));
                    l.addInv(tmpCons);
                } else {
                    throw std::runtime_error("Clock was not added");
                }
            } else {
                throw std::runtime_error("Added constraint is not in the right format");
            }
            break;
        }
    }
}

void TA::addEdge(const Loc& now, const Loc& next,
        const std::vector<ClockConstraint>& guards,
        const std::vector<Clock>& resets,
        const std::string& action) {
        this->edges.emplace_back(now, next, guards, resets, action);
    for (auto& clock : resets) {
        for (auto& cl : this->clocks) {
            if (cl == clock)
                cl.setClockValue(0);
        }
    }
}

void TA::setClocks(std::vector<std::string>& clocks) {
    for (auto& clock : clocks) {
        this->clocks.push_back(clock);
    }
}

void TA::setLocs(std::vector<std::string>& locs) {
    for (auto& loc : locs) {
        if (std::find(this->locs.begin(), this->locs.end(), loc) == this->locs.end()) {
            this->locs.push_back(loc);
        } else {
            throw std::runtime_error("Loc is already added");
        }
    }
}

void TA::setLocs(std::vector<Loc>& locs) {
    for (auto& loc : locs) {
        if (std::find(this->locs.begin(), this->locs.end(), loc) == this->locs.end()) {
            this->locs.push_back(loc);
        } else {
            throw std::runtime_error("Loc is already added");
        }
    }
}

std::vector<Clock> TA::getClocks() {
    return this->clocks;
}

std::vector<Loc> TA::getLocs() {
    return this->locs;
}

std::string TA::taToString() {
    std::string res = "clocks: ";
    for (auto& clock : this->clocks)
        res += clock.clockToString() + "; ";
    res += "\nlocs:\n";
    for (auto& loc : this->locs) {
        res += loc.locToString() + ";\n";
    }
    return res;
}