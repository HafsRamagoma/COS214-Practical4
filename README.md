# TaskForge — Film Production Work Processing System

COS 214 Practical 4 (2026). A hierarchical work-processing system for the **film production**
domain, implemented in C++11 using the Iterator, Composite, State and Decorator patterns.

## Domain

A `FilmComponent` tree models a movie's production hierarchy: a movie project contains
production phases (Pre-Production, Production, Post-Production), each phase contains
individual `TaskItem`s (e.g. "Write Script", "Main Filming"). Groups and individual tasks are
treated uniformly through the shared `FilmComponent` interface (Composite).

Each `TaskItem` has a production lifecycle (State): `NotStarted → InProgress → Blocked/
NeedsReshoot/Completed/Cancelled`, with invalid transitions rejected rather than crashing.

Two independent ways of traversing the hierarchy are provided (Iterator):

- **`DepthFirstIterator`** — visits every node in the tree (groups and tasks).
- **`PendingtaskIterator`** — visits only leaf tasks that are not yet completed.

Both are **snapshot iterators**: the set of nodes to visit is captured once, at construction
time, so an iterator's traversal is unaffected by structural changes (add/remove/state change)
made to the tree after the iterator was created. Iterators should be discarded before making
structural changes you want reflected in a *new* traversal.

Optional responsibilities can be layered onto a task at runtime without subclassing (Decorator):
`OvertimeDecorator` adds a flat overtime supercharge on top of a task's cost, and
`EquipmentDecorator` adds a named piece of rented equipment and its rental cost. Both delegate
`request()` to the wrapped component first, then log their own behaviour on top — and both can be
stacked on the same `FilmComponent`, since a decorator is itself a `FilmComponent`.

## Repository Layout

```
.
├── FilmComponent.{h,cpp}       # Composite base (Component)
├── WorkGroup.{h,cpp}           # Composite (group of tasks/groups)
├── TaskItem.{h,cpp}            # Leaf; owns a TaskState
├── FilmIterator.{h,cpp}        # Iterator interface
├── DepthFirstIterator.{h,cpp}  # Concrete Iterator: visits all nodes
├── PendingtaskIterator.{h,cpp} # Concrete Iterator: visits pending leaf tasks only
├── TaskState.{h,cpp}           # State base
├── NotStarted / InProgress / Blocked / NeedsReshoot / Completed / Cancelled	# Concrete States
│                                	
├── TaskDecorator.{h,cpp}       # Decorator base
├── OvertimeDecorator.{h,cpp}   # Concrete Decorator: flat overtime surcharge
├── EquipmentDecorator.{h,cpp}  # Concrete Decorator: named equipment + rental cost
├── SafetyDecorator.{h,cpp}     
├── main.cpp                    # Demo scenarios / manual test driver
├── makefile
├── Dockerfile
└── docs/                       # UML diagrams, PDF write-up material
```

## Building

Requires `g++` and `make`. The project compiles with `-std=c++11`, and
produces an executable named `taskforge`.

```bash
make            # builds the executable
make clean      # removes object files and the executable
```

## Running

```bash
./taskforge
```

This runs two demo scenarios from `main.cpp`:

1. Builds a 3-level movie hierarchy, prints the full structure and budget, then iterates only
   the pending tasks.
2. `taskTesting()` — drives a single task through its full lifecycle (including a rejected
   invalid transition) and demonstrates the pending-task iterator excluding a completed task.

## Debugging

### GDB

```bash
make            # -g is already in CXXFLAGS, so the build is debug-ready
gdb ./taskforge
(gdb) break WorkGroup::getCost
(gdb) run
(gdb) next
(gdb) print total
(gdb) backtrace
```

### Valgrind

```bash
make valgrind
# or directly:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./taskforge
```

The final submission must show no definitely-lost memory originating from project code.

## Docker

An Ubuntu 22.04-based `Dockerfile` is provided at the repository root with `g++`, `make`, `gdb`
and `valgrind` installed, and builds `taskforge` automatically as part of the image.

```bash
docker build -t taskforge .
docker run --rm -it taskforge                 # runs ./taskforge
docker run --rm -it --entrypoint bash taskforge   # drop into a shell for gdb/valgrind
```

Inside that shell, the GDB and Valgrind commands above work exactly as on the host.


## Patterns Reference (GoF participants)

| Pattern   | Participant              | Class(es)                                                   			  |
|-----------|------------------------- |----------------------------------------------------------------------------------|
| Composite | Component                | `FilmComponent`                                              			  |
|           | Leaf                     | `TaskItem`                                                    			  |
|           | Composite                | `WorkGroup`                                                   			  |
| Iterator  | Iterator                 | `FilmIterator`                                                 		  |
|           | ConcreteIterator         | `DepthFirstIterator`, `PendingtaskIterator`                     		  |
|           | Aggregate/ConcreteAggregate | `FilmComponent` (factory methods), `WorkGroup`, `TaskItem`  		  |
| State     | Context                  | `TaskItem`                                                     		  |
|           | State                    | `TaskState`                                                    		  |
|           | ConcreteState            | `NotStarted`, `InProgress`, `Blocked`, `NeedsReshoot`, `Completed`, `Cancelled`  |
| Decorator | Component                | `FilmComponent`                                                		  |
|           | Decorator                | `TaskDecorator`                                                		  |
|           | ConcreteDecorator        | `OvertimeDecorator`, `EquipmentDecorator` (`SafetyDecorator`) 			  |

## Contributors

	Dirk was responsible for the initial UML draft and design, just to get the team going. They were also responsible for the implementation of the Iterators and their associated alterations in the TaskItem and 	WorkGroup classes. They also set up the initial main.cpp testing file to reach testing and coverage requirements. They were also responsible for the creation of the Object diagram, GitHub workflow overview 	and team contribution statement.  

	Hafani was responsible for the expansion of the State design pattern as well as the alteration of the WorkGroup for adjust to the State changes. They proceeded to host and setup the GitHub repository and 	maintain many of the active merges, functioning as the last reviewer. They created the State diagrams and supported in the implementation of the State, Composite, Leaf and Component classes. 

	Danel was responsible for the maintenance and design of pdf document and the design and expansion of the Decorator design pattern. They also designed the 3 necessary activity diagrams and implemented the 	Decorator design pattern with its associated testing in the main.cpp. This member was in the middle of a medical situation, and yet still brought their part. 
