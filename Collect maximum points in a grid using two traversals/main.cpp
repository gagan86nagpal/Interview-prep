#include <iostream>

using namespace std;

int mat[100][100];

int dp[101][101][101];

void init(int r,int c)
{
    int i,j,k;
    for(i=0;i<=r;i++)
        for(j=0;j<=c;j++)
            for(k=0;k<=c;k++)
                dp[i][j][k]=-1;
}
int maxPointsCollected(int row,int c1,int c2,int n,int m)
{
    if(row==n && c1==1 && c2==m)
    {
        if(c1==c2)
            return mat[row][c1];
        else
            return mat[row][c1]+mat[row][c2];
    }

    if(row==n)
        return -(1<<30);
    if(dp[row][c1][c2]!=-1)
        return dp[row][c1][c2];
    int maxPoints = -(1<<30);
    int x,y;
    for(x=-1;x<=1;x++)
        for(y=-1;y<=1;y++)
            if( (c1+x>=1 && c1+x<=m && c2+y>=1 && c2+y<=m ) ==false)
                continue;
            else if(c1==c2)
                maxPoints=max(maxPoints,mat[row][c1]+maxPointsCollected(row+1,c1+x,c2+y,n,m) );
            else
                maxPoints=max(maxPoints,mat[row][c2]+mat[row][c1]+maxPointsCollected(row+1,c1+x,c2+y,n,m));

    return dp[row][c1][c2]=maxPoints;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>mat[i][j];
    init(n,m);
    int ans = maxPointsCollected(1 , 1, m , n , m);
    cout<<ans<<"\n";
    return 0;
}

/*
5 4
3 6 8 2
5 2 4 3
1 1 20 10
1 1 20 10
1 1 20 10

2 2
5 4
6 2

3 3
3 6 8
5 2 4
1 1 20
*/
