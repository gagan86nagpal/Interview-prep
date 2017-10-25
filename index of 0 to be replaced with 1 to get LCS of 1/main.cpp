#include <iostream>

using namespace std;
int a[104];

int solve(int n)
{
    int f=-1,s=-1,t=-1;
    f=0;
    int cnt=2;
    int i=1;
    while(i<=n+1)
    {
        if(a[i]==0)
        {
            f=s;
            s=t;
            t=i;
            cnt--;
            if(cnt==0)
                break;
        }
        i++;
    }
    // cnt must be 0 if there is atleast 1 zero in arrray
    if(cnt!=0)
        return -1;
    int ma = t-f-1;
    int pos =s-1;
    while(i<=n+1)
    {
        if(a[i]==0)
        {
            f=s;
            s=t;
            t=i;
            if(t-f-1 > ma)
                pos=s-1;
        }
        i++;
    }
    return pos;
}
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    a[0]=0;
    a[n+1]=0;
    // to handle the base cases
    int in = solve(n);
    if(in!=-1)
        cout<<in<<"\n";
    else
        cout<<"No Index\n";
    return 0;
}
/*
13
1 1 0 0 1 0 1 1 1 0 1 1 1
*/
