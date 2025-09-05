#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start;

// Function declarations
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

void main() {
    int choice = 0;

    while (choice != 9) {
        printf("\n\n********* Main Menu *********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1. Insert in beginning");
        printf("\n2. Insert at last");
        printf("\n3. Insert at any random location");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from last");
        printf("\n6. Delete node after specified location");
        printf("\n7. Search for an element");
        printf("\n8. Show");
        printf("\n9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter valid choice..");
        }
    }
}

void beginsert() {
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &item);

        ptr->data = item;
        ptr->next = start;
        start = ptr;

        printf("\nNode inserted");
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &item);

        ptr->data = item;
        ptr->next = NULL;

        if (start == NULL) {
            start = ptr;
            printf("\nNode inserted");
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            printf("\nNode inserted");
        }
    }
}

void randominsert() {
    int i, loc, item;
    struct node *ptr, *temp;

    ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter element value: ");
        scanf("%d", &item);

        ptr->data = item;

        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);

        temp = start;
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\nCan't insert\n");
                return;
            }
        }

        ptr->next = temp->next;
        temp->next = ptr;

        printf("\nNode inserted");
    }
}

void begin_delete() {
    struct node *ptr;

    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        ptr = start;
        start = ptr->next;
        free(ptr);

        printf("\nNode deleted from the beginning...\n");
    }
}

void last_delete() {
    struct node *ptr, *ptr1;

    if (start == NULL) {
        printf("\nList is empty");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;

        printf("\nOnly node of the list deleted...\n");
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);

        printf("\nDeleted Node from the last...\n");
    }
}

void random_delete() {
    struct node *ptr, *ptr1;
    int loc, i;

    printf("\nEnter the location of the node after which you want to perform deletion: ");
    scanf("%d", &loc);

    ptr = start;
    for (i = 0; i < loc; i++) {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL) {
            printf("\nCan't delete");
            return;
        }
    }

    ptr1->next = ptr->next;
    free(ptr);

    printf("\nDeleted node %d", loc + 1);
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 1;

    ptr = start;
    if (ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item which you want to search: ");
        scanf("%d", &item);

        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("Item found at location %d\n", i + 1);
                flag = 0;
            }
            i++;
            ptr = ptr->next;
        }

        if (flag == 1) {
            printf("Item not found\n");
        }
    }
}

void display() {
    struct node *ptr;

    ptr = start;
    if (ptr == NULL) {
        printf("Nothing to print");
    } else {
        printf("\nPrinting values...\n");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
