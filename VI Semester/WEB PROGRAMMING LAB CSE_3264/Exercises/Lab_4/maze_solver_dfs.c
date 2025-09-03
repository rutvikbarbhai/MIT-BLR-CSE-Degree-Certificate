#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 5
#define MAX_COLS 5

// Structure to represent a point in the maze
typedef struct {
    int row;
    int col;
} Point;

// Function to check if a point is valid in the maze
int isValidPoint(int row, int col) {
    return (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS);
}

// Function to construct a graph for the maze
void constructGraph(int maze[MAX_ROWS][MAX_COLS], int graph[MAX_ROWS * MAX_COLS][4]) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            int vertex = row * MAX_COLS + col;

            if (maze[row][col] == 1) {
                // Dead end
                for (int i = 0; i < 4; i++) {
                    graph[vertex][i] = -1; // No path in any direction
                }
            } else {
                // Crossroad or path
                for (int i = 0; i < 4; i++) {
                    int newRow = row + directions[i][0];
                    int newCol = col + directions[i][1];

                    if (isValidPoint(newRow, newCol) && maze[newRow][newCol] != 1) {
                        graph[vertex][i] = newRow * MAX_COLS + newCol;
                    } else {
                        graph[vertex][i] = -1; // No path in that direction
                    }
                }
            }
        }
    }
}

// Function to perform DFS to find a path through the maze
int dfsFindPath(int graph[MAX_ROWS * MAX_COLS][4], int startVertex, int endVertex, int visited[MAX_ROWS * MAX_COLS]) {
    if (startVertex == endVertex) {
        return 1; // Path found
    }

    visited[startVertex] = 1;

    for (int i = 0; i < 4; i++) {
        int nextVertex = graph[startVertex][i];
        if (nextVertex != -1 && !visited[nextVertex]) {
            if (dfsFindPath(graph, nextVertex, endVertex, visited)) {
                printf("(%d, %d) -> ", nextVertex / MAX_COLS, nextVertex % MAX_COLS);
                return 1;
            }
        }
    }

    return 0; // No path found
}

int main() {
    int maze[MAX_ROWS][MAX_COLS] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int graph[MAX_ROWS * MAX_COLS][4];
    constructGraph(maze, graph);

    int startVertex = 0; // Starting point
    int endVertex = (MAX_ROWS - 1) * MAX_COLS + (MAX_COLS - 1); // Finishing point

    int visited[MAX_ROWS * MAX_COLS] = {0};

    printf("Solution to the maze using DFS:\n");
    printf("Start -> ");
    
    if (dfsFindPath(graph, startVertex, endVertex, visited)) {
        printf("(%d, %d) [Finish]\n", endVertex / MAX_COLS, endVertex % MAX_COLS);
    } else {
        printf("No path found.\n");
    }

    return 0;
}
