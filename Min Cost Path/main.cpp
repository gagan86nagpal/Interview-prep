#include <iostream>

using namespace std;
int dp[1001][1001];
int m[1001][1001];
const int INT_MAX=(1<<30);
bool inLimits(int i,int j,int r,int c)
{
    return (i>=0&&i<r&&j>=0&&j<c);
}
void init(int r,int c)
{
    int i,j;
    for(i=0;i<=r;i++)
        for(j=0;j<=c;j++)
            dp[i][j]=-1;
}
int minCost(int i,int j,int r,int c)
{
    if(inLimits(i,j,r,c)==false)
        return INT_MAX;

    if(i==0&&j==0)
        return m[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j]=min(minCost(i-1,j,r,c),  min (minCost(i,j-1,r,c) , minCost(i-1,j-1,r,c)) ) + m[i][j];
    return dp[i][j];
}
int main()
{
    int r,c,i,j;
    cin>>r>>c;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>m[i][j];
    init(r,c);
    int ans = minCost(r-1,c-1,r,c);
    cout<<ans<<"\n";
    return 0;
}
