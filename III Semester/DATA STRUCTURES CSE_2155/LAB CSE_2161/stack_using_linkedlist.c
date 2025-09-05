#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation on a stack
void push(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }

    newNode->data = value;  
    newNode->next = top;   // link new node to previous top
    top = newNode;         // update top pointer

    printf("Node with value %d is inserted.\n", value);
}

// Pop operation on a stack
int pop() {
    if (top == NULL) {
        printf("\nStack Underflow! Cannot pop.\n");
        return -1;  // sentinel value
    }

    struct Node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);

    return poppedValue;
}

// Display elements of the stack
void display() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nThe stack is:\n");
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    printf("\nImplementation of Stack using Linked List\n");

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped element is: %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
