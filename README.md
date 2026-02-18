_This project has been created as part of the 42 curriculum by yartym_

## About

**push_swap** is a project that involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

The project provides two programs:
1.  **push_swap**: Calculates and displays the instructions to sort the integers received as arguments.
2.  **checker**: Executes the instructions and checks if the stack is correctly sorted.

## Algorithm Design

This project uses a greedy algorithm optimized with the **Longest Increasing Subsequence (LIS)**.

### 1. Identify LIS
The program analyzes Stack A to find the largest subset of numbers that are already in ascending order (not necessarily contiguous). These numbers are marked to stay in Stack A.

### 2. Push Non-LIS to B
All numbers that are **not** part of the identified LIS are pushed to Stack B. This leaves Stack A partially sorted.

### 3. Greedy Re-insertion
The algorithm then moves elements from Stack B back to Stack A. For every element in Stack B, it calculates:
* **Cost A:** Rotations needed to bring the correct target position in Stack A to the top.
* **Cost B:** Rotations needed to bring the element in Stack B to the top.
* **Total Cost:** The sum of moves (optimizing for double rotations like `rr` and `rrr`).

The element with the **cheapest total cost** is moved first.

### 4. Final Alignment
Once all elements are back in Stack A, the stack is rotated to bring the smallest number to the top, completing the sort.

## Instructions

### Compilation
To compile the `push_swap` program:
```
make
```

To compile the `checker` bonus program:
```bash
make checker
```

### Usage

**Running push_swap:**
```bash
./push_swap 2 1 3 6 5 8
```

**Running checker:**
```bash
./checker 2 1 3 6 5 8
```
*(Then type operations like `sa`, `pb`, `ra`... followed by Ctrl+D)*

**Combined Test (Random Numbers):**
You can pipe the output of push_swap into the checker using a random number generator:
```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

## Operations

| Code | Instruction | Action |
| :--- | :--- | :--- |
| `sa` | swap a | Swap the first 2 elements at the top of stack a. |
| `sb` | swap b | Swap the first 2 elements at the top of stack b. |
| `ss` | swap a+b | `sa` and `sb` at the same time. |
| `pa` | push a | Take the first element at the top of b and put it at the top of a. |
| `pb` | push b | Take the first element at the top of a and put it at the top of b. |
| `ra` | rotate a | Shift up all elements of stack a by 1. |
| `rb` | rotate b | Shift up all elements of stack b by 1. |
| `rr` | rotate a+b | `ra` and `rb` at the same time. |
| `rra` | reverse a | Shift down all elements of stack a by 1. |
| `rrb` | reverse b | Shift down all elements of stack b by 1. |
| `rrr` | reverse a+b | `rra` and `rrb` at the same time. |

## Resources

