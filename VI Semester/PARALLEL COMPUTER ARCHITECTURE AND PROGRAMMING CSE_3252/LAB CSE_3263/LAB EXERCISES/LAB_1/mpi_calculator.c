#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get rank and size of the processes
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Ensure at least 4 processes for calculator operations
    if (size < 4) {
        if (rank == 0) {
            printf("Please run the program with at least 4 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }

    // Input values (shared across all processes)
    const int a = 20;
    const int b = 10;
    double result;

    // Perform operations based on rank
    switch (rank) {
        case 0:
            result = a + b;
            printf("Process %d: Addition (%d + %d) = %.2f\n", rank, a, b, result);
            break;
        case 1:
            result = a - b;
            printf("Process %d: Subtraction (%d - %d) = %.2f\n", rank, a, b, result);
            break;
        case 2:
            result = a * b;
            printf("Process %d: Multiplication (%d * %d) = %.2f\n", rank, a, b, result);
            break;
        case 3:
            if (b != 0) {
                result = (double)a / b;
                printf("Process %d: Division (%d / %d) = %.2f\n", rank, a, b, result);
            } else {
                printf("Process %d: Division by zero error!\n", rank);
            }
            break;
        default:
            printf("Process %d: No operation assigned.\n", rank);
            break;
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
