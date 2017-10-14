#include <iostream>

using namespace std;

int dp[10002];

void build(int n)  // preprocessing
{
    dp[1]=1;
    dp[0]=0;
    int i,j;
    for(i=2;i<=n;i++)
    {
        dp[i]=i; // it can take maximum i step by 1+1+1+1+..1
        for(j=1;j*j<=i;j++)
        {
            dp[i]=min(1+dp[i-j*j],dp[i]);
        }
    }

}

int main()
{
    int t,n;
    build(10000); // build for n=10000
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
