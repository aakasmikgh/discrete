/*Write a program to Represent graphs
    i)Adjacency list
    ii)Matrix */
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent an adjacency list
struct AdjacencyList {
    struct Node* head;
};

// Structure to represent a graph using adjacency list
struct GraphAdjacencyList {
    int numVertices;
    struct AdjacencyList* array;
};

// Structure to represent a graph using adjacency matrix
struct GraphAdjacencyMatrix {
    int numVertices;
    int** matrix;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph using adjacency list
struct GraphAdjacencyList* createGraphAdjacencyList(int numVertices) {
    struct GraphAdjacencyList* graph = (struct GraphAdjacencyList*)malloc(sizeof(struct GraphAdjacencyList));
    graph->numVertices = numVertices;

    graph->array = (struct AdjacencyList*)malloc(numVertices * sizeof(struct AdjacencyList));

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph using adjacency list
void addEdgeAdjacencyList(struct GraphAdjacencyList* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to create a graph using adjacency matrix
struct GraphAdjacencyMatrix* createGraphAdjacencyMatrix(int numVertices) {
    struct GraphAdjacencyMatrix* graph = (struct GraphAdjacencyMatrix*)malloc(sizeof(struct GraphAdjacencyMatrix));
    graph->numVertices = numVertices;

    graph->matrix = (int**)malloc(numVertices * sizeof(int*));

    for (int i = 0; i < numVertices; ++i) {
        graph->matrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; ++j) {
            graph->matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph using adjacency matrix
void addEdgeAdjacencyMatrix(struct GraphAdjacencyMatrix* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

// Function to print the graph represented by adjacency list
void printGraphAdjacencyList(struct GraphAdjacencyList* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* temp = graph->array[i].head;
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to print the graph represented by adjacency matrix
void printGraphAdjacencyMatrix(struct GraphAdjacencyMatrix* graph) {
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;

    // Create a graph using adjacency list
    struct GraphAdjacencyList* adjacencyListGraph = createGraphAdjacencyList(numVertices);
    addEdgeAdjacencyList(adjacencyListGraph, 0, 1);
    addEdgeAdjacencyList(adjacencyListGraph, 0, 2);
    addEdgeAdjacencyList(adjacencyListGraph, 1, 3);
    addEdgeAdjacencyList(adjacencyListGraph, 2, 4);

    // Print the graph represented by adjacency list
    printf("Adjacency List Representation:\n");
    printGraphAdjacencyList(adjacencyListGraph);

    // Create a graph using adjacency matrix
    struct GraphAdjacencyMatrix* adjacencyMatrixGraph = createGraphAdjacencyMatrix(numVertices);
    addEdgeAdjacencyMatrix(adjacencyMatrixGraph, 0, 1);
    addEdgeAdjacencyMatrix(adjacencyMatrixGraph, 0, 2);
    addEdgeAdjacencyMatrix(adjacencyMatrixGraph, 1, 3);
    addEdgeAdjacencyMatrix(adjacencyMatrixGraph, 2, 4);

    // Print the graph represented by adjacency matrix
    printGraphAdjacencyMatrix(adjacencyMatrixGraph);

    return 0;
}