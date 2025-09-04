# push_swap

The **push_swap** project is a sorting algorithm challenge from 42 School.  
The goal is to sort a stack of integers using only a limited set of operations on two stacks (`a` and `b`).

---

## 🚀 Project Overview

- **Input:** A list of integers (possibly unsorted).
- **Goal:** Sort the list in ascending order with the minimum number of operations.
- **Stacks:**
  - `a`: contains the input numbers.
  - `b`: initially empty, used for temporary storage.

---

## 🧠 Project Goals

- Learn and implement efficient sorting algorithms  
- Optimize for the smallest number of moves  
- Work with stacks, linked lists, and algorithms  
- Manage complexity and big input cases  

---

## 📊 Performance

- Sort **3 numbers** → ≤ 3 moves  
- Sort **5 numbers** → ≤ 12 moves  
- For **100 numbers** → < 700 moves  
- For **500 numbers** → < 5500 moves  

*(The actual performance depends on your algorithm.)*

---

## 🛠️ Implementation Details

- ✅ Input validation:
  - Duplicates  
  - Non-numeric values  
  - Out-of-int-range numbers  

- ✅ Parsing arguments and initializing stacks  

- ✅ Core sorting algorithm:
  - Radix sort  
  - Chunking  
  - Or a mix of strategies  

- ✅ Outputting the minimal sequence of operations  


## 📋 Allowed Operations

- **Swap:**
  - `sa`: swap the first 2 elements of stack a.
  - `sb`: swap the first 2 elements of stack b.
  - `ss`: `sa` and `sb` at the same time.

- **Push:**
  - `pa`: push the first element of b onto a.
  - `pb`: push the first element of a onto b.

- **Rotate:**
  - `ra`: shift all elements of a up by 1.
  - `rb`: shift all elements of b up by 1.
  - `rr`: `ra` and `rb` at the same time.

- **Reverse Rotate:**
  - `rra`: shift all elements of a down by 1.
  - `rrb`: shift all elements of b down by 1.
  - `rrr`: `rra` and `rrb` at the same time.

---

## 🧠 Approach

- Small stacks (≤ 5 elements):  
  - Hardcoded efficient sorting with minimal moves.
- Large stacks:  
  - **Radix sort** (bitwise approach) for efficiency.  
  - Other strategies may include chunking or splitting into smaller ranges.

---

## 🛠️ Compilation


`make`
▶️ Usage

Example

`./push_swap 2 1 3 6 5 8`

Output (sequence of operations):

```
sa
pb
pb
ra
pa
pa
```

✅ Testing

You can combine push_swap with the checker program provided by 42:

`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`

If the output sequence sorts the stack → OK

Otherwise → KO

👨‍💻 Author

André Ferreira (anferre2)
