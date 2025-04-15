# Algorithms in C++

This repository contains C++ implementations of fundamental algorithms such as sorting, searching, and more. The goal is to provide clear and simple examples of common algorithms, helping developers and students understand the concepts behind them and their applications.

## Algorithms Implemented

### 1. **Sorting Algorithms**
- `sort`: General sorting algorithms such as **bubble sort**, **selection sort**, **insertion sort**, and others. Implementations may vary in terms of performance characteristics and use cases.

### 2. **Binary Search**
- `binary_search.cpp`: Implementation of the **binary search** algorithm. This efficient search algorithm finds the position of a target value within a **sorted array** in O(log n) time complexity.

### 3. **Merge Sort**
- `merge_sort.cpp`: A **merge sort** algorithm implementation that follows the **divide and conquer** technique. It sorts an array in O(n log n) time complexity.

### 4. **Map Operations**
- `map.cpp`: Implements various algorithms on a **map** data structure. Provides examples of key-value pair manipulations, including insertion, deletion, and searching.

### 5. **Priority Queue Algorithms**
- `priority_queue.cpp`: Implements algorithms for the **priority queue** data structure. This includes inserting elements based on priority and extracting the highest or lowest priority element.

### 6. **Set Operations**
- `set.cpp`: Implements **set** data structure algorithms. Provides examples of element insertion, deletion, and set union/intersection operations.

### 7. **Unordered Map**
- `unordered_map.cpp`: Implements an **unordered map** and demonstrates efficient key-value pair access using hashing.

### 8. **Unordered Set**
- `unordered_set.cpp`: Implements an **unordered set**, focusing on efficient storage and searching of unique elements.

### 9. **Vector Algorithms**
- `vector.cpp`: Implements algorithms that manipulate the **vector** data structure, focusing on dynamic resizing, element access, and iteration.

## Algorithms Implemented with Examples

### Sorting:
- **Bubble Sort**: Simple sorting algorithm, swaps adjacent elements if they are in the wrong order.
- **Selection Sort**: Finds the minimum element in the unsorted part and swaps it with the current position.
- **Insertion Sort**: Builds the sorted array one element at a time by inserting each element into its correct position.

### Searching:
- **Binary Search**: Efficiently finds the index of a target element in a **sorted array** by repeatedly dividing the search interval in half.

### Merge Sort:
- **Merge Sort**: A divide-and-conquer algorithm that recursively splits the array into smaller parts, sorts them, and merges them.

### Map Operations:
- **Insert**: Add key-value pairs to a map.
- **Erase**: Remove a key-value pair from the map.
- **Find**: Search for a key in the map.

### Priority Queue:
- **Insert**: Add an element with a specific priority.
- **Extract**: Remove the element with the highest priority (or lowest, depending on the heap).

### Set Operations:
- **Insert**: Add elements to the set.
- **Erase**: Remove elements from the set.
- **Union & Intersection**: Combine sets or find common elements.

### Unordered Map & Set:
- **Insert**: Insert elements efficiently using hashing.
- **Find**: Search for elements in constant time on average.

## Compilation and Usage

### Prerequisites:
- A C++11 or later compliant compiler.

### To compile and run any example (e.g., `binary_search.cpp`):

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/ALGO.git
   cd ALGO

