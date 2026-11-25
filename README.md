*This project has been created as part of the 42 curriculum by xinchong, sonfong*

## Description
This project involves students to sort a stack of integers using two stacks (`a` and `b`) and a limited set of 11 operations, and to print the list of operations that does it. It is a duo project.

It aims for students to learn about algorithmic complexity in a concrete way: the cost of an algorithm is not measured in CPU steps but in the **number of push_swap operations printed**, and the right algorithm depends on how messy the input is. The program therefore contains four strategies (simple, medium, complex and adaptive) and a benchmark mode.

## Instructions
To create the **push_swap** program, run the command `make all / make push_swap / make`. It builds `libft` first, then the project, and does not relink if nothing changed.

To remove all object files only, run the command `make clean`.

To remove **push_swap** and all object files, run the command `make fclean`.

To remove everything and build again, run the command `make re`.

Usage: `./push_swap [strategy] [--bench] <integers>`
* The first integer is the top of stack `a`. The integers can be separate arguments or one quoted string (`"3 1 2"`), or both.
* Strategy: `--simple`, `--medium`, `--complex` or `--adaptive` (default). Every strategy works for any input size.
* `--bench` also prints a report on **stderr** (disorder, strategy and its complexity class, total operations, count of each operation). The operations stay on stdout.
* The flags must come **before** the numbers.
* If there are no numbers, nothing is printed. If an argument is not an integer, does not fit in an `int`, or a value is duplicated, `Error` is printed on stderr.

Examples:
```
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
ARG="$(shuf -i 0-9999 -n 100 | tr '\n' ' ')"
./push_swap $ARG | ./checker_linux $ARG
./push_swap --bench $ARG 2> bench.txt | wc -l
```

