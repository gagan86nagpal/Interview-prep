#include <iostream>
#include <cmath>
using namespace std;
int pair_sum[1000];
int a[1000];

// General Idea is to first find the first element and then sequentially other elements can be found easily
// Now , to find first element , we can sum all the elements of pair sum array and divide by (n-1)
// here n is number of elements in original array
// THis is actually the sum of elements in original array ,
// after that we can calculate sum of first (n-1) elements in given array , and subtract sum of original
// to this array , diving this by (n-2) given first element
int main()
{
    int x ;
    int i;
    cin>>x;
    for(i=0;i<x;i++)
        cin>>pair_sum[i];
    int sum=0;
    for(i=0;i<x;i++)
        sum+=pair_sum[i];
    int n = (1+ sqrt(1+8*x) )/2;
    sum = sum/(n-1);   // it now represents the sum of original array to be found
    for(i=0;i<n-1;i++)
        a[0]+=pair_sum[i];
    a[0]-=sum;
    a[0]/=(n-2);  // a[0] is correct by here
    for(i=0;i<n-1;i++)
        a[i+1]=pair_sum[i]-a[0];
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
