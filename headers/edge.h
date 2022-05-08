#pragma once

#include "loc.h"

class Edge {
private:
    Loc now_, next_;
    std::vector<ClockConstraint> guards_;
    std::vector<Clock> resets_;
    std::string action_;
public:
    Edge() {};
    Edge(const Loc& now, const Loc& next,
         const std::vector<ClockConstraint>& guards,
         const std::vector<Clock>& resets,
         const std::string& action) :
            now_(now), next_(next),
            guards_(guards), resets_(resets),
            action_(action) {};
    ~Edge() {};
};