#include <iostream>

using namespace std;
char mat[101][101];
int hor[101][101];
int ver[101][101];
void preprocess(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(mat[i][j]=='X')
            {
                hor[i][j]+=hor[i][j-1]+1;
                ver[i][j]+=ver[i-1][j]+1;
            }
            else
            {
                hor[i][j]=ver[i][j]=0;
            }
        }
}

bool isSquare(int bx,int by,int l)
{
    int a=hor[bx][by]-hor[bx][by-l];
    int b=hor[bx-l+1][by]-hor[bx-l+1][by-l];
    int c=ver[bx][by]-ver[bx-l][by];
    int d=ver[bx][by-l+1]-ver[bx-l][by-l+1];
    return a==b&&b==c&&c==d;

}

int maxSquare(int n)
{
    int i,j;
    int ans=0;
    for(i=n;i>0;i--)
    {
        for(j=n;j>0;j--)
        {
            // i , j is bottom right corner
            int k = min(hor[i][j],ver[i][j]);
            while(k--)
            {
                if(isSquare(i,j,k+1))
                    ans = max(ans,k+1);
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>mat[i][j];
    preprocess(n);
    int ans = maxSquare(n);
    cout<<ans<<"\n";
    return 0;
}
