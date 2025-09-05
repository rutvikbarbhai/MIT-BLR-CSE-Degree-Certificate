#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Count(struct Node *p) {
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }
    return l;
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ReverseElements(struct Node *p) {
    int *A, i = 0;
    struct Node *q = p;

    int n = Count(p);
    A = (int*) malloc(sizeof(int) * n);

    // Copy elements into array
    while (q != NULL) {
        A[i++] = q->data;
        q = q->next;
    }

    // Copy back in reverse
    q = p;
    i--;
    while (q != NULL) {
        q->data = A[i--];
        q = q->next;
    }

    free(A); // free allocated memory
}

int main() {
    int A[] = {3, 4, 9, 10, 13, 16, 19};
    int n = sizeof(A) / sizeof(A[0]); // safer than hardcoding
    Create(A, n);

    printf("Before Reverse:\n");
    Display(first);

    ReverseElements(first);

    printf("After Reverse:\n");
    Display(first);

    return 0;
}
