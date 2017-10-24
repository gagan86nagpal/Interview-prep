#include <iostream>
#include <cmath>
using namespace std;
int a[1000];
int main()
{
    int n,x;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    int l=0,r=n-1;
    int diff= abs(a[l]+a[r]-x);
    int p1 =l;
    int p2 = r;
    while(l<r)
    {
        int d = abs(a[l]+a[r]-x);
        if(diff > d)
        {
            diff = d;
            p1 = l;
            p2 =r;
        }
        if(d==0)
            break;
        if(a[l]+a[r] > x)
            r--;
        else
            l++;
    }
    cout<<a[p1]<<" "<<a[p2]<<"\n";
    return 0;
}
