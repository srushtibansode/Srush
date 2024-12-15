#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
/* Queue definitions for Array implementation*/
class Queue
{
int qAry[10];
int front;
int count;
int rear;
public:
Queue()
{
front=-1;
rear=-1;
count=0;
}
void enqueue(int element)
{
if (count == 10)
{
cout<<"Can't enqueue an element in queue: Queue Overflow.\n";
//exit(1); /* Exit, returning error code. */
}
// Put information in array; update queue.
else
{
rear++;
qAry[rear]=element;
if(count==0)
{
//inserting into null queue
front = 0;
count=1;
}
else
count++;
}
cout<<"Queue count is:"<<count<<endl;
}
void dequeue()
{
int i;
if (!count)
{
cout<<"Can't deque element from queue: queue underflow.\n";
// exit(1); // Exit, returning error code.
}
else
{
i = qAry[front];
qAry[front]=0;
front++;
if(count==1)//deleted single item from queue
rear=front=-1;
count--;
cout<<"\nThe element dequeued is:"<<i<<endl;
cout<<"\nQueue count in "<<count<<endl;
}}};
int main()
{
int item, n,cnt,flag;
Queue q1;
//clrscr();
while (1)
{
cout<<" 1. Enqueue\n";
cout<<" 2. Dequeue\n";
cout<<" 3. Quit\n";
cout<<"\n Enter option";
cin>>n;
switch(n)
{
case 1:
cout<<"Input item to be inserted\n";
cin>>item;
q1.enqueue(item);
break;
case 2:
q1.dequeue();
break;
case 3:
exit(1);
break;
default: cout<<"Illegal option\n";
break;
}
}
return 0;
}