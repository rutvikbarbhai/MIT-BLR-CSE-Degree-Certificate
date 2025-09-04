#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *stack;
int capacity=1;
int top=-1, item;
void push()
{
if(top == capacity-1)
{
stackfull();//which double the memory when stack is full
}
printf("enter an item to insert\n");
scanf("%d", &item);
stack[++top] = item;
}
void pop()
{
if(top == -1)
{
printf("underflow\n");
return;
}
item = stack[top--];
printf("item deleted is %d \n", item);
}
void stackfull()
{
stack=realloc(stack,capacity*2*sizeof(int));// doubling the memory
if(stack==NULL)// IF MEMORY IS IN SUFFICIENT
{
printf("memory is insuffient\n");
exit(0);
}
capacity=capacity*2; // doubling the stack size
}
void display()
{
int i;
if(top==-1)
{
printf("stack is empty \n");
return;
}
for(i=top;i>=0;i--)
printf("%d",*(stack+i));
}
void main()
{
int choice=1;
stack=malloc(capacity*sizeof(int));//allocating memory dynamically
while(choice)
{
printf("enter your choice\n 1.push\n 2.pop\n 3.display \n 4 exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:printf("invalid operation\n");
exit(0);
}
}
free(stack);// deallocating memory
stack=NULL; //avoiding dangling pointer
}