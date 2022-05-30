#include "../../headers/zones/zone.h"

Zone::Zone(std::string loc, size_t N_clocks, std::vector<BoundedState> bs) :
    location(loc),
    dbm(std::vector<std::vector<int64_t> >(N_clocks+1, std::vector<int64_t>(N_clocks+1, INT64_MAX))) {
        for (size_t i = 0; i < N_clocks+1; ++i) {
            for (size_t j = 0; j < N_clocks+1; ++j) {
                if (i == 0 && j == 0) dbm[i][j] = 0;
                else if (i == 0 && j != 0) {
                    dbm[i][j] = bs[j-1].max_bound;
                } else if (j == 0 && i != 0) {
                    dbm[i][j] = bs[i-1].min_bound;
                } else {
                    int64_t tmp = static_cast<int64_t>(bs[j-1].max_bound) - static_cast<int64_t>(bs[i-1].min_bound);
                    dbm[i][j] = (tmp > 0 ? tmp : -tmp);
                }
                // Actually, here should be a pair of values, 
                // (difference, severity), which should take an infinite value if clocks aren't comparable
                // But I want to keep it as simple as possible :)
            }
        }
}

bool operator== (const Zone& lhs, const Zone& rhs) {
    for (size_t i = 0; i < lhs.dbm.size(); ++i) {
        for (size_t j = 0; j < lhs.dbm.size(); ++j) {
            if (rhs.dbm[i][j] - lhs.dbm[i][j] != 0) return false;
        }
    }

    return true;
}

bool operator>= (const Zone& lhs, const Zone& rhs) {
    for (size_t i = 0; i < lhs.dbm.size(); ++i) {
        for (size_t j = 0; j < lhs.dbm.size(); ++j) {
            if (lhs.dbm[i][j] < rhs.dbm[i][j]) return false;
        }
    }

    return true;
}