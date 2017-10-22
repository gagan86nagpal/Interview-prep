#include <iostream>

using namespace std;
int a[1002];
int dp[1002];
int maxSum(int in,int n)
{
    if(in >=n)
        return 0;
    if(dp[in]!=-1)
        return dp[in];
    return  dp[in]=max( a[in]+ maxSum(in+2,n) , maxSum(in+1,n));
}
void init(int n)
{
    for(int i=0;i<n;i++)
        dp[i]=-1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        init(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans = maxSum(0,n);
        cout<<ans<<"\n";
    }
    return 0;
}
