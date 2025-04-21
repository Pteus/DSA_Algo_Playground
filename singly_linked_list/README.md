# LinkedList<T> - Method Notes

A breakdown of each method, its behavior, edge cases, and implementation notes.

---

## 📌 Constructor: `LinkedList(const T &data)`

| Property          | Notes                                            |
|-------------------|--------------------------------------------------|
| Purpose           | Initializes the list with one node.              |
| Inputs            | Initial data value (`data`)                      |
| Edge Cases        | Always creates a single-node list.               |
| How It Works      | Creates a new node, sets `head` and `tail` to it |
| Time Complexity   | O(1)                                             |
| Memory Management | Allocates one node via `new`                     |

---

## 📌 Destructor: `~LinkedList()`

| Property          | Notes                                        |
|-------------------|----------------------------------------------|
| Purpose           | Deletes all nodes to prevent memory leaks.   |
| How It Works      | Loops through all nodes, deletes one by one. |
| Time Complexity   | O(n)                                         |
| Memory Management | Frees all allocated memory                   |

---

## 📌 `void append(const T &data)`

| Property          | Notes                                        |
|-------------------|----------------------------------------------|
| Purpose           | Adds a node to the end of the list.          |
| Inputs            | Data for the new node.                       |
| Edge Cases        | If empty, head and tail are set to new node. |
| How It Works      | `tail->next = newNode`, `tail = newNode`     |
| Time Complexity   | O(1)                                         |
| Memory Management | `new` allocates one node.                    |

---

## 📌 `void deleteLast()`

| Property          | Notes                                                      |
|-------------------|------------------------------------------------------------|
| Purpose           | Deletes the last node in the list.                         |
| Edge Cases        | Handles empty list and single-node list.                   |
| How It Works      | Iterates to second-last node, updates `tail`, deletes last |
| Time Complexity   | O(n) (due to iteration)                                    |
| Memory Management | Deletes one node                                           |

---

## 📌 `void prepend(const T &data)`

| Property          | Notes                                      |
|-------------------|--------------------------------------------|
| Purpose           | Inserts node at the beginning of the list. |
| Inputs            | Data for the new node.                     |
| Edge Cases        | Sets `tail` if list is empty.              |
| How It Works      | `newNode->next = head`, then update `head` |
| Time Complexity   | O(1)                                       |
| Memory Management | `new` allocates one node                   |

---

## 📌 `void deleteFirst()`

| Property          | Notes                                             |
|-------------------|---------------------------------------------------|
| Purpose           | Removes the first node.                           |
| Edge Cases        | Handles 0 or 1 node specially.                    |
| How It Works      | Updates `head` to `head->next`, deletes old head. |
| Time Complexity   | O(1)                                              |
| Memory Management | Deletes one node                                  |

---

## 📌 `Node<T>* getNodeAt(int index)`

| Property          | Notes                               |
|-------------------|-------------------------------------|
| Purpose           | Returns pointer to node at index.   |
| Inputs            | `index` (0-based)                   |
| Edge Cases        | Returns `nullptr` if index invalid. |
| How It Works      | Iterates to index using a loop.     |
| Time Complexity   | O(n)                                |
| Memory Management | No allocation or deletion           |

---

## 📌 `bool setNodeAt(int index, T nodeData)`

| Property          | Notes                                     |
|-------------------|-------------------------------------------|
| Purpose           | Sets data of node at specified index.     |
| Inputs            | `index`, new `nodeData`                   |
| Edge Cases        | Returns false if index invalid.           |
| How It Works      | Uses `getNodeAt()` and updates node->data |
| Time Complexity   | O(n) (due to getNodeAt)                   |
| Memory Management | None                                      |

---

## 📌 `bool insert(int index, T nodeData)`

| Property          | Notes                                          |
|-------------------|------------------------------------------------|
| Purpose           | Inserts a node at the specified index.         |
| Inputs            | `index`, new `nodeData`                        |
| Edge Cases        | Handles insert at beginning and end.           |
| How It Works      | Gets node at index-1, links new node in chain. |
| Time Complexity   | O(n)                                           |
| Memory Management | Allocates one node via `new`                   |

---

## 📌 `void deleteNodeAt(int index)`

| Property          | Notes                                             |
|-------------------|---------------------------------------------------|
| Purpose           | Deletes node at specific index.                   |
| Inputs            | `index`                                           |
| Edge Cases        | Handles first and last index specially.           |
| How It Works      | Re-links previous node to node after deleted one. |
| Time Complexity   | O(n)                                              |
| Memory Management | Deletes one node                                  |

---

## 📌 `void reverse()`

| Property          | Notes                                     |
|-------------------|-------------------------------------------|
| Purpose           | Reverses the order of the list.           |
| Edge Cases        | Safe for empty or single-node list.       |
| How It Works      | Iteratively reverses all `next` pointers. |
| Time Complexity   | O(n)                                      |
| Memory Management | None                                      |

---

## 📌 `void traverse() const`

| Property          | Notes                                 |
|-------------------|---------------------------------------|
| Purpose           | Prints all list elements in order.    |
| How It Works      | Loops through list from head to tail. |
| Time Complexity   | O(n)                                  |
| Memory Management | None                                  |

---

## 📌 `void printHead() const`

| Property        | Notes                                 |
|-----------------|---------------------------------------|
| Purpose         | Prints head node's data if it exists. |
| Edge Cases      | Does nothing if list is empty.        |
| Time Complexity | O(1)                                  |

---

## 📌 `void printTail() const`

| Property        | Notes                                 |
|-----------------|---------------------------------------|
| Purpose         | Prints tail node's data if it exists. |
| Edge Cases      | Does nothing if list is empty.        |
| Time Complexity | O(1)                                  |

---

## 📌 `void printLength() const`

| Property        | Notes                          |
|-----------------|--------------------------------|
| Purpose         | Prints the length of the list. |
| Time Complexity | O(1)                           |

---

## 📌 `void debug() const`

| Property        | Notes                                                   |
|-----------------|---------------------------------------------------------|
| Purpose         | Prints full internal state of list. Useful for testing. |
| What it prints  | Head, Tail, Length, All elements                        |
| Time Complexity | O(n)                                                    |

---
