# 🚀 Min Cost To Make Two Strings Identical

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1) |

---

### 📝 Problem Statement

Given two strings s1 and s2, and two integers costS1 and costS2, where costS1 is the cost of deleting one character from s1 and costS2 is the cost of deleting one character from s2, find the minimum cost required to make the two strings identical.You can delete any number of characters from either string, but the order of the remaining characters must be preserved.Examples:

### Input:
 s1 = "abcd", s2 = "acdb", costS1 = 10, costS2 = 20


### Output:
 30


### Explanation:
 Delete 'b' from both strings to obtain "acd". The total cost is 10 + 20 = 30.

### Input:
 s1 = "ef", s2 = "gh", costS1 = 10, costS2 = 20


### Output:
 60


### Explanation:
 The two strings have no common characters, so delete all characters from both strings. The total cost is (2 × 10) + (2 × 20) = 60.

---

### 🏢 Topic Tags

> `Dynamic Programming`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>