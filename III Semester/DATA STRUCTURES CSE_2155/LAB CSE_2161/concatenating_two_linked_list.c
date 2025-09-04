#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
} *temp = NULL, *first = NULL, *second = NULL;
struct Node* Create(int A[], int n)
{
int i;
struct Node *t, *last;
temp = (struct Node *) malloc(sizeof(struct Node));
temp->data = A[0];
temp->next = NULL;
last = temp;
for (i = 1; i < n; i++)
{
t = (struct Node *) malloc(sizeof(struct Node));
t->data = A[i];
t->next = NULL;
last->next = t;
last = t;
}
return temp;
}
void Display(struct Node *p)
{
while (p != NULL)
{
printf ("%d ", p->data);
p = p->next;
}
}
void Concat(struct Node *first, struct Node *second)
{
struct Node *p = first;
while (p->next != NULL)
{
p = p->next;
}
p->next = second;
second = NULL;
}
int main()
{
int A[] = { 9, 7, 4, 3 };
int B[] = { 2, 5, 6, 8 };
first = Create(A, 4);
second = Create(B, 4);
printf ("1st Linked List: ");
Display (first);
printf ("\n2nd Linked List: ");
Display (second);
Concat (first, second);
printf ("\n\nConcantenated Linked List: \n");
Display (first);
return 0;
}