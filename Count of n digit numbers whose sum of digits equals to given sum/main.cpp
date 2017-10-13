#include <iostream>

using namespace std;

int dp[1000][10000];
int countNumbers(int n , int sum)
{
    if(sum < 0 || n < 0)
        return 0;
    if(sum==0 && n==0)
        return 1;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    int i ,ans=0;
    for(i=0;i<=9;i++)
        ans+=countNumbers(n-1,sum-i);
    return dp[n][sum]=ans;
}

int solve(int n,int sum)
{
    int ans=0;
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=sum;j++)
            dp[i][j]=-1;
    for(i=1;i<=9;i++)
        ans+=countNumbers(n-1,sum-i);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum,ans;
        cin>>n>>sum;
        ans=solve(n,sum);
        cout<<ans<<"\n";
    }
    return 0;
}
