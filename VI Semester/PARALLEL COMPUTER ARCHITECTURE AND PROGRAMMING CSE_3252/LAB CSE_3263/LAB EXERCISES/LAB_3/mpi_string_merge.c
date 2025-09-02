#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int rank, size, len;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        char str1[100], str2[100];
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);

        len = strlen(str1);
        for (int i = 1; i < size; i++) {
            MPI_Send(str1, len + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            MPI_Send(str2, len + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }

        char result[len + 1];
        for (int i = 1; i < size; i++) {
            char partial_result[len + 1];
            MPI_Recv(partial_result, len + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            for (int j = 0; j < len / (size - 1); j++) {
                result[(i - 1) * (len / (size - 1)) + j] = partial_result[j];
            }
        }

        result[len] = '\0';
        printf("Resultant String: %s\n", result);
    } else {
        char str1[100], str2[100];
        MPI_Recv(str1, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(str2, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int start = (strlen(str1) / (size - 1)) * (rank - 1);
        int end = (rank == size - 1) ? strlen(str1) : start + strlen(str1) / (size - 1);

        char partial_result[end - start + 1];
        for (int i = start; i < end; i++) {
            partial_result[i - start] = (i % 2 == 0) ? str1[i] : str2[i];
        }
        partial_result[end - start] = '\0';

        MPI_Send(partial_result, end - start + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
