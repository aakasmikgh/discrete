//Write a program to find shortest path(Dijkastra)
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from source to target
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

// Function to print the distance and shortest paths from the source vertex
void printSolution(int dist[], int n, int parent[]) {
    int src = 0;
    printf("Vertex\tDistance from Source\tPath\n");

    for (int i = 1; i < V; i++) {
        printf("%d -> %d\t%d\t\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

// Function to perform Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Array to store the shortest distance from the source to each vertex
    bool sptSet[V];   // Array to mark vertices included in the shortest path tree
    int parent[V];    // Array to store the shortest path tree

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, V, parent);
}

int main() {
    // Example adjacency matrix representing the weighted graph
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    printf("Shortest paths from vertex 0 (source):\n");
    dijkstra(graph, 0);

    return 0;
}