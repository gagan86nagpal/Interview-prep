#include <iostream>

using namespace std;
int dp[100][100];
void init(int n,int k)
{
    int i, j;
    for(i=0;i<=n;i++)
        for(j=0;j<=k;j++)
            dp[i][j]=-1;
}
int binomial_coefficient(int n,int k)
{
    if(k>n)
        return -1;
    if(n==k)
        return 1;
    if(k==0)
        return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    return dp[n][k]=binomial_coefficient(n-1,k)+binomial_coefficient(n-1,k-1);
}
int main()
{
   int t;
   cin>>t;
   init(99,99);
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       init(n,k);
       cout<<binomial_coefficient(n,k)<<"\n";
   }
    return 0;
}
