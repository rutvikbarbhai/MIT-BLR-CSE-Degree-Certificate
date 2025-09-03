#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N_MAX 10  // Maximum number of agents/tasks

int costMatrix[N_MAX][N_MAX];
int minCost = INT_MAX;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculateCost(int assignment[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }

    if (totalCost < minCost) {
        minCost = totalCost;
    }
}

void permute(int assignment[], int start, int end, int n) {
    if (start == end) {
        calculateCost(assignment, n);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&assignment[start], &assignment[i]);
        permute(assignment, start + 1, end, n);
        swap(&assignment[start], &assignment[i]);  // backtrack
    }
}

int main() {
    int n;

    // Get the number of agents/tasks from the user
    printf("Enter the number of agents/tasks (maximum %d): ", N_MAX);
    scanf("%d", &n);

    if (n <= 0 || n > N_MAX) {
        printf("Invalid number of agents/tasks.\n");
        return 1;
    }

    // Get the cost matrix from the user
    printf("Enter the cost matrix for %d agents/tasks:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Cost from agent %d to task %d: ", i + 1, j + 1);
            scanf("%d", &costMatrix[i][j]);
        }
    }

    int assignment[N_MAX];

    // Initialize assignment array with initial task order (0, 1, 2, ..., n-1)
    for (int i = 0; i < n; i++) {
        assignment[i] = i;
    }

    permute(assignment, 0, n - 1, n);

    printf("Minimum Cost: %d\n", minCost);

    return 0;
}
