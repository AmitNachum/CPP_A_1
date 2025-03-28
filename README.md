# README - Graph Algorithms Project 
# Name: Amit Nachum
# Role: student


## Project Overview

This project is an implementation of various graph algorithms using C++ without the use of STL data structures (like vectors or standard priority queues). The project includes implementations of:

- Graphs (Adjacency List Representation)
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Kruskal's Algorithm (Minimum Spanning Tree)
- Prim's Algorithm (Minimum Spanning Tree)
- Dijkstra's Algorithm (Shortest Path Tree)
- Disjoint Set (Union-Find)
- Custom Priority Queue
- Stack and Queue Implementations

## File Structure

The project is structured as follows:

```
- graph/         (Contains Graph and algorithms files)
- Priority_Queue/(Contains Priority Queue files)
- Queue/         (Contains Queue files)
- Stack/         (Contains Stack files)
- Union_Find/    (Contains Union-Find files)
```

## Compilation Instructions

### Testing Output (Actual Output Generation)

To compile the `testingOutputG.cpp` file, use the `testingOutputG.mk` makefile under the  EX_Uni directory with the following command:

```
make -f testingOutputG.mk
```

To run the executable with memory leak checking using Valgrind:

```
valgrind ./testingOutputG
```

### Doctest Testing (Unit Testing)

To compile the `testG.cpp` file (Doctest), use the `testG.mk` makefile under the  EX_Uni directory with the following command:

```
make -f testG.mk
```

To run the executable with memory leak checking using Valgrind:

```
valgrind ./testG
```

### Individual Data Structures (Unit Testing with Doctest)

Each data structure folder contains a `makefile` specifically designed for testing its respective implementation with Doctest. To compile and run these tests, navigate to the folder and use:

```
make
```

Run the test:

```
./<Executable_Name>
```

Check for memory leaks:

```
valgrind ./<Executable_Name>
```

## Notes

- Make sure all paths are correctly set in the `#include` directives.
- The Makefiles are structured to detect and compile files based on their respective paths.
