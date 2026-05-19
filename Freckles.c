#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Maximum number of freckles (points)
#define MAXN 100

// Maximum possible edges between points
// Formula: n(n-1)/2
#define MAXE 5000

// Structure to store a point coordinate
typedef struct {
    double x, y;
} Point;

// Structure to store an edge between 2 points
typedef struct {
    int u, v;          // index of connected points
    double weight;     // distance between the points
} Edge;

// DSU (Disjoint Set Union) parent array
// Used for Kruskal's algorithm
int parent[MAXN];


// -----
// FIND 
// -----
// Finds the representative parent of a set
// Path compression is used to make future searches faster
int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}


// ------
// UNION 
// ------
// Merges two sets together
void unionSet(int a, int b) {
    parent[find(b)] = find(a);
}


// ---------
// DISTANCE 
// ---------
// Calculates Euclidean distance between 2 points
double distance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) +
                (b.y - a.y) * (b.y - a.y));
}


// ---------------------------
// COMPARE FUNCTION FOR QSORT
// ---------------------------
// Sorts edges from smallest weight to largest weight
// Needed for Kruskal's algorithm
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;

    if (e1->weight > e2->weight)
        return 1;

    if (e1->weight < e2->weight)
        return -1;

    return 0;
}


int main() {

    // Number of test cases
    int T;
    scanf("%d", &T);

    // Process each test case
    while (T--) {

        // Number of freckles (points)
        int n;
        scanf("%d", &n);

        // Array to store all points
        Point points[MAXN];

        // Array to store all possible edges
        Edge edges[MAXE];

        // Counts how many edges are created
        int edgeCount = 0;


        // -----------------
        // INPUT ALL POINTS
        // -----------------
        // Read x and y coordinates
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }


        // --------------------------
        // CREATE ALL POSSIBLE EDGES
        // --------------------------
        // Connect every point with every other point
        // and calculate their distances
        for (int u = 0; u < n; u++) {

            for (int v = u + 1; v < n; v++) {

                edges[edgeCount].u = u;
                edges[edgeCount].v = v;

                // Distance becomes edge weight
                edges[edgeCount].weight =
                    distance(points[u], points[v]);

                edgeCount++;
            }
        }


        // -----------
        // SORT EDGES
        // -----------
        // Smallest distances first
        qsort(edges, edgeCount, sizeof(Edge), compare);


        // ---------------
        // INITIALIZE DSU
        // ---------------
        // Initially every point is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }


        // Total minimum ink length
        double total_ink = 0.0;

        // Counts how many edges are added to MST
        int edges_added = 0;


        // --------------------
        // KRUSKAL'S ALGORITHM
        // --------------------
        // Take edges from smallest to largest
        for (int i = 0; i < edgeCount; i++) {

            // Find parent set of both vertices
            int set_u = find(edges[i].u);
            int set_v = find(edges[i].v);


            // If they are in different sets,
            // adding this edge will NOT form a cycle
            if (set_u != set_v) {

                // Merge the sets
                unionSet(set_u, set_v);

                // Add edge weight to total answer
                total_ink += edges[i].weight;

                edges_added++;


                // MST is complete when it has n-1 edges
                if (edges_added == n - 1)
                    break;
            }
        }


        // -------
        // OUTPUT 
        // -------
        // Print result with 2 decimal places
        printf("%.2lf\n", total_ink);


        // Print blank line between test cases
        if (T)
            printf("\n");
    }

    return 0;
}

