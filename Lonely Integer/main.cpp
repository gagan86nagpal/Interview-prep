#include <iostream>

using namespace std;
int lonelyInteger(int a[],int n)
{
    int ret=0;
    int i;
    for(i=0;i<n;i++)
        ret^=a[i];
    return ret;
}
int main()
{
    int a[]={1,4,4,1,5,2,5,2,7,7,12,42,42};
    int res=0;
    int n = 13;
    res = lonelyInteger(a,n);
    cout<<res<<"\n";
    return 0;
}
