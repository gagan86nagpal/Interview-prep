#include <iostream>

using namespace std;
int dp[2002][2002];
void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}
int editDistance(string &a , string &b,unsigned i,unsigned j)
{
    if(i==a.size()) // a is exhausted
    {
        return b.size()-j;
    }
    if(j==b.size())
    {
        return a.size()-i;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
   {
       dp[i][j]=editDistance(a,b,i+1,j+1);
   }
    else
    {
        int x,y,z;
        x=editDistance(a,b,i+1,j+1)+1;
        y=editDistance(a,b,i+1,j)+1;
        z=editDistance(a,b,i,j+1)+1;
        dp[i][j]= min(x, min(y,z) );
    }
    return dp[i][j];
}
int main()
{
    string a,b;
    cin>>a>>b;
    init(a.size(),b.size());
    int ans=editDistance(a,b,0,0);
    cout<<ans<<"\n";
    return 0;
}
