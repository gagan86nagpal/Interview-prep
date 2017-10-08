#include <iostream>

using namespace std;
int mat[52][52];
int r[52][52];
int c[52][52];
int dp[52][52];
int solve(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=r[i][j]=c[i][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(mat[i][j]==0)
                r[i][j]=c[i][j]=0;
            else
            {
                r[i][j]+=r[i][j-1]+1;
                c[i][j]+=c[i-1][j]+1;
            }
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mat[i][j])
            {
                dp[i][j]=1+min(dp[i-1][j-1], min(r[i][j]-1,c[i][j]-1));
                ans=max(ans,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }

    return ans;
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int i,j;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>mat[i][j];

        int ans=solve(n,m);
        cout<<ans<<"\n";
    }
    return 0;
}
