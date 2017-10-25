#include <iostream>

using namespace std;
int mat[101][101];

void floodFill(int x,int y,int nc,int oc,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m  && mat[x][y]==oc)
    {
        mat[x][y]=nc;
        floodFill(x+1,y,nc,oc,n,m);
        floodFill(x,y+1,nc,oc,n,m);
        floodFill(x-1,y,nc,oc,n,m);
        floodFill(x,y-1,nc,oc,n,m);
    }
}
int main()
{
    int n,m;
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>mat[i][j];
    int x,y,nc;
    cin>>x>>y>>nc;
    int oc = mat[x][y];
    floodFill(x,y,nc,oc,n,m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
