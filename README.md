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
