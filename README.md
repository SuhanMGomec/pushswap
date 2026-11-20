*This project has been created as part of the 42 curriculum by sgomec, gucakmak.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks (`a` and `b`) and a
restricted set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`,
`rra`, `rrb`, `rrr`). The program prints the sequence of operations that sorts
stack `a` in ascending order, with the smallest number on top.

The goal of the project is to experience algorithmic complexity in a concrete
way: the cost of every strategy is measured in **number of push_swap operations
generated**, not in CPU time.

The binary embeds four strategies:

| Flag         | Strategy                               | Class (in operations) |
|--------------|----------------------------------------|-----------------------|
| `--simple`   | Min extraction (selection sort)        | O(n²)                 |
| `--medium`   | Sliding-window chunk sort (√n window)  | O(n√n)                |
| `--complex`  | LSD radix sort on indices (base 2)     | O(n log n)            |
| `--adaptive` | Chooses one of the above by *disorder* | depends on regime     |

`--adaptive` is the default when no strategy flag is given.

## Instructions

### Compilation

```bash
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror` and does not relink.

### Usage

```bash
./push_swap 2 1 3 6 5 8              # adaptive (default)
./push_swap "2 1 3" 6 5 8            # numbers can also be given in one string
./push_swap --simple 5 4 3 2 1       # force the O(n²) strategy
./push_swap --medium $ARG            # force the O(n√n) strategy
./push_swap --complex $ARG           # force the O(n log n) strategy
./push_swap --adaptive $ARG          # explicit adaptive mode
./push_swap --bench $ARG             # print metrics on stderr after sorting
```

Flags can be placed anywhere among the numbers. Any unknown `--flag` is an error.

### Checking the result

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG   # → OK
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l                # number of operations
./push_swap --bench $ARG 2>&1 >/dev/null                     # only the bench output
```

### Error handling

`Error\n` is printed on **stderr** (exit code 1) when:

- an argument is not an integer (`1 a 3`, `+`, `-`, `1+`),
- a number is outside the `int` range (`2147483648`, `-2147483649`),
- a number appears twice (`1 2 2`, `0 -0`),
- an argument is empty or only spaces (`""`, `"   "`),
- an unknown flag is given (`--foo`).

With no arguments, nothing is printed.

### Benchmark mode

With `--bench`, after sorting, the following is printed on **stderr** (so it does
not interfere with the checker):

```
[bench] disorder: 45.19%
[bench] strategy: Adaptive / O(n*sqrt(n))
[bench] total_ops: 683
[bench] sa:  0  sb:  0  ss:  0  pa:  100  pb:  100
[bench] ra:  0  rb:  105  rr:  0  rra:  278  rrb:  100  rrr:  0
```

## Algorithms

### Preprocessing: indexing

Before sorting, every value is replaced (in the `index` field) by its rank:
the smallest value gets `0`, the largest gets `n - 1` (`assign_index`). All
strategies work on these ranks, which removes problems with negative numbers and
large values and makes the radix sort need only ⌈log₂ n⌉ passes.

### Disorder metric

`disorder` counts the pairs `(i, j)` with `i < j` and `a[i] > a[j]` (inversions)
and divides by the total number of pairs `n(n-1)/2`. The result is between `0`
(already sorted) and `1` (reverse sorted). It is computed **before any
operation** is performed.

### 1. Simple — min extraction, O(n²)

- 2 elements: one `sa` if needed.
- 3 elements: at most one rotation (`ra` or `rra`) to put the maximum at the
  bottom, then at most one `sa`.
- 4 or more: repeatedly find the smallest remaining index, bring it to the top
  of `a` with `ra` or `rra` (whichever direction is shorter), and `pb` it. When
  only 3 elements remain in `a`, sort them with the 3-element case and `pa`
  everything back.

**Bound:** each extraction costs at most `n/2` rotations + 1 push, for at most
`n` extractions, plus `n` `pa`: ≤ `n·(n/2 + 2)` operations → **O(n²)**.
**Space:** the two stacks, O(n); O(1) extra.

### 2. Medium — sliding-window chunk sort, O(n√n)

Let `w = ⌊√n⌋` and `i` the number of elements already pushed to `b`.

- **Phase 1 (a → b):** while `a` is not empty, if the top index is `≤ i + w`,
  `pb` it; if it is also smaller than `i`, `rb` it to the bottom of `b` (this
  keeps the smaller elements at the bottom and the larger ones on top). Otherwise
  `rra` to look at the next candidate.
- **Phase 2 (b → a):** repeatedly bring the largest index of `b` to the top with
  `rb` or `rrb` (shorter direction) and `pa` it. Since every element enters `b`
  inside a window of size `w`, `b` is "almost sorted by blocks" and the maximum is
  always close to the top or the bottom.

**Bound:** in phase 1, an element waits at most one window (≈ `w` rotations) for
its turn, so phase 1 costs O(n·w). In phase 2, the maximum is within O(w)
positions of one end of `b`, so each `pa` costs O(w) rotations. Total
**O(n·√n)**. **Space:** O(n).

