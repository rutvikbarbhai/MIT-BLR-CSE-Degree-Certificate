#include <stdio.h>

// Function to compute the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Input the position of the Fibonacci number
    printf("Enter the position (n) of the Fibonacci number: ");
    scanf("%d", &n);

    // Compute and display the nth Fibonacci number
    int result = fibonacci(n);
    printf("Fibonacci number at position %d is: %d\n", n, result);

    return 0;
}

Time Complexity- O(2^n)

