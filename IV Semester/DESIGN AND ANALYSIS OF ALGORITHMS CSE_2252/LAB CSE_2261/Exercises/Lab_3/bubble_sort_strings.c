
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void swapStrings(char str1[], char str2[]) {
    char temp[MAX_SIZE];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void bubbleSortStrings(char arr[][MAX_SIZE], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap the strings if they are in the wrong order
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}

void printStrings(char arr[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    char strings[][MAX_SIZE] = {"banana", "apple", "grape", "orange", "kiwi"};
    int n = sizeof(strings) / sizeof(strings[0]);

    printf("Original strings:\n");
    printStrings(strings, n);

    // Perform Bubble Sort on the array of strings
    bubbleSortStrings(strings, n);

    printf("\nSorted strings:\n");
    printStrings(strings, n);

    return 0;
}



