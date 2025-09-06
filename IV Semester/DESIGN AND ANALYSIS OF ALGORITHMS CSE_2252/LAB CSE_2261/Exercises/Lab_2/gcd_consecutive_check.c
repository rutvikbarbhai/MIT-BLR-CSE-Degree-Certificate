#include <stdio.h>

// Function to find the GCD using consecutive integer checking method
int findGCD(int a, int b) {
    int gcd = 1;
    int smaller = (a < b) ? a : b;

    for (int i = 1; i <= smaller; ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Find and display the GCD
    int result = findGCD(num1, num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

Time Complexity- O(min(a,b))
