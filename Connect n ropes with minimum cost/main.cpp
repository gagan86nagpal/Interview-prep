#include <iostream>

using namespace std;

// DP Solution
// O(n^2)
int ropes[1000];
int cumRopes[1000];
// 1 based indexing
int ropeLenght(int l,int r)
{
    return cumRopes[r]-cumRopes[l-1];
}
int dp[1000][1000];
void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}
int minCost(int l,int r)
{
    if(l==r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    int i;
    int ans  = 1000000000;
    for(i=l;i<r;i++)
    {
        ans = min(minCost(l,i) + +minCost(i+1,r) + ropeLenght(l,i) + ropeLenght(i+1,r) , ans );
    }
    return dp[l][r]=ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i;
        int n;
        cin>>n;
        init(n);
        for(i=1;i<=n;i++)
            cin>>ropes[i];
        for(i=1;i<=n;i++)
            cumRopes[i]+=cumRopes[i-1]+ropes[i];

        int ans = minCost(1,n);
        cout<<ans<<"\n";
    }
    return 0;
}
