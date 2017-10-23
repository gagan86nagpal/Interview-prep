#include <iostream>

using namespace std;
char mat[100][100];
int vis[100][100];

void visit(int x,int y,int n,int m)
{
    int i,j;
    for(i=x;i<n;i++)
    {
        if(mat[i][y]!='X')
            break;

        for(j=y;j<m;j++)
        {
            if(mat[i][j]=='X')
                vis[i][j]=1;
            else
                break;
        }
    }
}

int solve(int n,int m)
{
    int i,j;
    int cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]=='X' && vis[i][j]==0)
            {
                cnt++;
                visit(i,j,n,m);
            }
        }
    }
    return cnt;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>mat[i][j];
    int ans = solve(n,m);
    cout<<ans<<"\n";
    return 0;
}
/*
6 3
O O O
X X O
X X O
O O X
O O X
X X O

6 6
X O O O O O
X O X X X X
O O O O O O
X X X O X X
X X X O X X
O O O O X X

*/
