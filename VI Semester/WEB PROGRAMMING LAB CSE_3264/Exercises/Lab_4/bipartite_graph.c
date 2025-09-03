#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to add an edge to the adjacency list
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to perform DFS and check for bipartite
int dfsCheckBipartite(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int colors[], int vertex, int color) {
    colors[vertex] = color;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i]) {
            if (colors[i] == -1) {
                if (!dfsCheckBipartite(graph, numVertices, colors, i, 1 - color)) {
                    return 0;
                }
            } else if (colors[i] == color) {
                return 0; // Graph is not bipartite
            }
        }
    }

    return 1; // Graph is bipartite
}

// Function to check bipartite using DFS
int isBipartiteDFS(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int colors[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        colors[i] = -1; // Initialize colors to -1 (unvisited)
    }

    for (int i = 0; i < numVertices; i++) {
        if (colors[i] == -1) {
            if (!dfsCheckBipartite(graph, numVertices, colors, i, 0)) {
                return 0; // Graph is not bipartite
            }
        }
    }

    return 1; // Graph is bipartite
}

// Function to check bipartite using BFS
int isBipartiteBFS(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int colors[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        colors[i] = -1; // Initialize colors to -1 (unvisited)
    }

    for (int i = 0; i < numVertices; i++) {
        if (colors[i] == -1) {
            colors[i] = 0; // Color the source vertex

            // Create a queue for BFS
            int queue[MAX_VERTICES];
            int front = -1, rear = -1;
            queue[++rear] = i;

            while (front != rear) {
                int currentVertex = queue[++front];

                for (int j = 0; j < numVertices; j++) {
                    if (graph[currentVertex][j]) {
                        if (colors[j] == -1) {
                            colors[j] = 1 - colors[currentVertex];
                            queue[++rear] = j;
                        } else if (colors[j] == colors[currentVertex]) {
                            return 0; // Graph is not bipartite
                        }
                    }
                }
            }
        }
    }

    return 1; // Graph is bipartite
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Check bipartite using DFS
    if (isBipartiteDFS(graph, numVertices)) {
        printf("Graph is bipartite (DFS).\n");
    } else {
        printf("Graph is not bipartite (DFS).\n");
    }

    // Check bipartite using BFS
    if (isBipartiteBFS(graph, numVertices)) {
        printf("Graph is bipartite (BFS).\n");
    } else {
        printf("Graph is not bipartite (BFS).\n");
    }

    return 0;
}
