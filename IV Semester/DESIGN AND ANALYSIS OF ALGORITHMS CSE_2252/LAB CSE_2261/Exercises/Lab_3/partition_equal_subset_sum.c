
#include <stdio.h>

int isSubsetSum(int arr[], int n, int sum) {
    // Base cases
    if (sum == 0) {
        return 1;
    }
    if (n == 0 && sum != 0) {
        return 0;
    }

    // If the last element is greater than the sum,
    // then it can't be included in the subset
    if (arr[n - 1] > sum) {
        return isSubsetSum(arr, n - 1, sum);
    }

    // Check if the sum can be obtained by either including or excluding the last element
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Function to check whether the given set can be partitioned into two subsets with equal sum
int canPartition(int arr[], int n) {
    int totalSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // If the total sum is odd, the array can't be partitioned into two subsets with equal sum
    if (totalSum % 2 != 0) {
        return 0;
    }

    // Check whether there exists a subset with sum equal to half of the total sum
    return isSubsetSum(arr, n, totalSum / 2);
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(arr, n)) {
        printf("The array can be partitioned into two subsets with equal sum.\n");
    } else {
        printf("The array cannot be partitioned into two subsets with equal sum.\n");
    }

    return 0;
}

Q5

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



