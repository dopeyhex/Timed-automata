# A toy timed automata with a region graph
## Build
```
cd build
cmake .
make
./main
```
## Timed automata description
``clock.h`` -- definition of clock

``cc.h`` -- definition of clock constraint

``loc.h`` -- definition of location with clock constraints

``ta.h`` -- definition of timed automata

Each class has a function to represent it as a string for further optimizations.

### TODO:
Change representation from string to proper class in main 

## Region graph description

``graph.h`` -- definition of the region graph with reachability check
