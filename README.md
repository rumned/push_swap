*This project has been created as part of the 42 curriculum by `nisim` and `mbin-mus`*

## Description
**push_swap** is a project about sorting data on a stack, with a limited set of instructions, using the lowest possible number of operations. The goal is to sort random integers in ascending order into stack A using an auxiliary stack B.

## Sorting and Stack
- **Sorting** rearranges data to follow a predetermined sequential order.
- **A stack** is a linear data structure following the Last-In, First-Out (LIFO) rule.
- **Open access** is restricted to only one end of the stack.

## Available instructions
The goal is to sort in ascending order numbers into stack a. Only these operations are allowed in this project:
- `sa` (swap a): Swap the first two elements at the top of stack a.
- `sb` (swap b): Swap the first two elements at the top of stack b.
- `ss` : `sa` and `sb` at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): Shift up all elements of stack a by one (first becomes last).
- `rb` (rotate b): Shift up all elements of stack b by one (first becomes last).
- `rr` : `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by one (last becomes first).
- `rrb` (reverse rotate b): Shift down all elements of stack b by one (last becomes first).
- `rrr` : `rra` and `rrb` at the same time.

## Program Output
The program splits its outputs across two standard data streams to allow clean separation of tasks:
- **`stdout` (Standard Output)**: The raw sequence of generated sorting operations, with **each instruction separated strictly by a newline (`\n`)**. Sorting larger datasets will produce thousands of lines.
- **`stderr` (Standard Error)**: Benchmarking metrics (triggered by `--bench`) are routed here so they do not pollute the raw operation stream, making it completely safe to use validation pipes.

## Algorithms and Data Structure
### Core Data Structure
- **Linear Doubly Linked Lists**: Both Stack A and Stack B are implemented as linear doubly linked lists, tracked via a single pointer to the `head` (top of the stack). 
  - **Pushes & Swaps (`pa`/`pb`, `sa`/`sb`)** execute in **O(1) constant time** as they only manipulate the top nodes.
  - **Rotations (`ra`/`rb`, `rra`/`rrb`)** operate in **O(N) linear time** because the algorithm must traverse the entire length of the list from the head to locate and update the bottom (tail) node references.

### Pre-processing Optimization
- **Coordinate Compression (Indexing)**: Before sorting, all input numbers are simplified by indexing them based on their value (e.g., the smallest number becomes `0`, the next becomes `1`, etc.). This eliminates the complexity of handling large gaps, negative values, and integer limits, allowing the core algorithms to safely and efficiently sort based on clean indices from `0` to `N-1`.

### Sorting Framework
This implementation adaptively switches sorting strategies depending on an internal **disorder metric** calculated post-indexing:

- **Simple Sort** (`--simple`): Uses **Insertion Sort** paired with greedy utility functions to calculate the cheapest element movement costs.
- **Medium Sort** (`--medium`): Employs **Chunk Sort** reinforced with the same greedy cost optimizations to efficiently group and sort data.
- **Complex Sort** (`--complex`): Implements a **Dual-Pivot Quicksort** strategy featuring a small sort optimization (when chunks drop to ≤ 3 elements, they are immediately resolved via hardcoded sorting rules).
- **Adaptive Routing** (`--adaptive`): Explicitly triggers the default sorting framework, which automatically shifts between Simple, Medium, or Complex tiers based on the disorder metric.

## Algorithm Justification

Standard sorting algorithms assume random access arrays (`O(1)` indexing). Because `push_swap` relies on sequential stacks where deep access incurs `O(N)` rotation penalties, standard approaches fail. This architecture uses **Adaptive Routing** backed by an architectural **Disorder Metric** (calculated via inversion counting post-indexing) to route execution to the most operation-efficient strategy.

### 1. Simple Sort (Pre-Sorting & Signed Greedy Insertion)
*   **Target:** Highly pre-sorted arrays (low disorder metric).
*   **Complexity:** Time: $O(N^2)$ \| Auxiliary Space: O(1)
*   **Justification:** For tiny lists, algorithmic overhead outweighs instruction savings. This implementation avoids traditional blind comparisons by utilizing a specialized two-step architecture:
    *   **Pre-Sorting Phase:** The program parses Stack A linearly. If an element's index breaks the strictly ascending pattern (`index > last`), it is kept and rotated (`ra`); otherwise, it is systematically isolated to Stack B (`pb`). This isolates structural chaos into Stack B up front.
    *   **Signed Cost Scoring & Interleaved Execution:** During the collection phase (`greedy_pop`), the system evaluates insertion placement across both stacks using signed arithmetic. Positive values indicate down-stream rotations (`ra`/`rb`), while negative values capture upstream reverse-rotations (`rra`/`rrb`). By comparing the alignment of signs via a `combined()` evaluation function, the engine detects when rotation directions match. It then interleaves these operations through synchronous double-moves (`rr`/`rrr`), collapsing two distinct operation pathways into one to minimize execution footprints.


### 2. Medium Sort (Two-Phase Dynamic Chunk Sort)
* **Target:** Moderately disordered stacks.
* **Complexity:** Time: $O(N \sqrt{N})$ | Auxiliary Space: O(1)
* **Justification:** Pushing random numbers blindly to Stack B creates massive O(N) search penalties later. This implementation eliminates that penalty using a custom, two-phase algorithmic design:
  * **Phase 1: Dynamic Range Filtering & Instruction Interleaving:** The array range is divided into chunks scaled mathematically to exactly `(width * 36) / 10` ($\approx 3.6 \times \sqrt{N}$) using integer precision to optimize chunk sizing without floating-point overhead. As items match the active range and move via `pb`, elements smaller than the chunk's midpoint trigger a **deferred sink optimization**. Instead of immediate `rb` execution, the operation is flagged as pending. If the next step requires an `ra` shift, the instructions are interleaved and resolved as a single, concurrent `rr` operation, trimming down total moves.
  * **Phase 2: Lookahead Retrieval with Bottom-Parking:** When popping elements back to Stack A, the system evaluates the distance to the maximum index remaining in Stack B. If a node is encountered that is smaller than the current head of Stack A but close to the top of Stack B, the algorithm triggers a **parking sub-system**. Rather than rotating Stack B away from the target element, it pushes the current node to Stack A and rotates it immediately out of the way to the bottom (`ra`). Once the true maximum is cleared, these parked nodes are systematically recalled using structured reverse rotations (`rra`), preventing hundreds of redundant sorting loops.


### 3. Complex Sort (Hybrid Dual-Pivot Quicksort via Multi-Boundary Function Pointers)
*   **Target:** High-entropy (highly chaotic) stacks.
*   **Complexity:** Time: $O(N \log N)$ \| Auxiliary Space: $O(\log N)$ via call stack recurrence.
*   **Justification:** Standard quicksort patterns introduce severe data thrashing on stacks due to the lack of pointer indexing. This engine overrides that fundamental constraint by utilizing a unique state-machine based Dual-Pivot architecture:
    *   **4-Way Structural Boundary Mapping:** The system does not limit execution to the tops of Stack A or B. It defines execution vectors across four discrete structural entry points: `START_A`, `END_A`, `START_B`, and `END_B`. By mapping these boundaries, elements can be dynamically pushed from or pushed to both the top and bottom elements of either stack via constant-time lookahead functions (`get_next_index` and `move_to`).
    *   **Dynamic Three-Way Partitioning:** Using two calculated structural pivots tuned adaptively to dataset sizes (1/3 and 2/3 split metrics), a conditional loop routes data through a highly optimized split matrix. Elements matching the highest sub-range are routed to the upper target, mid-range elements to the middle target, and small components are pushed to the lowest target zone. This three-way split forces elements to converge on their target positions up to 33% faster than standard quicksort. Sometimes the highest sub-range is intentionally made to hold larger chunk of data to decrease the amount of "round-trips" required for the data to move between stack a and stack b.
    *   **Function Pointer Jump-Tables for Base Cases:** To prevent recursion overhead from flooding the execution stack, partitions dropping to a size of ≤ 3 elements are instantly bypassed and caught by a specialized base-case controller (`small_sort`). It uses an internal array of function pointers (`sort_three_at`) to jump straight to hardcoded sorting routines custom-designed for each boundary layout, guaranteeing zero overhead at lower boundaries.



# Instructions

## Compile

### Mandatory Part
1. Run `make`
2. The `push_swap` executable will be generated.

### Bonus Part (Checker)
1. Run `make bonus`
2. The `checker` executable will be generated.

## Execution & Usage

To execute the program and allow the internal metric to automatically handle algorithm allocation:
```bash
./push_swap 2 1 3 6 5 8
```
### Algorithm & Benchmarking Flags
Force explicit behaviors or extract internal performance metrics using the following arguments:

*   `--adaptive`: Explicitly forces the automated profiling algorithm to select the best sort type using the disorder metric.
*   `--simple`  : Forces the execution of the Simple (Insertion) Sort algorithm.
*   `--medium`  : Forces the execution of the Medium (Chunk) Sort algorithm.
*   `--complex` : Forces the execution of the Complex (Dual-Pivot Quicksort) algorithm.
*   `--bench`   : Prints performance diagnostics including the **disorder metric**, **chosen algorithm and time complexity**, **total operation count**, and a **breakdown of each operation's individual count**.

Example syntax using diagnostics:
```bash
./push_swap --bench 2 1 3 6 5 8
./push_swap --simple 2 1 3 6 5 8
./push_swap --medium 2 1 3 6 5 8
./push_swap --complex 2 1 3 6 5 8
./push_swap --adaptive 2 1 3 6 5 8
./push_swap --adaptive --bench 2 1 3 6 5 8
```
### Managing Large Outputs (Redirection)
To prevent your terminal screen from flooding with thousands of operation lines, you can redirect the data streams into files using standard shell features:

*   **Save operations (`stdout`) to a file:**
    ```bash
    ./push_swap 2 1 3 6 5 8 > operations.txt
    ```
*   **Save benchmarks (`stderr`) to a log file while keeping operations on screen:**
    ```bash
    ./push_swap --bench 2 1 3 6 5 8 2> bench_log.txt
    ```
*   **Isolate both streams into separate files simultaneously:**
    ```bash
    ./push_swap --bench 2 1 3 6 5 8 > operations.txt 2> bench_log.txt
    ```

### Bonus: Verifying Outputs with Checker
The `checker` binary reads operations from standard input and confirms whether the sequence yields a clean, sequentially sorted stack.

Pipe your instruction pipeline directly to verify correctness:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
*   Outputs `OK` if the numbers are properly sorted and stack B remains completely empty.
*   Outputs `KO` if the sequence fails to sort the integers.

Because `--bench` diagnostics are isolated to `stderr`, you can benchmark performance and check the sorting correctness at the same time without breaking the pipe interface:
```bash
ARG="4 67 3 87 23"; ./push_swap --bench $ARG | ./checker $ARG
```
*(The `checker` safely reads the operation strings from `stdout`, while the benchmarks flash directly onto the terminal via `stderr`).*

Example output:
```
ARG="4 67 3 87 23"; ./push_swap --bench $ARG | ./checker $ARG        
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5  
[bench] ra: 0  rb: 2  rr: 0  rra: 0  rrb: 1  rrr: 0  
OK
```

## Cleaning Up
- **Remove Object Files**: Run `make clean` to delete all compiled `*.o` files.
- **Full Clean**: Run `make fclean` to strip object files, `push_swap`, and the `checker` executable.
- **Recompile**: Run `make re` to reset your build environment and compile fresh targets.


# Resources

1. [C Standard Library](https://github.com) - Repository containing source code to C Standard Library as defined by Plauger.
2. [Claude](https://claude.ai) - AI tool used for generating test cases and explaining bugs.
3. [GeeksForGeeks](https://geeksforgeeks.org) - Resource for learning about linked lists and C in general.
4. [Markdown Live Preview](https://markdownlivepreview.com) - Reference for markdown file format.
5. [Python Tutor](https://pythontutor.com) - Visualizer for C (and Python).
6. [C99 Standard Draft](https://open-std.org) - Draft for C99 Standard.
7. [Push_swap visualiser](https://github.com/Niimphu/push_swap_visualiser.git) - Visualiser for push_swap output using Godot engine.

# Contributions
`nisim`:
- Disorder metric
- Bench
- Data structure
- Operations
- Complex Algorithm
- Bonus / Checker program
- Makefile
- README

`mbin-mus`:
- Input parsing and checking
- Stack initialization
- Flags handling
- Utils for push_swap program
- Simple Algorithm
- Medium Algorithm
- Push_swap program
- README