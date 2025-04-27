# My C Algorithms & Data Structures Library

This is my personal collection of C implementations for common CS problems.
I'm building this mostly to practice my C skills.

## What's in here?

### Data Structures

#### Fundamental

- [ ] Dynamic Array (with resizing)
- [ ] Linked List (singly and doubly)
- [ ] Stack
- [ ] Queue
- [ ] Circular Queue
- [ ] Priority Queue

#### Trees

- [ ] Binary Search Tree
- [ ] AVL Tree (self-balancing)
- [ ] Red-Black Tree
- [ ] B-Tree
- [ ] Trie (Prefix Tree)
- [ ] Heap (Min and Max)

#### Hash-Based

- [ ] Hash Table (with collision handling)
- [ ] Hash Set
- [ ] Hash Map

#### Graphs

- [ ] Adjacency Matrix
- [ ] Adjacency List
- [ ] Weighted Graph

### Algorithms

#### Sorting

- [x] Bubble Sort
- [x] Selection Sort
- [ ] Insertion Sort
- [x] Merge Sort
- [ ] Quick Sort
- [ ] Heap Sort
- [ ] Radix Sort
- [ ] Counting Sort

#### Searching

- [x] Linear Search
- [x] Binary Search
- [ ] Interpolation Search
- [ ] Jump Search

#### Graph Algorithms

- [ ] Breadth-First Search (BFS)
- [ ] Depth-First Search (DFS)
- [ ] Dijkstra's Algorithm
- [ ] Bellman-Ford Algorithm
- [ ] Floyd-Warshall Algorithm
- [ ] Kruskal's Algorithm
- [ ] Prim's Algorithm
- [ ] Topological Sort

#### String Algorithms

- [ ] String Matching (Naive)
- [ ] Knuth-Morris-Pratt Algorithm
- [ ] Rabin-Karp Algorithm
- [ ] Longest Common Subsequence
- [ ] Levenshtein Distance (Edit Distance)

#### Dynamic Programming

- [ ] Fibonacci Sequence
- [ ] Knapsack Problem
- [ ] Longest Increasing Subsequence
- [ ] Matrix Chain Multiplication
- [ ] Coin Change Problem

#### Advanced Topics

- [ ] Union-Find Data Structure
- [ ] Segment Tree
- [ ] Fenwick Tree (Binary Indexed Tree)
- [ ] Bloom Filter
- [ ] Skip List

## How to build

Just run `make` in the root directory. If you want to test things:

```bash
make test
```

## Notes to myself

- Remember to check for memory leaks with Valgrind
- I'm using a consistent error handling pattern where functions return bool
- Use [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/#summary)

## Reference resources

- "Algorithms in C" by Robert Sedgewick
- [TheAlgorithms library](https://github.com/TheAlgorithms/C)
