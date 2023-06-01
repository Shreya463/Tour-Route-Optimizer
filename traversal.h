#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>
#include"Stack.h"
#define MAX_SIZE 30
int findVertexWithOneConnection(int adjacencyMatrix[MAX_SIZE][MAX_SIZE], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        int connectionCount = 0;
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j]!=0 && adjacencyMatrix[i][j]!=-1 ) {
                connectionCount++;
            }
        }
        if (connectionCount == 1) {
            return i;
            
        }
    }
    return -1; // If no such vertex is found
}
int* dfs(int graph[MAX_SIZE][MAX_SIZE], int vertices) {
    int visited[MAX_SIZE] = {0}; // Array to track visited vertices
    int start=findVertexWithOneConnection(graph,vertices);
    struct Stack stack;
    create(&stack);

    push(&stack, start); // Push the starting vertex onto the stack

    int* traversedNodes = (int*)malloc(vertices * sizeof(int));
    int index = 0;

    while (!isEmpty(stack)) {
        int vertex = pop(&stack); // Pop a vertex from the stack

        if (!visited[vertex]) {
            visited[vertex] = 1; // Mark the vertex as visited
            traversedNodes[index++] = vertex; // Store the traversed vertex in the array

            // Traverse the neighbors of the current vertex
            for (int i = 0; i < vertices; i++) {
                if (graph[vertex][i] != 0 && graph[vertex][i] != -1 && !visited[i]) {
                    push(&stack, i); // Push unvisited neighbor onto the stack
                }
            }
        }
    }

    return traversedNodes;
}

void printarray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}
