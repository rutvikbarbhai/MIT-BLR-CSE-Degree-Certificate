#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[]) {
    int rank, size, number;
    MPI_Init(&argc, &argv);                  
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   
    MPI_Comm_size(MPI_COMM_WORLD, &size);   
    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            number = i * 10;
            MPI_Send(&number, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            printf("Master sent %d to process %d\n", number, i);
        }
    } else {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Receive from master
        printf("Process %d received number %d from master\n", rank, number);
    }
    MPI_Finalize(); // Finalize MPI
    return 0;
}
