#pragma once

#include "step.h"

class TA {
private:
    std::vector<Clock> clocks;
    std::vector<Loc> locs;
    std::vector<Step> transitions;
    // min and max values for each clock to get to the next transition
public:
    TA() {};
    ~TA() {};

    void setClocks(std::vector<std::string>& clocks);
    void setLocs(std::vector<std::string>& locs);
    void setLocs(std::vector<Loc>& locs);

    void addInv(std::string& cons, std::string& loc);
    void addTransition(const Loc& now, const Loc& next,
         const std::vector<ClockConstraint>& guards,
         const std::vector<Clock>& reset,
         const std::string& action);

    std::vector<Clock> getClocks();
    std::vector<Loc> getLocs();

    std::string taToString();
};
