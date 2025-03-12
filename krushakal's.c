#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store an edge
struct Edge {
    int src, dest, weight;
};

// Structure to store a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the root of a subset (using path compression)
int findParent(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findParent(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets (using union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = findParent(subsets, x);
    int rootY = findParent(subsets, y);
    
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Function to compare edges based on weight (for sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(struct Edge edges[], int n, int e) {
    struct Edge result[MAX]; // Store MST edges
    struct Subset subsets[MAX];
    int mstSize = 0;
    
    // Initialize subsets
    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // Sort edges by weight
    qsort(edges, e, sizeof(edges[0]), compareEdges);
    
    int i = 0; // Index for sorted edges
    while (mstSize < n - 1 && i < e) {
        struct Edge nextEdge = edges[i++];
        int x = findParent(subsets, nextEdge.src);
        int y = findParent(subsets, nextEdge.dest);
        
        if (x != y) { // No cycle formed
            result[mstSize++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    
    // Print the MST
    printf("Minimum Spanning Tree using Kruskal's Algorithm:\n");
    printf("Edge   Weight\n");
    for (i = 0; i < mstSize; i++) {
        printf("%d - %d    %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int n, e;
    struct Edge edges[MAX];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    
    kruskalMST(edges, n, e);
    
    return 0;
}

