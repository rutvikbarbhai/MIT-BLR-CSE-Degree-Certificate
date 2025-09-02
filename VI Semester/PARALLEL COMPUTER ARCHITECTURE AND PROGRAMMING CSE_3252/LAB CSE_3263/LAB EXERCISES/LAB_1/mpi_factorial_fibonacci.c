#include <mpi.h>
#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char** argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the rank and size of the processes
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank % 2 == 0) {
        // Even-ranked process: Calculate factorial
        unsigned long long fact = factorial(rank);
        printf("Process %d (Even): Factorial of %d = %llu\n", rank, rank, fact);
    } else {
        // Odd-ranked process: Calculate Fibonacci
        unsigned long long fib = fibonacci(rank);
        printf("Process %d (Odd): Fibonacci number at %d = %llu\n", rank, rank, fib);
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
