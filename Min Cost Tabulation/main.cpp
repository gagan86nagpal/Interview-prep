#include <iostream>

using namespace std;
int m[1001][1001];
int dp[1001][1001];


// Idea is to imagine the problem in graph , find the top sort
// And solve in the fashion

// Top sort is the row-col traversal
int minCost(int r,int c)
{
    int i=0,j=0;
    for(i=0;i<=r;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=1<<30;
            else if(i==1 && j==1)
                dp[i][j]=m[i][j];
            else
                dp[i][j] = m[i][j]+min( dp[i-1][j-1] , min ( dp[i][j-1] ,dp[i-1][j]  ));
        }
    }
    return dp[r][c];
}
int main()
{
    int r,c,i,j;
    cin>>r>>c;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            cin>>m[i][j];
    int ans = minCost(r,c);
    cout<<ans<<"\n";
    return 0;
}
