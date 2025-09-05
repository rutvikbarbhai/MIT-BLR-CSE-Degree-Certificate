// C program for all operations in the Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

// Function to traverse the linked list
void traverse() {
    // List is empty
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    // Else print the data
    struct node* temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

// Function to insert at the front of the linked list
void insertAtFront() {
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    temp->info = data;
    temp->prev = NULL;
    temp->next = start;

    if (start != NULL)
        start->prev = temp;

    start = temp;
}

// Function to insert at the end of the linked list
void insertAtEnd() {
    int data;
    struct node *temp, *trav;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    temp->info = data;

    // If list is empty
    if (start == NULL) {
        start = temp;
    } else {
        trav = start;
        while (trav->next != NULL)
            trav = trav->next;

        temp->prev = trav;
        trav->next = temp;
    }
}

// Function to insert at any specified position in the linked list
void insertAtPosition() {
    int data, pos, i = 1;
    struct node *temp, *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    // If list is empty
    if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    // If position == 1
    else if (pos == 1) {
        insertAtFront();
    }
    // General case
    else {
        printf("\nEnter number to be inserted: ");
        scanf("%d", &data);

        newnode->info = data;
        temp = start;

        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newnode;

        newnode->prev = temp;
        temp->next = newnode;
    }
}

// Function to delete from the front of the linked list
void deleteFirst() {
    struct node* temp;

    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;

        free(temp);
    }
}

// Function to delete from the end of the linked list
void deleteEnd() {
    struct node* temp;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    if (start->next == NULL) {
        start = NULL;
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
}

// Function to delete from any specified position
void deletePosition() {
    int pos, i = 1;
    struct node *temp, *position;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    temp = start;

    // If deleting first node
    if (pos == 1) {
        deleteFirst();
        return;
    }

    // Traverse to node before the position
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    position = temp->next;
    if (position == NULL) {
        printf("\nPosition not found\n");
        return;
    }

    temp->next = position->next;
    if (position->next != NULL)
        position->next->prev = temp;

    free(position);
}

// Driver Code
int main() {
    int choice;

    while (1) {
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at starting\n");
        printf("\t3  For insertion at end\n");
        printf("\t4  For insertion at any position\n");
        printf("\t5  For deletion of first element\n");
        printf("\t6  For deletion of last element\n");
        printf("\t7  For deletion at any position\n");
        printf("\t8  To exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deletePosition();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Incorrect Choice. Try Again\n");
                continue;
        }
    }

    return 0;
}
