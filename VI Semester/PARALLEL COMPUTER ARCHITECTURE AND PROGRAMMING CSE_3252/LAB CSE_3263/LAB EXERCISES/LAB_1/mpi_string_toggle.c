#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the rank and size of the processes
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Input string (shared across processes)
    char str[] = "HelloWorld";
    int str_len = strlen(str);

    // Ensure the rank is within the string's length
    if (rank < str_len) {
        // Toggle the character at the index corresponding to the rank
        if (isupper(str[rank])) {
            str[rank] = tolower(str[rank]);
        } else if (islower(str[rank])) {
            str[rank] = toupper(str[rank]);
        }

        // Print the updated character and its index
        printf("Process %d: Toggled character at index %d to '%c'\n", rank, rank, str[rank]);
    }

    // Finalize MPI
    MPI_Finalize();

    // Process 0 can optionally print the final result
    if (rank == 0) {
        printf("Final toggled string: %s\n", str);
    }

    return 0;
}
