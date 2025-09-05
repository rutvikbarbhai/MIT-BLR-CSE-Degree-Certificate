#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    ptr->data = value;
    ptr->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Inserted: %d\n", value);
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow (empty queue)\n");
        return -1;
    }

    struct node *temp = front;
    int temp_data = front->data;

    front = front->next;
    if (front == NULL) {
        // if queue becomes empty, reset rear too
        rear = NULL;
    }

    free(temp);
    return temp_data;
}

// Display queue elements
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value;

    printf("\nImplementation of Queue using Linked List\n");

    while (choice != 4) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Wrong Choice! Try again.\n");
        }
    }

    return 0;
}
