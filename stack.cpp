// staken.cpp
// overloading functions in base and derived classes
#include<iostream>
using namespace std;
#include<conio.h>
#include<process.h> //for exit()

class Stack
{
protected: //NOTE: cant be private
int MAX; //size of stack array
int st[10]; //stack: array of integers
int top;
int count,size;
//index to top of stack
public:
Stack() //constructor
{
top = -1;
count=0;
//size=10;
}
void push(int var) //put number on stack

{
if(top >= size-1) //error if stack full
{
cout << "\nError: stack is full";
exit(1);
}
else
top++;
st[top] =var;
//st[++top] = var;
}
int pop() //take number off stack
{
if(top < 0) //error if stack empty if (top==-1)
{
cout << "\nError: stack is empty \n";
exit(1);
}
return st[top--];
}
int stacktop()
{
if(top < 0) //error if stack empty
{
cout << "\nError: stack is empty \n";
exit(1);
}
return st[top];
}};

int main()
{
Stack s1;

int num,n,i;
cout<<"Enter the number of elements\n";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter the number\n";
cin>>num;
s1.push(num); //push some values onto stack
}
cout<<"The element at top:"<<s1.stacktop()<<endl;
cout<<"The popped elements are:";
for(i=0;i<n;i++)
{
cout<<endl<<s1.pop();
getch();
}
cout << endl << s1.pop(); //Stack Underflow
cout << endl;
return 0;
}