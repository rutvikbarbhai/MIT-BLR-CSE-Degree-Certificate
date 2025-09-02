#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[]) {
    int rank, size, M, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Enter the number of elements per process (M): ");
        scanf("%d", &M);
        N = M * (size - 1);
        int array[N];
        printf("Enter %d elements: ", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
        for (int i = 1; i < size; i++) {
            MPI_Send(&array[(i - 1) * M], M, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        double total_average = 0;
        for (int i = 1; i < size; i++) {
            double partial_avg;
            MPI_Recv(&partial_avg, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_average += partial_avg;
        }
        total_average /= (size - 1);
        printf("Overall average: %.2f\n", total_average);
    } else {
        int elements[M];
        MPI_Recv(elements, M, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        double sum = 0;
        for (int i = 0; i < M; i++) {
            sum += elements[i];
        }
        double avg = sum / M;
        MPI_Send(&avg, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
