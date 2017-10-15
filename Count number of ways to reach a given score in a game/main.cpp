#include <iostream>

using namespace std;
int a[3]={3,5,10};
int dp[10001][4];
void init(int p,int n)
{
    int i,j;
    for(i=0;i<=p;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}
int numberOfWays(int p,int n)
{
    if(n==-1)
        return 0;
    if(p==0)
        return 1;
    if(p<0)
        return 0;
    if(dp[p][n]!=-1)
        return dp[p][n];
    int take_n = numberOfWays(p-a[n] , n);
    int dont_take = numberOfWays(p,n-1);
    return dp[p][n]= take_n+dont_take;
}
int main()
{
    int n=3;
    int p;
    cin>>p;
    init(p,n);
    int ans = numberOfWays(p,n-1);
    cout<<ans<<"\n";
    return 0;
}
