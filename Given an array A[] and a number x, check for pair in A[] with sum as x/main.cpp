#include <iostream>

using namespace std;
 /*
Write a C program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x.
 */

 // Here we are using an array as hash table
 // if element range is bigger than array then we can use :
 // 1. Map < int,int> by c++
 // 2. Hashing techniques like separate chaining etc
 // If we have negative elements , then we can make a hash function and proceed accordingly

/*
Create a hash map for given array
for each element check whether x-element is present or not
if present , print , break
else look for another
*/

int hashTable[1000];
int main()
{
   int arr[]={1, 3, 45, 5, 6,6, 8};
   int x=14;
   int n=sizeof(arr)/sizeof(arr[0]);
   int i;
   int a,b;
   for(i=0;i<n;i++)
        hashTable[arr[i]]++;
    bool flag=false;
   for(i=0;i<n;i++)
   {
       if(x-arr[i]==arr[i])
       {
           if(hashTable[arr[i]]>=2) // two or more same elements are present
           {
               a=b=arr[i];
               flag=true;
               break;
           }
       }
       else if(hashTable[x-arr[i]]>=1) // x and arr[i]-x are present
       {
           a=arr[i];
           b=x-arr[i];
           flag=true;
           break;
       }
   }
   if(flag)
   {
       cout<<a<<" + "<<b<<" = "<<x<<"\n";
   }
   else
    cout<<"Sum is not present\n";
    return 0;
}
