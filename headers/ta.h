#pragma once

#include "edge.h"

class TA {
private:
    std::vector<Clock> clocks;
    std::vector<Loc> locs;
    std::vector<Edge> edges;
public:
    TA() {};
    ~TA() {};

    void setClocks(std::vector<std::string>& clocks);
    void setLocs(std::vector<std::string>& locs);
    void setLocs(std::vector<Loc>& locs);

    void addInv(std::string& cons, std::string& loc);
    void addEdge(const Loc& now, const Loc& next,
         const std::vector<ClockConstraint>& guards,
         const std::vector<Clock>& resets,
         const std::string& action);

    std::vector<Clock> getClocks();
    std::vector<Loc> getLocs();

    std::string taToString();
};