## Resources
This project was implemented using resources such as:
* The subject — chapter VI.3 names the example algorithms of each complexity class and defines the disorder metric and the adaptive thresholds.
* [Wikipedia: Radix sort](https://en.wikipedia.org/wiki/Radix_sort) / [Wikipedia: Selection sort](https://en.wikipedia.org/wiki/Selection_sort) — to understand the two classic algorithms before adapting them to two stacks.
* [leogaudin/push_swap](https://github.com/leogaudin/push_swap) — a README describing a chunk-based approach: push the chunks to `b` in order, then bring everything back starting from the maximum. Read for the idea only.
* [klode-git/push_swap](https://github.com/klode-git/push_swap) — a README for this version of the subject, which gave the argument that `k` chunks cost about `n·k + n²/k` operations.
* [devinesm/PushSwap](https://github.com/devinesm/PushSwap) — showed that the chunk size is a tuning constant (it uses 2·√n).
* [Medium (Ulysse Gerkens)](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0) — a different approach (quicksort-like on chunks), useful as an alternative that was considered.
* `man` pages — for `read`, `write`, `malloc` and `free`.
* [Python Tutor](https://pythontutor.com/visualize.html#mode=edit) — to help with visualisation of difficult problems.
* Our own peers on campus
### AI usage
AI was not used as source for solutions but only used for research for concepts and questions that could not be easily found from the resources mentioned above, and provided extra guidance.

## Details
### Algorithm & data structure
**Data structures**

Both stacks are **doubly linked lists** (`t_node`: `value`, `rank`, `next`, `prev`) held by a `t_stack` (`top`, `bottom`, `size`). Keeping a pointer to the bottom and a `prev` pointer in every node makes all 11 operations a handful of pointer changes, even `rra`/`rrb`, instead of shifting an array. The operations never allocate: nodes are relinked, never copied. There are no global variables. The operation counters live in a `t_counters` struct and the user's choices in a `t_options` struct, both created in `main` and passed down.

**Ranks**

The input values can be anything between `INT_MIN` and `INT_MAX`, so every node also stores its **rank**: how many values are smaller than it (`0` to `n-1`, valid because there are no duplicates). The sorts work on ranks, which makes the radix passes and the chunks easy to compute.

**Disorder**

`compute_disorder` counts the pairs where a bigger number comes before a smaller one and divides by the total number of pairs, giving a value from 0 (sorted) to 1 (reversed). It is computed once, **before** any move, and it is 0 for 0 or 1 numbers. A random list has a disorder of about 0.5, because each pair is out of order with probability 1/2.

**Operations**

Each of the 11 operations prints its name followed by `\n`, and adds 1 to its own counter. `ss`, `rr` and `rrr` count once as themselves, not as two operations. An operation that cannot do anything (a swap or rotation on fewer than 2 nodes, a push from an empty stack) does nothing and prints nothing.

### The strategies
Complexity is stated in the number of push_swap operations generated. The comparisons the program itself makes (ranks, disorder) are not operations. All strategies use O(1) extra space: the nodes are only relinked, and the only allocations are the `n` nodes of the input and the temporary array from `ft_split` while parsing.

**Simple: selection sort, O(n²)**

In each round, the smallest rank of `a` is brought to the top by the shorter of `ra` or `rra`, and pushed to `b` with `pb`. When `a` is empty, everything is pushed back with `pa`.
* *Upper bound: with `m` nodes left, a round costs at most `m/2` rotations plus one `pb`. Over all rounds that is at most `n·n/2 + n`, plus `n` times `pa`, so about `n²/2 + 2n` = O(n²).*
* *Why the result is ascending: the smallest is pushed first, so `b` ends with the largest on top. `pa` then moves the largest first, so it sinks to the bottom of `a`, and the smallest arrives last, on top.*

**Medium: chunk sort, O(n√n)**

The ranks are split into `k = max(1, ⌊√n⌋ / 2)` chunks of `⌈n / k⌉` consecutive ranks each. A node belongs to chunk `rank / size`.
1. For each chunk in increasing order, go through every node of `a` once: `pb` if it belongs to the current chunk, otherwise `ra`.
2. Then, until `b` is empty, bring the node with the largest rank to the top of `b` (the shorter of `rb` or `rrb`) and `pa` it.

* *Pushing phase: each pass looks at every node left in `a` exactly once and costs one operation per node, so at most `n` per pass and at most `n·k` in total.*
* *Bringing back: `rb` and `rrb` do not change the cyclic order of `b`. After the pushing phase, every chunk occupies one consecutive block of at most `⌈n/k⌉` nodes, and the largest remaining rank is always in the current block or the next one. So each extraction costs at most about `2·⌈n/k⌉` rotations, and `n` extractions cost at most about `2n²/k`.*
* *Total: `n·k + 2n²/k + n`. This is O(n√n) when `k` is proportional to `√n`. A fixed number of chunks would not be O(n√n), which is why `k` grows with `√n`. The constant 1/2 was chosen by measuring: it lowered the 500-number average from about 8200 to about 7400.*

**Complex: radix sort (LSD), O(n log n)**

For every bit of the ranks, from the lowest to the highest, go through every node of `a` once: `pb` if the bit is 0, `ra` if it is 1. Then `pa` everything back. After the pass of the highest bit, `a` is sorted, because each pass is stable and the last pass decides the most significant order.
* *Number of passes: `⌈log₂ n⌉` (the bits needed for the largest rank, `n-1`).*
* *Upper bound: a pass costs `n` operations for `pb`/`ra` plus at most `n` for `pa`, so at most `2n·⌈log₂ n⌉` = O(n log n).*
* *The count only depends on `n`, not on the order of the input, because the ranks are always a permutation of `0..n-1`.*

**Adaptive: choosing by disorder**

`run_sort` returns at once if `a` is already sorted. Otherwise `--adaptive` (the default) chooses:

| Case | Method | Class |
| --- | --- | --- |
| fewer than 6 numbers | `sort_small` | at most 2, 6 and 10 operations for 3, 4 and 5 numbers |
| disorder < 0.2 | simple (selection sort) | O(n²) |
| 0.2 ≤ disorder < 0.5 | medium (chunk sort) | O(n√n) |
| disorder ≥ 0.5 | complex (radix sort) | O(n log n) |

* *The thresholds 0.2 and 0.5 are the regime boundaries given by the subject, and each regime uses a method whose upper bound meets the subject's target for that regime.*
* *Random input has a disorder of about 0.5, so it falls on the border between medium and complex. Both pass the benchmarks, and measuring both showed neither is clearly better (the medium sort wins for 100 numbers, radix for 500), so the subject's boundary was kept.*
* *`sort_small` handles 2 to 5 numbers: 2 numbers with `sa`, 3 numbers by finding the largest (`ra`, `rra` and/or `sa`), and 4 or 5 numbers by pushing the 1 or 2 smallest to `b`, sorting the 3 left and pushing back. Only the adaptive strategy uses it, so the forced flags (`--simple`, `--medium`, `--complex`) always run their own algorithm, whatever the size.*

### Functions
**Parsing and options**
* `parse_options` — reads the leading flags into `t_options` (default: adaptive, no bench) and returns how many arguments it used. It stops at the first argument that is not a flag.
* `is_valid_int` — returns 0 and writes the value if the string is an optional sign and digits only and fits in an `int` (the range is checked while the number is built), otherwise 1.
* `has_duplicates` — returns 1 if a value appears twice.
* `build_stack` — splits every argument with `ft_split` (so `"1 2 3"` works), validates each piece and appends it to `a`, frees the split array on every path, then checks for duplicates. It does not free the stack on error: `main` does.

**Stack**
* `add_bottom` — allocates a node and appends it at the bottom, updating the links, `top`, `bottom` and `size`.
* `ft_llstclear` / `free_split` — free every node of a stack / every string of a split array.
* `is_sorted` — returns 1 if `a` is ascending from the top (empty and one-node stacks count as sorted).
* `assign_ranks` — sets the rank of every node.
* `compute_disorder` — see above.

**Operations** — `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, in `op_swap.c`, `op_push.c`, `op_rotate.c` and `op_reverse.c`.

**Sorting**
* `simple_algo`, `medium_sort`, `radix_sort`, `sort_small` / `sort_three` and `run_sort` (with `adaptive_sort`) — as described above.
* `find_min`, `find_max`, `find_position`, `move_top` — helpers that find a node and bring it to the top of `a` by the shorter direction.

**Benchmark**
* `print_bench` — when `--bench` is given, prints on stderr: the disorder measured before sorting (percentage with two decimals), the strategy and its class (for adaptive, the class of the method it chose), the total number of operations and the count of each operation. The percentage is printed by `put_percent` using integer arithmetic, because libft cannot print a `double`.

### Results
Average number of operations on random inputs (15 inputs for each size):

| Strategy | 100 numbers | 500 numbers |
| --- | --- | --- |
| default (adaptive) | 886 (max 1084) | 7003 (max 7634) |
| `--simple` | 1470 | 32348 |
| `--medium` | 759 | 7452 |
| `--complex` | 1084 | 6784 |

The default is under the "good" targets of the subject (1500 for 100 numbers, 8000 for 500 numbers). The forced `--simple` is meant to show the cost of an O(n²) algorithm, so it does not reach the benchmarks.

## Contributions
* **sonfong** — argument parsing and error handling, the linked list stack and its helpers, ranks, the disorder function, the option flags, the Makefile, the radix sort, the medium sort, `sort_small`, the `--bench` report and the strategy dispatcher.
* **xinchong** — the 11 operations, the simple sort and its helpers, and the adaptive selector.


