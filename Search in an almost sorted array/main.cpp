#include <iostream>

using namespace std;
int a[100];

int bSearch(int l,int h,int x)
{
    if(l>h)
        return -1; // not found
    int m = (l+h)/2;
    if(a[m]==x)
        return m;
    if(m>l && a[m-1]==x)
        return m-1;
    if(m<h &&a[m+1]==x)
        return m+1;
    if(a[m]<x)
        return bSearch(m+1,h,x);
    else
        return bSearch(l,m-1,x);
}
int main()
{
    int n,x,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    int in = bSearch(0,n-1,x);
    cout<<in<<"\n";
    return 0;
}
