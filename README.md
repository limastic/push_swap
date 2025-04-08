# 🔄 Push_swap — Sorting Algorithm Project

**"Because Swap_push isn't as natural!"**

Welcome to Push_swap, a challenging algorithmic project where I implemented an efficient sorting solution with a limited set of operations on two stacks.

---

## 🎯 Project Objectives

- Implement a sorting algorithm using only specific stack operations
- Learn about algorithmic complexity and optimization techniques
- Develop efficient sorting strategies for different data sets
- Create a program that finds the minimal number of operations to sort data

---

## 📋 Project Overview

Push_swap is an algorithm project that requires sorting a stack of integers using only a specific set of operations. The challenge is to sort the stack in as few operations as possible.

### 🧮 The Rules

- Two stacks: **Stack A** (contains random integers) and **Stack B** (initially empty)
- Goal: Sort Stack A in ascending order using only allowed operations
- Output: Print the list of operations used to sort the stack

### ⚙️ Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the first element from stack B and put it at the top of stack A |
| `pb` | Take the first element from stack A and put it at the top of stack B |
| `ra` | Shift up all elements of stack A by 1 (first becomes last) |
| `rb` | Shift up all elements of stack B by 1 (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Shift down all elements of stack A by 1 (last becomes first) |
| `rrb` | Shift down all elements of stack B by 1 (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |


## 🔍 Algorithm Approach

I implemented a hybrid sorting strategy that uses different algorithms depending on the input size:

- **Small sets (≤ 5)**: Hardcoded optimal solutions
- **Medium sets**: Enhanced selection sort using both stacks
- **Large sets**: Optimized radix sort algorithm adapted for stack operations

The program analyzes the input and selects the most efficient strategy based on the number of elements and their distribution.

---

## 🛠️ How to Use

### Compilation

```bash
make            # Compile push_swap program
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Recompile everything
```

### Usage

```bash
# Run push_swap with integers to sort
./push_swap 4 67 3 87 23

# Verify number of operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Error Handling

The program handles various error cases:
- Non-integer arguments
- Numbers larger than MAX_INT
- Duplicate numbers

In these cases, it displays "Error" on the standard error output.

---

## 💡 Key Learnings

- Algorithm efficiency and complexity analysis
- Stack-based data manipulation
- Optimization techniques for different data sets
- Advanced error handling in C