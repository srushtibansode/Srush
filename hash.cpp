//It direct hashing technique with linear probe
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<conio.h>
#define SIZE 7
using namespace std;
class hashlist
{
int no_elts;
int arr[SIZE],addr[SIZE];
public:
void createht();
void search();
void displayht();
int collision(int);
};
void hashlist::createht()
{
int i,tempaddr,j,flag;
cout<<"Input number of keys (integers) to be stored in the Hash table\n";
cin>>no_elts;
// input keys
cout<<"\n Input keys to be stored \n";
for(i=0; i<no_elts; i++)
{

addr[i]=0;
cin>>arr[i];
tempaddr = arr[i];
tempaddr=collision(tempaddr);
addr[i] = tempaddr;
}
}
void hashlist::displayht()
{
int i;
cout<<"Hashed list is:\n";
cout<<"Elements"<<"\t"<<"Address"<<"\n";
for (i=0; i<no_elts; i++)
{
cout<<arr[i]<<"\t"<<addr[i]<<"\n";
}
}
void hashlist::search()
{
int i,key,addr1;
cout<<"\nEnter key to be searched:\n";
cin>>key;
addr1 = key;
i=0;
while (i<SIZE)
{
l1: if(addr1 == addr[i])
if(key==arr[i])
{
cout<<"\nMatch is found";
break;
}
else

{
addr1 = addr1+1;
i++;
goto l1;
}
i++;
}
if(i==SIZE)
cout<<"\nMatch is not found\n";
}
int hashlist::collision(int tadd)
{
int i;
for(i=0;i<SIZE;i++)
{
if (tadd==addr[i])
{
cout<<"Collision ";
tadd=tadd+1;
//break;
}
}
return tadd;
}
int main(void)
{
int opt ;
//clrscr();
hashlist hl;
do /* main menu*/
{
cout<<"\n1.Create Hash table \n";
cout<<"\n2.Display Chained Hash table\n";
cout<<"\n3.Search Hash table \n";
cout<<"\n4.Quit\n";
cout<<"\nEnter option: ";
cin>>opt;
switch(opt)
 {
case 1:
hl.createht();
break;
case 2:
hl.displayht();
break;
case 3:
hl.search();
break;
case 4:
exit(1);
break;
}
}
while(1);
return 0;
}
