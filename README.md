# Freckles-MST-Project

## Group M
- Keven John Gondowardojo (5025251016)
- Renato Kiran Arisandi (5025251015)
- Hussein Mohammad Mahsun (5025251170)
- I Gusti Agung Candra Nugraha (5025251169

## Problem we used
https://open.kattis.com/problems/freckles


## Problem Description
In this problem, we are given several freckles represented as points on a 2D space.Our task is to connect all of these freckles using straight lines so that every freckle is connected, either directly or indirectly, while keeping the total distance as small as possible.
Because we want the minimum total connection cost, this problem can be solved using the **Minimum Spanning Tree (MST)** concept.
The distance between two freckles is calculated using the Euclidean distance formula:

    d = √((x₂ - x₁)² + (y₂ - y₁)²)

# Freckles - MST Project

## Group M
- Keven (5025251016)
- Kyan (5025251015)
- Hussein (5025251170)
- Candra (5025251169)

---

## Problem Link
https://open.kattis.com/problems/freckles

---

## Problem Description
In this problem, we are given several freckles represented as points on a 2D coordinate plane.

Our task is to connect all of these freckles using straight lines so that every freckle is connected, either directly or indirectly, while keeping the total distance as small as possible.

Because we want the minimum total connection cost, this problem can be solved using the **Minimum Spanning Tree (MST)** concept.

The distance between two freckles is calculated using the Euclidean distance formula:

d = √((x₂ - x₁)² + (y₂ - y₁)²)

---

## Algorithm Used
### Kruskal's Algorithm

Steps:
1. Calculate all possible edges between all freckles
2. Sort all edges from smallest to largest distance
3. Pick the smallest edge
4. Check if adding it creates a cycle
5. If there is no cycle then add it to the MST
6. Repeat it until all freckles are connected

---

## Disjoint Set Union (Union-Find)
We use DSU to detect cycles efficiently

---

## IMPORTANT NOTES

# Find Function

![image alt](https://github.com/TheDelightOFice/Freckles-MST-Project/blob/e9ab6dcdd5bd312ed3312eb4bc73eb112d451d4f/Screenshot%202026-05-19%20232245.png)

The find function determines which set a point belongs to by finding it's root parent. If the point is already it's own parent, it returns immediately. If it doesn't, it continues moving upward untill it finds the root parent.

# Union Function

![image alt](https://github.com/TheDelightOFice/Freckles-MST-Project/blob/e9ab6dcdd5bd312ed3312eb4bc73eb112d451d4f/Screenshot%202026-05-19%20232518.png)

The unionset cuntion comines the two different sets into one. When Kruskal chooses a valid edge, the two connected poins must now belong to the same group, unionset updates the DSU structure by linking their parents together.

# Creating Possible Edges & Calculating Distance

![image alt](https://github.com/TheDelightOFice/Freckles-MST-Project/blob/a0724b583f8e266c0df430396bcd11f2de6213a6/Screenshot%202026-05-19%20232102.png)

This section builds the grap by creating every possible connection between points. The nested loop generate all point pairs and for each pair, the program stores both points, calculates the distance between them, the distance function uses the Euclidean distance formula. These distances are the edge weights that will be used by the Kruskal Algorithmm.

# Quicksort Function

![image alt](https://github.com/TheDelightOFice/Freckles-MST-Project/blob/a0724b583f8e266c0df430396bcd11f2de6213a6/Screenshot%202026-05-19%20232428.png)

After generating all edges, the program sorts them from shortest to longest distance. Sorting is necessary because Kruskal Algorithm always picks the smallest available edge first. The compare function tells qsort how to compare two edges and orders them in ascending order.

# DSU

![image alt](https://github.com/TheDelightOFice/Freckles-MST-Project/blob/a0724b583f8e266c0df430396bcd11f2de6213a6/Screenshot%202026-05-19%20232343.png)

The code uses DSU to keep track of which points are already connected. In Kruskal Algorithm, we must avoid cycles, so before adding an edge, the program checks whether the two points already belong to the same connected group. The DSU structure is implemented using the parent array. 

# Kruskal Algorithm

![image alt](https://github.com/TheDelightOFice/Freckles-MST-Project/blob/a0724b583f8e266c0df430396bcd11f2de6213a6/Screenshot%202026-05-19%20232548.png)

This is the main part of the program that builds the Minimum Spanning Tree (MST). It checks the edges one by one after sorting. For each edge, it finds the parents sets, then it checks if the parents are differen, adding the edge will not create a cycle, so the edge is accepted. The prgram then merges the set and adds the edge weight to the total answer. The algorithm stops once n-1 edges are added because an MST for n points always contains n-1 edges. 
