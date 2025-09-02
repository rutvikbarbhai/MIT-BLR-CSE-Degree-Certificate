#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[]) {
    int rank, size, number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int arr[size];
    if (rank == 0) {
        printf("Enter %d elements of the array: ", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 1; i < size; i++) {
            MPI_Bsend(&arr[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD); 
        }
    } else {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        if (rank % 2 == 0) {
            printf("Process %d received %d, square: %d\n", rank, number, number * number);
        } else {
            printf("Process %d received %d, cube: %d\n", rank, number, number * number * number);
        }
    }
    MPI_Finalize();
    return 0;
}
