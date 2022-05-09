#pragma once

#include "loc.h"

struct Step {
    Loc now_, next_;
    std::vector<ClockConstraint> guards_;
    std::vector<Clock> reset_;
    std::string action_;

    Step() {};
    Step(const Loc& now, const Loc& next,
         const std::vector<ClockConstraint>& guards,
         const std::vector<Clock>& reset,
         const std::string& action) :
            now_(now), next_(next),
            guards_(guards), reset_(reset),
            action_(action) {};
    ~Step() {};

    std::string stepToString();
};