### 3. Complex — LSD radix sort, O(n log n)

Indices are in `[0, n-1]`, so they need `k = ⌈log₂ n⌉` bits. For each bit from
the least significant to the most significant:

1. Look at the top element of `a` exactly `size(a)` times: if the current bit of
   its index is `1`, `ra` (it stays in `a`); if it is `0`, `pb`.
2. `pa` everything back from `b`.

Each pass is stable (elements with the same bit keep their relative order:
`ra` keeps the order, and `pb` then `pa` reverses it twice), so after the last
bit the stack is sorted. If `a` becomes sorted before the last bit, the
remaining passes are skipped.

**Bound:** each pass costs `n` (`ra`/`pb`) + at most `n` (`pa`) ≤ `2n`
operations, for `⌈log₂ n⌉` passes → ≤ `2n·⌈log₂ n⌉` → **O(n log n)**.
**Space:** O(n).

### 4. Adaptive — chosen by disorder

| Disorder `d`      | Method used        | Required class | Why                                                                     |
|-------------------|--------------------|----------------|-------------------------------------------------------------------------|
| `d < 0.2`         | Simple             | O(n²)          | Few inversions: the minimum is usually near the top, so rotations are cheap. |
| `0.2 ≤ d < 0.5`   | Medium             | O(n√n)         | Partially ordered input: windows of size √n catch most elements quickly. |
| `d ≥ 0.5`         | Complex (radix)    | O(n log n)     | Random/reversed input: radix sort has a guaranteed `2n⌈log₂ n⌉` bound.  |
| `n ≤ 5` (any `d`) | Simple             | O(1)           | With at most 5 elements the cost is bounded by a small constant, so the hand-tuned small sorts are always best. |

The thresholds `0.2` and `0.5` are the ones required by the subject. We kept
them because our measurements agree with them: on 500 almost-sorted numbers the
simple strategy needs about 1 000 operations, while radix sort always needs
6 784; on random input (disorder ≈ 0.5) the medium and complex strategies give
similar results, so the switch point between them at `0.5` is reasonable.

## Performance

Measured with the provided `checker_Mac` (default adaptive mode, 50 random
inputs each, all results `OK`):

| Size | Min  | Average | Max  | Pass | Good | Excellent |
|------|------|---------|------|------|------|-----------|
| 100  | 649  | 903     | 1084 | ✅ < 2000 | ✅ < 1500 | 15/50 < 700 |
| 500  | 5612 | 6261    | 6784 | ✅ < 12000 | ✅ < 8000 | 0/50 < 5500 |

## Project structure

| File | Content |
|------|---------|
| `main.c` | Entry point, strategy selection, adaptive logic, bench call |
| `parse.c`, `parse_utils.c`, `ft_split.c` | Argument and flag parsing, validation, errors |
| `stack_utils.c` | Linked-list stack helpers |
| `op_swap.c`, `op_push.c`, `op_rotate.c`, `op_reverse.c` | The 11 operations (print + count) |
| `sort_utils.c` | `is_sorted`, `assign_index`, `disorder`, search helpers |
| `sort_simple.c` | Simple strategy |
| `sort_medium.c` | Medium strategy |
| `sort_complex.c` | Complex strategy (radix) |
| `counter.c`, `bench.c` | Operation counters and `--bench` output |

## Contributions

- **sgomec**: stack operations (`rotate`, `swap`, `reverse`), argument parsing
  (`parse.c`), `main.c` and the `Makefile`, the simple strategy
  (`sort_simple.c`), the complex strategy (radix sort, `sort_complex.c`), flag
  parsing and strategy selection, norm fixes.
- **gucakmak**: first version of the operations (`push`), parsing helpers and
  stack utilities (`parse_utils.c`, `stack_utils.c`, `ft_split.c`), the operation
  counter (`t_ctr`) and benchmark output (`bench.c`), the disorder metric and
  indexing (`sort_utils.c`), the medium strategy (chunk sort, `sort_medium.c`).

Both of us reviewed and tested every strategy and can explain every part of the
code.

## Resources

- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)),
  the idea behind the disorder metric
- [Bitwise operations in C — Wikipedia](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
- Cormen, Leiserson, Rivest, Stein — *Introduction to Algorithms* (sorting and
  complexity chapters)

### Use of AI

We used an AI assistant (Claude) for the following tasks:

- **Learning:** step-by-step explanations of binary numbers, bit shifting
  (`>>`, `& 1`) and how LSD radix sort works. The radix sort code was then
  written by us with the assistant reviewing our attempts.
- **Code:** the flag parsing (`set_flag`, `parse_numbers`, `ft_strcmp` in
  `parse.c`) and the strategy selection in `main.c` (`sort_stack`,
  `run_adaptive`) were drafted with the assistant; we reviewed, tested and
  adapted them.
- **Review and fixes:** finding the `rr` counter bug, `disorder` type fix and
  norm problems.
- **Testing:** scripts to run many random inputs through the checker and to
  measure operation counts.
- **Documentation:** a first draft of this README, which we checked and
  completed.

Every part generated with AI was read, tested and understood by both of us
before being kept.
