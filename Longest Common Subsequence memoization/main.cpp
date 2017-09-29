#include <iostream>
#include <string>
using namespace std;
int dp[1000][1000];
void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}
int lcs(string a,string b,unsigned sa,unsigned sb)
{
    if(a.size()==sa || b.size()==sb)
        return 0;
    if(dp[sa][sb]!=-1)
        return dp[sa][sb];

    if(a[sa]==b[sb])
        dp[sa][sb]=1+lcs(a,b,sa+1,sb+1);
    else
        dp[sa][sb]=max(  lcs(a,b,sa+1,sb),lcs(a,b,sa,sb+1) );
    return dp[sa][sb];
}
int main()
{
    string a,b;
    cin>>a>>b;
    init(a.size()-1,b.size()-1);
    int ans = lcs(a,b,0,0);
    cout<<"Length of LCS:"<<ans<<"\n";
    return 0;
}
