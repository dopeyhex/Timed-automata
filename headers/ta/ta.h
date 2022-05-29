#pragma once

#include "step.h"

class TA {
private:
    std::vector<Clock> clocks;
    std::vector<State> states;
    std::vector<Step> transitions;
    // min and max values for each clock to get to the next transition
public:
    TA() {};
    ~TA() {};

    void setClocks(std::vector<std::string>& clocks);
    void setLocs(std::vector<std::string>& locs);
    void setStates(std::vector<State>& states);

    void addInv(std::string& cons, std::string& state);
    void addTransition(const State& now, const State& next,
         const std::vector<ClockConstraint>& guards,
         const std::vector<Clock>& reset,
         const std::string& action);

    const std::vector<Clock> getClocks() const;
    const std::vector<State> getLocs() const;
    const std::vector<Step> getSteps() const;

    std::string taToString();
};
