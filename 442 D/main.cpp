// Removing continue

#include <iostream>
#include <cmath>
using namespace std;
string mat[1005];
int dp[1005][1005];
int vis[1005][1005];
int n,m;
#define max 10000000
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
int shortestDistance(int i,int j,int x,int y,int k)
{
    vis[i][j]=1;
    if(i==x && y==j)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int a=max;
    for(int l=1;l<=k;l++)// down
    {
        if(inLimits(i+l,j) && mat[i+l][j]=='.')
        {
            if(vis[i+l][j] && dp[i+l][j]!=-1)  // already calculated
                a =min(a,1+dp[i+l][j]);
            else if(vis[i+l][j] && dp[i+l][j]==-1)  // I came from this subproblem
                continue;
            else    //I haven't seen this subproblem
                a=min(a,1+shortestDistance(i+l,j,x,y,k));
        }
        else
            break;
    }
    for(int l=1;l<=k;l++)//right
    {
        if(inLimits(i,j+l) && mat[i][j+l]=='.')
        {
            if(vis[i][j+l] && dp[i][j+l]!=-1)  // already calculated
                a = min(a,1+dp[i][j+l]);
            else if(vis[i][j+l] && dp[i][j+l]==-1)  // I came from this subproblem
                continue;
            else        //I haven't seen this subproblem
                a=min(a,1+shortestDistance(i,j+l,x,y,k));
        }
        else
            break;
    }
    for(int l=1;l<=k;l++) // up
    {
        if(inLimits(i-l,j)&& mat[i-l][j]=='.')
        {
            if(vis[i-l][j] && dp[i-l][j]!=-1)  // ALready calculated
                a = min(a,1+dp[i-l][j]);
            else if(vis[i-l][j] && dp[i-l][j]==-1)  // I came from this subproblem
                continue;
            else  // I haven't seen this subproblem
                a=min(a,1+shortestDistance(i-l,j,x,y,k));
        }
        else
            break;
    }
    for(int l=1;l<=k;l++)//left
    {
        if(inLimits(i,j-l)&& mat[i][j-l]=='.')
        {
            if(vis[i][j-l] && dp[i][j-l]!=-1)   // Already Calculated
                a = min(a,1+dp[i][j-l]);
            else if(vis[i][j-l] && dp[i ][j-l]==-1)  // i came from this subproblem
                continue ;
            else            // I haven't seen this subproblem
                a=min(a,1+shortestDistance(i,j-l,x,y,k));
        }
        else
            break;
    }
       return dp[i][j]=a;
}
void print(int x[1005][1005],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<x[i][j]<<"\t";
        cout<<"\n";
    }
}
void init(int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            dp[i][j]=-1,vis[i][j]=0;
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
        int dist = shortestDistance(sx,sy,fx,fy,k);
        cout<<dist<<"\n";
    }
    else
        cout<<"-1\n";

    print(dp,n,m);
    return 0;
}
/*
7 5 3
...#.
.#..#
###..
.....
.....
.....
.....
1 1 7 1
*/
