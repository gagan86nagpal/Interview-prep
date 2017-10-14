#include <iostream>

using namespace std;
string a,b;

int dp[1000][1000];
int lcs(int i,int j,int n,int m )
{
    if(i==n || j==m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
        return dp[i][j]=1+lcs(i+1,j+1,n,m);
    else
        return dp[i][j]=max(lcs(i+1,j,n,m),lcs(i,j+1,n,m));
}
void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        init(a.size(),b.size());
        int ans = a.size() + b.size() - lcs(0,0,a.size(),b.size());
        cout<<ans<<"\n";
    }
    return 0;
}
