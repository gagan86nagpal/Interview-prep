#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector <int> v;
int dp[1000][10];
void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}
int coinChange(int n,int m)
{

    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(m==-1)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    dp[n][m]=coinChange(n-v[m],m )+coinChange(n,m-1);
    return dp[n][m];
}
int main()
{
    int n,m,x;
    cin>>m>>n;
    init(n,m);
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
