#include <iostream>

using namespace std;

char mat[101][101];
int dp[101][101];


// Here we don't need an visited array ,
// as , we can only make a move to the next character
// hence it cannot happen that we are revisiting that element
// Because of this , our dp exhibits optimal sub structure too.
// If we hit a character , and we have already computed the longest path
// Then all the paths in the longest path of the just visited character
// will not be encountered , hence we just need to find the longest path
// and dp there after
int longestPath(int i,int j,int n,int m)
{
    int path=0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    for(int x=i-1;x<=i+1;x++)
        for(int y=j-1;y<=j+1;y++)
            if(x>=1 && x<=n && y>=1 && y<=m  && mat[x][y] == mat[i][j]+1)
            {
               path=max(path,1+longestPath(x,y,n,m) );
            }
    return dp[i][j]=path;
}

int solve(char s ,int n,int m)
{
    int i,j;
    int path=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            dp[i][j]=-1;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(mat[i][j]==s)
            {
               path = max(path,1+longestPath(i,j,n,m));
            }
        }
    }
    return path;
}
int main()
{
    int n,m;
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>mat[i][j];

    char s;
    cin>>s;
    int longest_path = solve(s,n,m);
    cout<<longest_path<<"\n";
    return 0;
}

/*
3 3
a c d
h b e
i g f
e

3 3
a b c
b a d
c d e
a
*/
