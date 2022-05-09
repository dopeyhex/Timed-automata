# A toy timed automata with a region graph
## Build
```
cd build
cmake .
make
./main
```
## Timed automata description
``clock.h`` -- definition of clock; clock has a name and a value (for proper simulation if needed).

``cc.h`` -- definition of clock constraint; CC runs a clock simulation and closes when it reaches maxClockVal defined by user. For example, "a<=20" is a CC for a clock "a". 

``loc.h`` -- definition of location; location is a vertex of TA graph with a name and some CC defined by user. Clock constraints in locations recognize either "<=" or "<". For example, state "start" with CCs "a<=20" and "b<=25".

``step.h`` -- definition of transition in TA; transition runs when specific conditions are met, for example, "a<=13". Transitions recognize "<=", "<", ">", and ">=".

``ta.h`` -- definition of timed automata; TA consists of locations and transitions between them. 

### TODO
Code optimization and refactoring

## Region graph description

``graph.h`` -- definition of the region graph with reachability check
