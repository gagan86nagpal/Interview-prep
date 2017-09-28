#include <iostream>

using namespace std;
int dp[1000];
int a[1000];
int lis(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        dp[i]=1;
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j] && dp[j]+1 > dp[i])
                dp[i]=dp[j]+1;
        }
    }
    return dp[n-1];
}
int main()
{ int n;
   cin>>n;
   a[0]=-1;
   for(int i=1;i<=n;i++)
    cin>>a[i];
    int ans = lis(n);
    cout<<"LIS Length:"<<ans<<"\n";
    return 0;
}
