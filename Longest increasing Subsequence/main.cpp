#include <iostream>

using namespace std;
int a[100000];
int cnt=0;
int lis(int in,int n,int mi=0)
{
    cnt++;
    if(in==n+1)
    {
        return 0;
    }
    if(a[in] > a[mi])
    {
        int x=1+ lis(in+1,n,in) ;
        int y=lis(in+1,n,mi)   ;
        return max(x,y);
    }

    int x= lis(in+1,n,mi);

    return x;
}
int main()
{
    int n;
    cin>>n;
    int i;
    a[0]=-1;
    for(i=1;i<=n;i++)
        cin>>a[i];
    int ans=lis(1,n);
    cout<<"LIS length:" <<ans<<"\n";
    return 0;
}
