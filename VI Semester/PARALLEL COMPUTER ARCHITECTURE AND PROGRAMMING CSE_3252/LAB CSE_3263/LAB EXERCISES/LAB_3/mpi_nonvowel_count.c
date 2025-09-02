#include <stdio.h>
#include <mpi.h>
#include <ctype.h>
#include <string.h>

int count_non_vowels(const char *str, int start, int end) {
    int count = 0;
    for (int i = start; i < end; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int rank, size, len;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        len = strlen(str);

        for (int i = 1; i < size; i++) {
            MPI_Send(str, len + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }

        int total_non_vowels = 0;
        for (int i = 1; i < size; i++) {
            int partial_count;
            MPI_Recv(&partial_count, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_non_vowels += partial_count;
        }

        printf("Total non-vowels: %d\n", total_non_vowels);
    } else {
        char str[100];
        MPI_Recv(str, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int start = (strlen(str) / (size - 1)) * (rank - 1);
        int end = (rank == size - 1) ? strlen(str) : start + strlen(str) / (size - 1);

        int non_vowel_count = count_non_vowels(str, start, end);
        MPI_Send(&non_vowel_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
