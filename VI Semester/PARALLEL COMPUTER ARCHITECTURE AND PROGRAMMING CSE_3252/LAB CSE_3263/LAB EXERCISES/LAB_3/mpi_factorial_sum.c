#include <stdio.h>
#include <mpi.h>
long factorial(int n) {
    long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int main(int argc, char *argv[]) {
    int rank, size, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the number of values (N): ");
        scanf("%d", &N);
        int values[N];
        printf("Enter %d numbers: ", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &values[i]);
        }
        for (int i = 1; i < size; i++) {
            MPI_Send(&values[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        long total_sum = 0;
        for (int i = 1; i < size; i++) {
            long partial_result;
            MPI_Recv(&partial_result, 1, MPI_LONG, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_sum += partial_result;
        }
        printf("Total sum of factorials: %ld\n", total_sum);
    } else {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        long fact = factorial(num);
        MPI_Send(&fact, 1, MPI_LONG, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
