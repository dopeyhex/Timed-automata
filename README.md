# A toy timed automata for FM-CPS course
Note: this is an ineffective implementation which strictly follows the definitions.

```
Timed automata properties:
Clocks:
a; b; 

States (Locations X Eval(C)):
start: a<=5 && b<=3;
loc1: a<=10 && b<=9;
loc2: a<=15 && b<=17;
finish: a<=20 && b<=25;

Transitions:
start->loc1:
guards: b<=30;
resets:
a:=0;
action: alpha;

loc1->loc2:
guards: a<=8 && b<=6;
resets:
action: alpha;

loc2->finish:
guards: a<=13;
resets:
action: alpha;

finish->start:
guards: a<=17 && b<=20;
resets:
a:=0;
b:=0;
action: alpha;


Is state finish: a<=20 && b<=25 reachable?
Yes
```

## Build
You will need g++-11 and CMake.

```
cd build
cmake .
make
./main
```
## Timed automata description

``clock.h`` -- definition of clock; clock has a name and a value (it could be used for proper simulation).

``cc.h`` -- definition of clock constraint; CC runs a clock simulation and closes when it reaches maxClockVal defined by user. For example, "a<=20" is a CC for a clock "a". For the sake of simplicity, maxClockVals are integers.

``state.h`` -- definition of state; state is a vertex of TA graph with a name of location and some CC defined by user. Clock constraints in locations recognize either "<=" or "<". For example, state "start" with CCs "a<=20" and "b<=25". For the sake of simplicity, in each state user should describe all of the clocks used in the TA in the right order.

``step.h`` -- definition of transition in TA; transition runs when specific conditions are met, for example, "a<=13", and resets specific clock (or clocks, if somehow needed). Transitions recognize "<=", "<", ">", and ">=". For the sake of simplicity, the guards should be integers.

``ta.h`` -- definition of timed automata; TA consists of states and transitions between them. 

## Region description

A *clock region* is a part of the n-dimensional unit hypercube, where n is the number of clocks, under (or above) the hyperplane defined by relations between clocks in a particular state. For example, region

<img src="img/graph1.svg" alt="graph1" width="300"/>

is defined by 

<img src="img/eq1.svg" alt="eq1" width="120"/>

## Zone graph description

Based on work of Rajeev Alur

As this implementation uses integer values of clocks instead of real, it's appropriate to consider convex unions of clock regions rather then looking at them separately.

A *clock zone* is a set of clock interpretations described by conjuction of clock constraints, each of which put a lower or upper bound on a clock or on difference of two clocks. Clock zone is a convex set in the n-dimensional euclidean space.

* For two CZs ???? and ?? their intersection is ?????????;
* For a clock zone ??, ?? ??? denotes the set of interpretations ?? + ?? for ?? ??? ??
and ?? ??? IR;
* For a subset ?? of clocks and a clock zone ??, ??[?? := 0] denotes the set of
clock interpretations ??[?? := 0] for ?? ??? ??;

With this three operations it is possible to analyze the reachability.

A **zone** is a pair (location, *clock zone*).

A switch is a tuple e = (l, ??, ??, ??, s') for zone (l, ??) which determines it's successor (l', succ(??, e)), where

succ(??, e) = (((?? ??? I(s)) ???) ??? I(s) ??? ??)[?? := 0].

In my implementation switch is basically an offset of vector os Zones, because every location and clock are ordered.

*Zone automation* is a new transition system, which states are zones and transitions are switches.

``zone.h`` -- definition of zone;

``graph.h`` -- definition of the zone graph with reachability check. Zone graph consists of zones.


## TODO
Code optimization and refactoring

Concurrency