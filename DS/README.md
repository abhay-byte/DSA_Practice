# Data Structures in C++

This repository contains C++ implementations of various data structures including linked lists, trees, graphs, heaps, and more. The goal is to provide clear, concise examples for each data structure and their operations, helping developers and students understand the underlying mechanics of these structures.

## Data Structures Implemented

### 1. **Linked List**
- `linked_list.cpp`: Basic implementation of a **singly linked list**.
- `circular_linked_list.cpp`: Basic implementation of a **circular linked list**.

### 2. **Graph**
- `graph.cpp`: Implementation of a **graph** with basic operations (adjacency list representation).

### 3. **Map**
- `map.cpp`: Implementation of the **map** data structure (associative array), with key-value pairs sorted by key.

### 4. **Priority Queue**
- `priority_queue.cpp`: Implementation of a **priority queue**, utilizing a heap (max-heap by default).

### 5. **Set**
- `set.cpp`: Implementation of the **set** data structure, which stores unique elements in sorted order.

### 6. **Tree**
- `tree.cpp`: Implementation of a basic **binary tree** with fundamental tree operations.

### 7. **Unordered Map**
- `unordered_map.cpp`: Implementation of an **unordered map**, using hashing for efficient key-value access.

### 8. **Unordered Set**
- `unordered_set.cpp`: Implementation of an **unordered set**, using hashing to store unique elements.

### 9. **Vector**
- `vector.cpp`: Implementation of the **vector** data structure, with dynamic array resizing.

### 10. **List**
- `list.cpp`: Implementation of the **doubly linked list**, allowing operations from both ends.

## Operations Provided

Each data structure includes the following core operations:

- **Add**: Insert an element into the data structure.
- **Remove**: Remove an element from the data structure.
- **Traverse**: Iterate through the elements.
- **Search**: Find if an element exists in the data structure.
- **Sort**: Sort elements (if applicable).
- **Priority**: Set the priority (for `priority_queue`).

### Examples of Operations:

- **Adding and Removing Elements**: Each implementation supports adding and removing elements (such as inserting a node into a linked list or inserting an item into a priority queue).
  
- **Traversing**: Methods like `traverse()` and iteration techniques are included to allow traversal through data structures.

- **Sorting**: Where applicable, sorting is implemented. For instance, vectors and sets are sorted using built-in sorting functions.

- **Priority Queue**: For priority queues, you can change the order (max-heap or min-heap).

## Compilation and Usage

### Prerequisites:
- A C++11 or later compliant compiler.

### To compile and run the examples:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/DS.git
   cd DS

