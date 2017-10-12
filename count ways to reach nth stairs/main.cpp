#include <iostream>

using namespace std;
int dp[1000];
int main()
{
    dp[1]=1;
    int n,m,i,j;
    cin>>n>>m;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=m && (i-j)>=1;j++)
        {
            dp[i]+=dp[i-j];
        }
    }
    cout<<dp[n];
    return 0;
}
