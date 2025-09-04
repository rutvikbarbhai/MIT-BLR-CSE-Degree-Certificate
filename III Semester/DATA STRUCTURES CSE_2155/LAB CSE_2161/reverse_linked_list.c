#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
} *first = NULL;
void Create(int A[], int n)
{
int i;
struct Node *t, *last;
first = (struct Node *) malloc (sizeof (struct Node));
first->data = A[0];
first->next = NULL;
last = first;
for (i = 1; i < n; i++)
{
t = (struct Node *) malloc (sizeof (struct Node));
t->data = A[i];
t->next = NULL;
last->next = t;// new node insertion
last = t;
}
}
int Count(struct Node * p) {
int l = 0;
while (p) {
l++;
p = p -> next;
}
return l;
}
void Display(struct Node *p)
{
while (p != NULL)
{
printf ("%d ", p->data);
p = p->next;
}
}
void ReverseElements(struct Node *p)
{
int *A, i = 0;
struct Node *q = p;
A = (int *) malloc(sizeof(int) * Count(p));
while (q != NULL)
{
A[i] = q->data; //{1,2,3,4,5}
q = q->next;
i++;
}
q = p;
i--;
while (q != NULL)
{
q->data = A[i];
q = q->next;
i--;
}
}
int main()
{
int A[] = { 3, 4, 9, 10, 13, 16, 19 };
Create(A, 5);
printf("Before Reverse: \n");
Display(first);
ReverseElements(first);
printf("\nAfter Reverse: \n");
Display(first);
return 0;
}