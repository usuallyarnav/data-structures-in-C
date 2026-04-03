# Unit 3 — Stack and Queue

This unit covers two of the most widely used data structures in programming — Stacks and Queues. Both control the order in which data is accessed, just in different ways.

---

## 📚 Stack

| File | Description |
|------|-------------|
| `stack_array.c` | Stack implementation using an array. Follows Last-In-First-Out (LIFO) order. |
| `stack_linked.c` | Stack implementation using a linked list, allowing dynamic sizing. |
| `infix_to_postfix.c` | Converts a standard math expression (infix) to postfix form using a stack. |
| `postfix_evaluation.c` | Evaluates a postfix expression using a stack to produce the final result. |

---

## 🚶 Queue

| File | Description |
|------|-------------|
| `queue_array.c` | Queue implementation using an array. Follows First-In-First-Out (FIFO) order. |
| `queue_linked.c` | Queue implementation using a linked list, allowing dynamic sizing. |
| `circular_queue.c` | A queue where the last position wraps around to the first, making better use of space. |

---

## ↔️ Deque

| File | Description |
|------|-------------|
| `deque_array.c` | A Double Ended Queue (Deque) using an array — elements can be added or removed from both ends. |
| `deque_linked.c` | A Deque implementation using a linked list for dynamic sizing. |

---

## 📂 Structure

```
Unit3_Stack_and_Queue/
│
├── stack/
│   ├── stack_array_global.c
│   └── stack_linked.c
├── queue/
│   ├── queue_array.c
│   ├── queue_linked.c
│   └── circular_queue.c
└── deque/
    ├── deque_array.c
    └── deque_linked.c
```