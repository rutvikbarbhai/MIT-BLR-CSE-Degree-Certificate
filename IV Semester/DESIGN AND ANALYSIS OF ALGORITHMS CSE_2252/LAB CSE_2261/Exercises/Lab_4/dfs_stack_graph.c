#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6

// Structure to represent a stack (used for DFS)
typedef struct {
    int data[MAX_VERTICES];
    int top;
} Stack;

// Function to initialize an empty stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == MAX_VERTICES - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to perform Depth-First Search (DFS) on the graph
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int visited[MAX_VERTICES], Stack* stack) {
    visited[vertex] = 1;
    printf("Push: %d\n", vertex);

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(graph, i, visited, stack);
        }
    }

    printf("Pop: %d\n", vertex);
    push(stack, vertex);  // Push the vertex onto the stack after visiting its neighbors
}

// Function to initialize the visited array and perform DFS
void dfsTraversal(int graph[MAX_VERTICES][MAX_VERTICES]) {
    int visited[MAX_VERTICES] = {0};
    Stack stack;
    initializeStack(&stack);

    printf("DFS Push and Pop Order:\n");
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, &stack);
        }
    }

    // Display the vertices in the order they are popped from the stack
    printf("\nDFS Pop Order (Top to Bottom of Stack):\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}

int main() {
    // Example graph adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    dfsTraversal(graph);

    return 0;
}




