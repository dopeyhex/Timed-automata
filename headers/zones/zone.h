#pragma once

#include "ta.h"

// Each is a part of 1x1x...x1 hypercube

class Zone {
private:
    std::vector<std::vector<size_t> > points;
public:
    Zone(std::vector<size_t>& origin);
    Zone();
    ~Zone();
};