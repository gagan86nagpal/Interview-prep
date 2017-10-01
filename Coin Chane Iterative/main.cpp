#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector <int> v;
int dp[1000][10];
int coinChange(int n,int m)
{
    int i,j;
    for(i=0;i<=m;i++)
        dp[0][i]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i-v[j]<0 && j-1<0)
                continue;
            else if(i-v[j]<0)
                dp[i][j]=dp[i][j-1];
            else if(j-1<0)
                dp[i][j]=dp[i-v[j]][j];
            else
            dp[i][j]=dp[i-v[j]][j]+dp[i][j-1];
        }
    }
    return dp[n][m];
}
int main()
{
    int n,m,x;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    int ans=coinChange(n,m-1);
    cout<<ans<<"\n";
    return 0;
}

/*
3 4
1 2 3


*/
