#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *stack;
int capacity = 1;
int top = -1, item;

void push() {
    if (top == capacity - 1) {
        stackfull(); // doubles memory when stack is full
    }

    printf("Enter an item to insert: ");
    scanf("%d", &item);

    stack[++top] = item;
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    }

    item = stack[top--];
    printf("Item deleted is %d\n", item);
}

void stackfull() {
    stack = realloc(stack, capacity * 2 * sizeof(int)); // doubling the memory

    if (stack == NULL) { // if memory is insufficient
        printf("Memory is insufficient\n");
        exit(0);
    }

    capacity = capacity * 2; // doubling the stack size
}

void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", *(stack + i));
    }
    printf("\n");
}

void main() {
    int choice = 1;

    stack = malloc(capacity * sizeof(int)); // allocating memory dynamically

    while (choice) {
        printf("\nEnter your choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
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
                printf("Exiting...\n");
                free(stack);  // deallocating memory
                stack = NULL; // avoiding dangling pointer
                exit(0);
            default:
                printf("Invalid operation\n");
        }
    }
}
