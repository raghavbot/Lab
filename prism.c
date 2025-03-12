#include <stdio.h>
#include <limits.h>

#define MAX 100 // Maximum number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the Minimum Spanning Tree
void printMST(int parent[], int graph[MAX][MAX], int n)
{
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's Algorithm
void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX]; // Stores the MST
    int key[MAX];    // Stores minimum weights
    int mstSet[MAX]; // Boolean array to mark selected vertices

    // Initialize key values and MST set
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;     // Start from the first vertex
    parent[0] = -1; // First node is the root

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n); // Pick the minimum key vertex
        mstSet[u] = 1;                  // Mark as included

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph, n);

    return 0;
}
