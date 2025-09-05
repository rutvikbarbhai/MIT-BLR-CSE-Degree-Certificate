#include <stdio.h>
#include <stdlib.h>

int MAX = 5;
int *cqueue_arr;   // dynamic circular queue
int front = -1;
int rear = -1;

// Function to double queue size
void queuefull() {
    cqueue_arr = realloc(cqueue_arr, MAX * 2 * sizeof(int));  // resize
    if (cqueue_arr == NULL) { // check for allocation failure
        printf("Memory is insufficient\n");
        exit(0);
    }
    MAX = MAX * 2;
    printf("Queue size doubled to %d\n", MAX);
}

void insert(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        printf("Resizing...\n");
        queuefull();
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    cqueue_arr[rear] = item;
}

void deletion() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Element deleted from queue is: %d\n", cqueue_arr[front]);

    if (front == rear) { // only one element
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%d ", cqueue_arr[i]);
        }
    } else {
        for (i = front; i < MAX; i++) {
            printf("%d ", cqueue_arr[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", cqueue_arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, item;

    // Initial allocation
    cqueue_arr = (int*) malloc(MAX * sizeof(int));
    if (cqueue_arr == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input the element for insertion in queue: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                deletion();
                break;

            case 3:
                display();
                break;

            case 4:
                break;

            default:
                printf("Wrong choice\n");
        }
    } while (choice != 4);

    free(cqueue_arr); // free allocated memory
    return 0;
}
