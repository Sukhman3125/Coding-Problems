# 🚀 Largest Subsquare Surrounded by X

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1) |

---

### 📝 Problem Statement

Given a square matrix mat[][] of size n × n, where each cell contains either 'X' or 'O'. Find the size of the largest square submatrix whose boundary is completely surrounded by 'X'. The cells inside the submatrix can contain either 'X' or 'O'. Only the four sides of the submatrix must contain 'X'.Return side length of the largest such square submatrix. Note: A square of size 1 is valid if its only cell is 'X'. If no such square submatrix exists, return 0.Examples:

### Input:
 mat[][] = [[X,X,X,O],[X,O,X,X],[X,X,X,O],[X,O,X,X]] 

### Output:
 3


### Explanation:
 Here, the input represents following matrix of size 4 x 4
 The square submatrix starting at (0,0) and ending at (2,2) is the largest submatrix surrounded by X. Therefore, size of that matrix would be 3.

### Input:
 mat[][] = [[X,X],[X,X]] 

### Output:
 2

### Explanation:
 The largest square submatrix surrounded by X is the whole input matrix.

---

### 🏢 Topic Tags

> `Matrix`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>