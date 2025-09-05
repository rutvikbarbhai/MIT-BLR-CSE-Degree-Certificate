#include <stdio.h>

int stack[100], choice, n, top, x, i;

void push(void);
void pop(void);
void display(void);

int main() {
    top = -1;

    printf("\nEnter the size of STACK: ");
    scanf("%d", &n);

    printf("\nSTACK OPERATIONS USING ARRAY");
    printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");

    do {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nPlease enter a valid choice (1/2/3/4)");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top >= n - 1) {
        printf("\nSTACK Overflow");
    } else {
        printf("\nEnter a value to be pushed: ");
        scanf("%d", &x);
        stack[++top] = x;
        printf("Value %d pushed into STACK", x);
    }
}

void pop() {
    if (top <= -1) {
        printf("\nSTACK Underflow");
    } else {
        printf("\nThe popped element is %d", stack[top--]);
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in STACK are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\nThe STACK is empty");
    }
}
