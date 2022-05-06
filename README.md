# A toy timed automata with a region graph
## Build
```
cd build
cmake .
make
./main
```
## Project description
``clock.h`` -- definition of clock

``cc.h`` -- definition of clock constraint

``state.h`` -- definition of state (or location) with clock constraints

``ta.h`` -- definition of timed automata

Each class has a function to represent it as a string, clock and state have equality check.

``graph.h`` -- definition of the region graph with reachability check
