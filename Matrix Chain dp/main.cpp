#include <iostream>
#include <vector>
using namespace std;
int p[1000];
int dp[1000][1000];
void init(int n,int m)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
}
int matrixMul(int s,int e)
{
    if(dp[s][e]!=-1)
        return dp[s][e];
    if(e-s+1<=2)
    {
        return dp[s][e]=0;
    }
    int mi=1<<30;
    for(int i=s;i<e-1;i++)
    {
        int cost=p[s]*p[i+1]*p[e];
        mi=min(mi,matrixMul(s,i+1)+cost +matrixMul(i+1,e) );
    }
    return dp[s][e]=mi;
}
int main()
{
    int n;
    int i;
    cin>>n;
    vector <int>v;

    for(i=0;i<=n;i++)
        cin>>p[i];

    init(n,n);
    int cost=matrixMul(0,n);
    cout<<cost<<"\n";
    return 0;
}
