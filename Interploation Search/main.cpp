#include <iostream>
#include <math.h>
using namespace std;

// returns -1 if not found , else returns index
int jumpSearch(int a[],int n,int ele)
{
    int i;
    int lo=0,hi=n-1;
    int pos;
    while(lo<=hi&&ele>=a[lo]&&ele<=a[hi])
    {
        pos =lo+( (ele-a[lo])*(hi-lo) ) /(a[hi]-a[lo]);
        if(a[pos]==ele)
            return pos;
        if(a[pos]<ele)
            lo=pos+1;
        else
            lo=hi-1;
    }
    return -1;
}
int main()
{
    int a[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 163,233, 377, 610};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<jumpSearch(a,n,89)<<"\n";

    return 0;
}
