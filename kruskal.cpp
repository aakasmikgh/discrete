//WAP to find minimum spanning tree (krushkal)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int numVertices, numEdges;
    struct Edge* edges;
};

// Structure to represent a subset for disjoint-set data structure
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph
struct Graph*createGraph(int numVertices, int numEdges) {
    struct Graph*graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
    return graph;
};

// Function to create a subset for disjoint-set
struct Subset*createSubset(int numVertices) {
    struct Subset*subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));
    for (int i = 0;i < numVertices;i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    return subsets;
}

// Function to find the parent of a subset
int find(struct Subset subsets[],int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets,subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare edges by weight (used for sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(struct Graph*graph) {
    int numVertices = graph->numVertices;
    struct Edge result[numVertices];
    int e = 0;
    int i = 0;

    // Sort all the edges in the graph in ascending order of weight
    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compareEdges);

    struct Subset* subsets = createSubset(numVertices);

    while (e < numVertices - 1 && i < graph->numEdges) {
        struct Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree (MST) using Kruskal's algorithm:\n");
    for (int j = 0; j < e; j++) {
        printf("Edge %d - %d, Weight: %d\n", result[j].src, result[j].dest, result[j].weight);
    }
}

int main() {
    struct Graph* graph = createGraph(V, V - 1); // A connected graph has V - 1 edges

    // Example edges with weights
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 2;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 3;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 3;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 8;

    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;
    graph->edges[4].weight = 5;

    graph->edges[5].src = 2;
    graph->edges[5].dest = 4;
    graph->edges[5].weight = 7;

    graph->edges[6].src = 3;
    graph->edges[6].dest = 4;
    graph->edges[6].weight = 9;

    kruskalMST(graph);

    return 0;
}