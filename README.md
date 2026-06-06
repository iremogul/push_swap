*This project has been created as part of the 42 curriculum by [Your Login].*

# Push_swap

## Description
The Push swap project is a simple yet highly structured algorithmic challenge: you need to sort data. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks. Your goal is to write a C program called `push_swap` that calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers.

---

## The Rules
* You have 2 stacks named `a` and `b`.
* At the beginning, stack `a` contains a random number of unique negative and/or positive integers.
* Stack `b` is initially empty.
* The goal is to sort the numbers in stack `a` in ascending order.

---

## The Algorithm: Radix Sort
For this project, I chose to implement the **Radix Sort** algorithm. Since we are restricted to two stacks and a strict set of operations, a Base-2 (binary) Radix algorithm is highly optimized and exceptionally reliable for sorting larger datasets (such as 100 or 500 integers). 

* **How it works:** The algorithm evaluates the integers bit by bit, moving from the least significant bit (LSB) to the most significant bit (MSB).
* **Execution:** For every bit position, the algorithm loops through all the numbers in stack `a`. If the current bit of a number is `0`, it is pushed over to stack `b` using the `pb` operation. If the bit is `1`, the number stays in stack `a` and is simply shifted upwards using `ra`.
* **Reintegration:** Once all the elements have been evaluated for that specific bit, everything that was pushed to stack `b` is pushed back to stack `a` using the `pa` operation. This cycle repeats for all the necessary bits of the integers, ultimately leaving stack `a` perfectly sorted.

---

## Instruction Set
* **sa (swap a):** Swap the first 2 elements at the top of stack a.
* **sb (swap b):** Swap the first 2 elements at the top of stack b.
* **ss:** sa and sb at the same time.
* **pa (push a):** Take the first element at the top of b and put it at the top of a.
* **pb (push b):** Take the first element at the top of a and put it at the top of b.
* **ra (rotate a):** Shift up all elements of stack a by 1.
* **rb (rotate b):** Shift up all elements of stack b by 1.
* **rr:** ra and rb at the same time.
* **rra (reverse rotate a):** Shift down all elements of stack a by 1.
* **rrb (reverse rotate b):** Shift down all elements of stack b by 1.
* **rrr:** rra and rrb at the same time.

---

## Installation and Usage

### Compilation
You have to turn in a Makefile which will compile your source files. Run the following command in the root directory:
`make`

### Execution
You have to write a program named `push_swap` that takes as an argument the stack a formatted as a list of integers.
`./push_swap 2 1 3 6 5 8`
In case of error, it must display "Error" followed by a `\n` on the standard error.

### Checker (Bonus)
A `checker` program can be used to execute the sorting instructions to ensure the sequence works properly.
`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`

---

## Benchmark
To achieve maximum project validation (100%), the sorting algorithm must perform within the following limits:
* Sort 100 random numbers in fewer than 700 operations.
* Sort 500 random numbers in no more than 5500 operations.

---

## Resources & AI Usage
During the development phase, AI tools were utilized ethically to reduce repetitive coding tasks and brainstorm optimal parsing structures. All AI-assisted approaches were systematically reviewed, questioned, and tested to avoid blindly copying code. Final validations were discussed in peer-review sessions to ensure a complete and fundamental understanding of the Radix implementation.
