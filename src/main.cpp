#include "../headers/regions/graph.h"

#include <iostream>

int main() {
    TA ta;
    std::vector<std::string> clocks = {"a", "b"};
    ta.setClocks(clocks);

    /* 
    There are two ways of defining locations.
    The first one is to add locations and then add invariants to them:

    std::vector<std::string> locs = {"start", "state 1", "state 2", "finish"};
    ta.setLocs(locs);
    
    std::vector<std::string> constrainta = {"a<=20", "a<=15", "a<=10", "a<=5"};
    std::vector<std::string> constraintb = {"b<=25", "b<=17", "b<=9", "b<=3"};
    for (size_t i = 0; i < locs.size(); ++i) {
        ta.addInv(constrainta[i], locs[i]);
        ta.addInv(constraintb[i], locs[i]);
    }
    
    The second one is to create locations with invariants:
    */

    std::vector<ClockConstraint> consfin = {ClockConstraint(static_cast<std::string>("a<=20")), ClockConstraint(static_cast<std::string>("b<=25"))},
                                 consloc2 = {ClockConstraint(static_cast<std::string>("a<=15")), ClockConstraint(static_cast<std::string>("b<=17"))},
                                 consloc1 = {ClockConstraint(static_cast<std::string>("a<=10")), ClockConstraint(static_cast<std::string>("b<=9"))},
                                 constart = {ClockConstraint(static_cast<std::string>("a<=5")), ClockConstraint(static_cast<std::string>("b<=3"))},
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
                                 consedge4 = {ClockConstraint(static_cast<std::string>("a<=17")), ClockConstraint(static_cast<std::string>("b<=20"))},
                                 consedge3 = {ClockConstraint(static_cast<std::string>("a<=13"))},
                                 consedge2 = {ClockConstraint(static_cast<std::string>("a<=8")), ClockConstraint(static_cast<std::string>("b<=6"))},
                                 consedge1 = {ClockConstraint(static_cast<std::string>("b<=30"))};
    // ...Yep, C++ was a bad idea...
    State start("start", constart);
    State loc1("loc1", consloc1);
    State loc2("loc2", consloc2);
    State finish("finish", consfin);
    std::vector<State> states = {start, loc1, loc2, finish};

    ta.setStates(states);
    std::string invvv = "a<=14";
    std::string loccc = "loc1";
    ta.addInv(invvv, loccc);
    // Define automata's transitions
    ta.addTransition(start, loc1, consedge1, std::vector<Clock>{}, "alpha");
    ta.addTransition(loc1, loc2, consedge2, std::vector<Clock>{}, "alpha");
    ta.addTransition(loc2, finish, consedge3, std::vector<Clock>{}, "alpha");
    ta.addTransition(finish, start, consedge4, std::vector<Clock>{}, "alpha");
    std::cout << "Timed automata properties:\n" << ta.taToString() << std::endl;
    Graph graph(ta);
    /*
    State start("a");
    State finish("d");
    std::cout << (graph.isReachable(start, finish) ? "Yes" : "No");*/
    return 0;
}