#include <mpi.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the rank and size of the process
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Constant x (base)
    const int x = 2; // You can change this value

    // Compute pow(x, rank)
    double result = pow(x, rank);

    // Print the result from each process
    printf("Process %d: %d^%d = %.0f\n", rank, x, rank, result);

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
