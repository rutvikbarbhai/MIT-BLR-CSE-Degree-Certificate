#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int firstMatrix[MAX_SIZE][MAX_SIZE], int secondMatrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    if (colFirst != rowSecond) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    // Initializing elements of result matrix to 0
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying firstMatrix and secondMatrix and storing the result in result
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            for (int k = 0; k < colFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d  ", matrix[i][j]);
            if (j == col - 1) {
                printf("\n");
            }
        }
    }
}

int main() {
    int firstMatrix[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int secondMatrix[MAX_SIZE][MAX_SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[MAX_SIZE][MAX_SIZE];

    int rowFirst = 3, colFirst = 3;
    int rowSecond = 3, colSecond = 3;

    printf("First matrix:\n");
    displayMatrix(firstMatrix, rowFirst, colFirst);

    printf("\nSecond matrix:\n");
    displayMatrix(secondMatrix, rowSecond, colSecond);

    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, colFirst, rowSecond, colSecond);

    printf("\nResult matrix:\n");
    displayMatrix(result, rowFirst, colSecond);

    return 0;
}
