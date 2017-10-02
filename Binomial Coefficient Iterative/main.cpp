#include <iostream>

using namespace std;
int dp[100][100];

int binomial_coefficient(int n,int k)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(j>i)
                dp[i][j]=0;
            else if(j==i)
                dp[i][j]=1;
           else if(j==0)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    return dp[n][k];
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       cout<<binomial_coefficient(n,k)<<"\n";
   }
    return 0;
}
