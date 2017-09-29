#include <iostream>

using namespace std;
int dp[1001][1001];
int m[1001][1001];
const int INT_MAX=(1<<30);
// check if given indices in the matrix or not
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

// return minCOst from (i,j) to reach 0,0
int minCost(int i,int j,int r,int c)
{
    // if out of limit , return maximum value as this path is invalid
    if(inLimits(i,j,r,c)==false)
        return INT_MAX;
    // reached destination
    if(i==0&&j==0)
        return m[i][j];
    // already computed
    if(dp[i][j]!=-1)
        return dp[i][j];
    // Take minimum of left, above and left-above diagonal
    dp[i][j]=min(minCost(i-1,j,r,c),  min (minCost(i,j-1,r,c) , minCost(i-1,j-1,r,c)) ) + m[i][j];
    // ave and return the computed value
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
