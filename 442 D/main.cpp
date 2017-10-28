#include <iostream>
#include <cmath>
using namespace std;
string mat[1001];
int dp[1001][1001];
int vis[1001][1001];
int n,m;

bool inLimits(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
bool isReachable(int i,int j,int x,int y)
{
    vis[i][j]=1;
    if(i==x && y==j)
        return true;
    bool a=false ,b=false,c=false,d=false;
    if(inLimits(i+1,j) && mat[i+1][j]=='.' && vis[i+1][j]==0)
        a=isReachable(i+1,j,x,y);
    if(inLimits(i,j+1) && mat[i][j+1]=='.' && vis[i][j+1]==0)
        b=isReachable(i,j+1,x,y);
    if(inLimits(i-1,j) && mat[i-1][j]=='.' && vis[i-1][j]==0)
        c=isReachable(i-1,j,x,y);
    if(inLimits(i,j-1) && mat[i][j-1]=='.' && vis[i][j-1]==0)
        d=isReachable(i,j-1,x,y);
    return a||b||c||d;
}
int shortestDistance(int i,int j,int x,int y)
{
    vis[i][j]=1;
    if(i==x && y==j)
        return 0;
    int a=100000,b=10000,c=1000000,d=1000000;
    if(inLimits(i+1,j) && mat[i+1][j]=='.' && vis[i+1][j]==0)
       a=1+ shortestDistance(i+1,j,x,y);
    if(inLimits(i,j+1) && mat[i][j+1]=='.' && vis[i][j+1]==0)
        b=1+shortestDistance(i,j+1,x,y);
    if(inLimits(i-1,j) && mat[i-1][j]=='.' && vis[i-1][j]==0)
        c=1+shortestDistance(i-1,j,x,y);
    if(inLimits(i,j-1) && mat[i][j-1]=='.' && vis[i][j-1]==0)
       d=1+ shortestDistance(i,j-1,x,y);
       return min(min(a,b), min(c,d)) ;
}
void init(int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            dp[i][j]=0,vis[i][j]=0;
}
int main()
{
    int k;
    cin>>n>>m>>k;
    int i;
    for(i=0;i<n;i++)
        cin>>mat[i];
    int sx,sy,fx,fy;
    cin>>sx>>sy>>fx>>fy;
    sx--;
    sy--;
    fx--;
    fy--;
    bool is_solve= isReachable(sx,sy,fx,fy);
    if(is_solve)
    {
        init(n,m);
        int dist = shortestDistance(sx,sy,fx,fy);
        cout<<dist<<"\n";
        cout<<ceil(dist/k)<<"\n";
    }
    else
        cout<<"-1\n";
    return 0;
}
