#include <iostream>
#include <string>
using namespace std;
int binarySearch(int myarray[], int beg, int end, int key)
{
int mid;
if(end >= beg) {
mid = (beg + end)/2;

if(myarray[mid] == key)
{
return mid+1;
}
else if(myarray[mid] < key) {
return binarySearch(myarray,mid+1,end,key);
}
else {
return binarySearch(myarray,beg,mid-1,key);
} }
return -1;
}
int main ()
{
int myarray[1121] = {5,8,10,13,21,23,25,43,54,75,80};
int key, location=-1;
cout<<"The input array is"<<endl;
for(int i=0;i<10;i++){
cout<<myarray[i]<<" ";
}
cout<<endl;
cout<<"Enter the key that is to be searched:";
cin>>key;
location = binarySearch(myarray, 0, 10, key);
if(location != -1)
{
cout<<"Key found at location "<<location;
}
else {
cout<<"Requested key not found";
}
}