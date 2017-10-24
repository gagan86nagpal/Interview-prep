#include <iostream>
#include <cmath>
using namespace std;
int a[100];
int b[100];
int main()
{
    int n,m;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)
        cin>>b[i];
    int x;
    cin>>x;
    int l = 0;
    int r = m-1;
    int diff=abs(a[0]+b[m-1] -x);
    int p1=0;
    int p2 =m-1;
    while(l<=n-1 || r>=0)
    {
        int d =abs(a[l] + b[r] -x);
        if(d < diff)
        {
            diff= d;
            p1 =l;
            p2 =r;
        }
        if(r>=0 && a[l]+b[r] >x)
            r--;
        else if(l<=n-1)
            l++;
        else
            break;
    }
    cout<<a[p1]<<" "<<b[p2]<<" : "<<diff<<"\n";
    return 0;
}
/*
4
1 4 5 7
4
10 20 30 40
32


4
1 4 5 7
4
10 20 30 40
50
*/
