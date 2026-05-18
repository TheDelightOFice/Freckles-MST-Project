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
