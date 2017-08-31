#include <iostream>
#include <math.h>
using namespace std;

// returns -1 if not found , else returns index
int jumpSearch(int a[],int n,int ele)
{
    int i;
    int sqn=sqrt(n);
    for(i=0;i<n;i+=sqn)
    {
        if(a[i]>=ele)
            break;
    }
    if(i>=n)
        return -1;
    i=max(0,i-sqn);
    while(i<n)
    {
        if(a[i]==ele)
            return i;
        if(a[i]>ele)
            return -1;
        i++;
    }
}
int main()
{
    int a[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 163,233, 377, 610};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<jumpSearch(a,n,611)<<"\n";

    return 0;
}
