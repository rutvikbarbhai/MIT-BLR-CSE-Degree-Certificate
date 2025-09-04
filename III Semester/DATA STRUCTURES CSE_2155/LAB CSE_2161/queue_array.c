#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//# define MAX 5
int MAX=5;
int cqueue_arr[];
int *stack;
int front = -1;
int rear = -1;
void insert(int item)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("Queue Overflow \n");
printf("Want to increase the size");
queuefull();
display();
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = item ;
}
void deletion()
{
if(front == -1)
{
printf("Queue Underflow\n");
return ;
}
printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}
void queuefull()
{
stack=realloc(stack,MAX*2*sizeof(int));// doubling the memory
if(stack==NULL)// IF MEMORY IS IN SUFFICIENT
{
printf("memory is insuffient\n");
exit(0);
}
MAX = MAX*2; // doubling the stack size
}
void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is empty\n");
return;
}
printf("Queue elements\n");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d\n",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos <= MAX-1)
{
printf("%d\n ",cqueue_arr[front_pos]);
front_pos++;
}
front_pos = 0;
//while(front_pos <= rear_pos)
//{
//printf("%d \n",cqueue_arr[front_pos]);
//front_pos++;
//}
}
printf("\n");
}
int main()
{
int choice,item;
do
{
printf("1.Insertn\n");
printf("2.Deleten\n");
printf("3.Displayn\n");
printf("4.Quitn\n");
printf("Enter your choice : \n");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
insert(item);
break;
case 2 :
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
}while(choice!=4);
return 0;
}