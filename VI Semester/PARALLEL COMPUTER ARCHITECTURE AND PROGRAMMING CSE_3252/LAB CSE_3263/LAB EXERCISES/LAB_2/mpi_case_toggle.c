#include <stdio.h>
#include <mpi.h>
#include <ctype.h>
int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char word[100], modified_word[100];
    if (rank == 0) {
        printf("Enter a word: ");
        scanf("%s", word);
        MPI_Ssend(word, 100, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(modified_word, 100, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Modified word: %s\n", modified_word);
    }
    else if (rank == 1) {
        MPI_Recv(word, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; word[i] != '\0'; i++) {
            if (islower(word[i])) {
                modified_word[i] = toupper(word[i]);
            } else {
                modified_word[i] = tolower(word[i]);
            }
        }
        MPI_Ssend(modified_word, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
