#include "../headers/graph.h"
#include <iostream>

int main() {
    TA ta;
    std::vector<std::string> clocks = {"a", "b"};
    ta.setClocks(clocks);


    /* Define locations in order of presence in automata; in this case
     start -> loc1 -> loc2 -> finish -> start -> ...

    There are two ways of defining locations.
    The first one is to add locations and then add invariants to them:

    std::vector<std::string> locs = {"start", "loc 1", "loc 2", "finish"};
    ta.setLocs(locs);
    
    std::vector<std::string> constrainta = {"a<=20", "a<=15", "a<=10", "a<=5"};
    std::vector<std::string> constraintb = {"b<=25", "b<=17", "b<=9", "b<=3"};
    for (size_t i = 0; i < locs.size(); ++i) {
        ta.addInv(constrainta[i], locs[i]);
        ta.addInv(constraintb[i], locs[i]);
    }
    
    The second one is to create locations with invariants:
    */

    std::vector<ClockConstraint> constart = {ClockConstraint(static_cast<std::string>("a<=20")), ClockConstraint(static_cast<std::string>("b<=25"))},
                                 consedge1 = {ClockConstraint(static_cast<std::string>("a<=17")), ClockConstraint(static_cast<std::string>("b<=20"))},
                                 consloc1 = {ClockConstraint(static_cast<std::string>("a<=15")), ClockConstraint(static_cast<std::string>("b<=17"))},
                                 consloc2 = {ClockConstraint(static_cast<std::string>("a<=10")), ClockConstraint(static_cast<std::string>("b<=9"))},
                                 consfin = {ClockConstraint(static_cast<std::string>("a<=5")), ClockConstraint(static_cast<std::string>("b<=3"))};
    // ...Yep, C++ was a bad idea...
    Loc start("start", constart);
    Loc loc1("loc1", consloc1);
    Loc loc2("loc2", consloc2);
    Loc finish("finish", consfin);
    std::vector<Loc> locs = {start, loc1, loc2, finish};

    ta.setLocs(locs);
    // Define automata
    ta.addEdge(start, loc1, consedge1, std::vector<Clock>{Clock("a"), Clock("b")}, "alpha");
    std::cout << "Timed automata properties:\n" << ta.taToString() << std::endl;
    /*
    Loc start("a");
    Loc finish("d");
    Graph graph(ta);
    std::cout << (graph.isReachable(start, finish) ? "Yes" : "No");*/
    return 0;
}