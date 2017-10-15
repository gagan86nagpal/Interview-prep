#include <iostream>

using namespace std;
int cost[100][100];
int dp[100];

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        dp[i]=-1;
}
int solve(int cur, int n)
{
    int i;
    if(cur==n)
        return 0;
    if(dp[cur]!=-1)
        return dp[cur];
    int mini=1000000;
    for(i=cur+1;i<=n;i++)
    {
        mini = min(mini,cost[cur][i] + solve(i,n));
    }
    return dp[cur]=mini;
}
int main()
{
    int n;
    int i,j;
    cin>>n;
    init(n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>cost[i][j];
    int minCost = solve(1,n);
    cout<<minCost<<"\n";
    return 0;
}
/*
4
0 15 80 90
-1 0 40 50
-1 -1 0 70
-1 -1 -1 0
*/
