# 🚀 Check Level Anagrams in Binary Trees

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1) |

---

### 📝 Problem Statement

Given the roots of two binary trees root1 and root2, check whether the nodes at every corresponding level of the two trees are anagrams of each other. Two levels are considered anagrams if they contain the same node values with the same frequencies, regardless of their order.Examples:

### Input:
 root1 = [1, 3, 2, N, N, 5, 4], root2 = [1, 2, 3, 4, 5, N, N]

### Output:
 true


### Explanation:
 
Level 0: [1] and [1]
Level 1: [3, 2] and [2, 3]
Level 2: [5, 4] and [4, 5]
The node values at every corresponding level are anagrams of each other. Hence, the answer is true.

### Input:
 root1 = [1, 2, 3, 5, 4], root2 = [1, 2, 4, 5, 3]


### Output:
 false


### Explanation:
 Level 0: [1] and [1]
Level 1: [2, 3] and [2, 4]
Since the node values at level 1 are not anagrams, the answer is false.

---

### 🏢 Topic Tags

> `Tree`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>