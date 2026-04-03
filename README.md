# 📚 data-structures-in-C

> Understanding *why* a linked list beats an array (sometimes) is far more satisfying than just memorizing it.

A structured collection of C programs covering fundamental data structures and algorithms — built for everyone, from beginners to those looking to revisit the basics.

---

## 🗂️ Repo Structure

```
data-structures-in-C/
│
├── Unit1_Searching_Sorting_Algorithms/
│   ├── README.md
│   ├── searching/
│   │   ├── linear_search.c
│   │   └── binary_search.c
│   ├── sorting/
│   │   ├── bubble_sort.c
│   │   ├── insertion_sort.c
│   │   ├── selection_sort.c
│   │   ├── radix_sort.c
│   │   ├── quick_sort.c
│   │   └── heap_sort.c
│   └── algorithms/
│       ├── recursion_examples.c
│       ├── time_space_complexity_notes.md
│       └── hashing.c
│
├── Unit2_Linked_Lists/
│   ├── README.md
│   ├── singly_linked_list.c
│   ├── circular_linked_list.c
│   ├── doubly_linked_list.c
│   └── sparse_matrix/
│       ├── sparse_array_representation.c
│       └── sparse_linked_representation.c
│
├── Unit3_Stack_and_Queue/
│   ├── README.md
│   ├── stack/
│   │   ├── stack_array.c
│   │   ├── stack_linked.c
│   │   ├── infix_to_postfix.c
│   │   └── postfix_evaluation.c
│   ├── queue/
│   │   ├── queue_array.c
│   │   ├── queue_linked.c
│   │   └── circular_queue.c
│   └── deque/
│       ├── deque_array.c
│       └── deque_linked.c
│
├── Unit4_Trees/
│   ├── README.md
│   ├── binary_tree/
│   │   ├── binary_tree_array.c
│   │   ├── binary_tree_linked.c
│   │   └── traversals.c
│   ├── priority_queue/
│   │   ├── max_heap.c
│   │   └── priority_queue.c
│   └── bst/
│       ├── bst_operations.c
│       └── avl_tree.c
│
├── Unit5_Graphs/
│   ├── README.md
│   ├── representations/
│   │   ├── adjacency_matrix.c
│   │   └── adjacency_list.c
│   └── traversals/
│       ├── dfs.c
│       └── bfs.c
│
├── Labs/
├── Tutorials/
├── README.md
├── CONTRIBUTING.md
└── LICENSE
```

Each unit folder contains its own `README.md` with a breakdown of the topics and programs covered.

---

## 🧰 Prerequisites

- A C compiler — [GCC](https://gcc.gnu.org/) recommended
- A terminal / command line
- Basic knowledge of C (variables, loops, functions)
- Curiosity — most of the learning happens when you tweak the code and see what breaks

---

## 🚀 Getting Started

### 1. Clone the repo

```bash
git clone https://github.com/your-username/data-structures-in-C.git
cd data-structures-in-C
```

### 2. Navigate to a topic

```bash
cd Unit1_Searching_Sorting_Algorithms/searching
```

### 3. Compile and run

```bash
gcc file_name.c -o output && ./output
```

---

## 🤝 Contributing

Contributions are welcome — whether it's fixing a typo, adding a new implementation, or improving an explanation.

> ⚠️ **Note:** AI-generated code will not be accepted and will be removed without review.

Please read [CONTRIBUTING.md](CONTRIBUTING.md) before submitting a pull request.

---

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.