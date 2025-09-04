push_swap

📌 Overview

The push_swap project is a sorting algorithm challenge from 42 school.
The goal is to sort a stack of integers with the smallest number of operations, using only a limited set of stack instructions.

The project consists of two programs:

push_swap → takes a list of integers as arguments and prints the sequence of operations needed to sort them.

checker (optional bonus) → takes the same list and a sequence of operations as input, then checks if the result is sorted.

⚙️ Allowed operations

sa / sb : swap the first two elements of stack A or B

ss : sa and sb at the same time

pa : push the first element of B onto A

pb : push the first element of A onto B

ra / rb : rotate stack A or B upwards

rr : ra and rb at the same time

rra / rrb : reverse rotate stack A or B

rrr : rra and rrb at the same time

🚀 Usage
Compile
make

This will create the push_swap executable.
Run

./push_swap 4 67 3 87 23

Example output:

pb
ra
pb
sa
pa
pa

🧠 Project Goals

    Learn and implement efficient sorting algorithms

    Optimize for the smallest number of moves

    Work with stacks, linked lists, and algorithms

    Manage complexity and big input cases

📊 Performance

    Sort 3 numbers in ≤ 3 moves

    Sort 5 numbers in ≤ 12 moves

    For 100 numbers, expect < 700 moves

    For 500 numbers, expect < 5500 moves

(The actual performance depends on your algorithm.)
🛠️ Implementation details

    Input validation (duplicates, non-numeric values, out-of-int-range)

    Parsing arguments and initializing stacks

    Core sorting algorithm (usually radix sort, chunking, or a mix of strategies)

    Outputting the minimal sequence of operations

👨‍💻 Author

Project developed as part of the 42 School curriculum.

Author: André Lima
