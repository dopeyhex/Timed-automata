# A toy timed automata with a region graph for FM-CPS course
## Build
You will need C++20 and CMake.

```
cd build
cmake .
make
./main
```
## Timed automata description
``clock.h`` -- definition of clock; clock has a name and a value (for proper simulation if needed).

``cc.h`` -- definition of clock constraint; CC runs a clock simulation and closes when it reaches maxClockVal defined by user. For example, "a<=20" is a CC for a clock "a". 

``state.h`` -- definition of state; state is a vertex of TA graph with a name of location and some CC defined by user. Clock constraints in locations recognize either "<=" or "<". For example, state "start" with CCs "a<=20" and "b<=25".

``step.h`` -- definition of transition in TA; transition runs when specific conditions are met, for example, "a<=13", and resets specific clock (or clocks, if somehow needed). Transitions recognize "<=", "<", ">", and ">=". For obvious reasons, this TA is discrete, so time transitions are not implemented.

``ta.h`` -- definition of timed automata; TA consists of states and transitions between them. 

### TODO
Code optimization and refactoring.

## Region graph description

Firsty, for each state clocks' minimum and maximum values (depending on constraints) are stored. 

``region.h`` -- definition of region; each region is a part of the n-dimensional unit hypercube, where n is the number of clocks, under (or above) the hyperplane defined by relations between clocks in a particular state. For example, region

<img src="img/graph1.svg" alt="graph1" width="300"/>

is defined by 

$\begin{cases}0<x<1\\0<y<1\\x<y\end{cases}$

``graph.h`` -- definition of the region graph with reachability check. Region graph consists of regions.
 
