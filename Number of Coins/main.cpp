#include <iostream>

using namespace std;


int c[51];
int dp[10002];
int minCoins(int v,int n)
{
    if(v==0)
        return 0;
    int i;
    if(dp[v]!=-1)
        return dp[v];
    int mini=1<<30;
    for(i=0;i<n;i++)
        if(v>=c[i])
            mini=min(mini,minCoins(v-c[i],n));

    return dp[i]=1+mini;
}

void init(int v)
{
    int i;
    for(i=0;i<=v;i++)
        dp[i]=-1;
}
int main()
{
    int t;
    int n,v,i;
    cin>>t;
    while(t--)
    {
        cin>>v>>n;
        init(v);
        for(i=0;i<n;i++)
            cin>>c[i];
        int ans=minCoins(v,n);
        cout<<ans<<"\n";
    }
    return 0;
}


/*
1
15 3
3 2 4 1
*/
