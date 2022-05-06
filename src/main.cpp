#include "../headers/graph.h"
#include <iostream>

int main() {
    TA ta;
    std::vector<std::string> clocks = {"a", "b", "c", "d"};
    std::vector<std::string> states = {"start", "state 1", "state 2", "finish"};
    std::string state = "start", consa = "a<=10", 
                                 consb = "b<=5", 
                                 consc = "c<=3",
                                 consd = "d<=2";
    ta.setClocks(clocks);
    ta.setStates(states);
    ta.addConstraint(consa, state);
    ta.addConstraint(consb, state);
    ta.addConstraint(consc, state);
    ta.addConstraint(consd, state);
    std::cout << "Timed automata properties:\n" << ta.taToString() << std::endl;

    State start("a");
    State finish("d");
    //Graph graph(ta);
    //std::cout << (graph.isReachable(start, finish) ? "Yes" : "No");
    return 0;
}