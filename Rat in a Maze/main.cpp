#include <iostream>
#include <string>
#include <set>
using namespace std;


// Print all paths


// Rat is allowed only right and down directions

set <string> paths;
int maze[20][20];
void printPath(int n);
bool inBounds(int i,int j,int n)
{
    return i>=0 && i<=n-1 && j>=0 && j<=n-1;
}
bool solve(int i,int j,int n,string path)
{
    if(i==n-1 && j==n-1)
    {
        paths.insert(path);
        return true;
    }

    bool r=false,d=false;
    if(inBounds(i,j+1,n) && maze[i][j+1]==1)
    {
       r= solve(i,j+1,n,path+'R');
    }
     if(inBounds(i+1,j,n) && maze[i+1][j]==1)
    {
        d=solve(i+1,j,n,path+'D');
    }
    return r||d;
}

int main()
{
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n; // n*n maze
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>maze[i][j];

        paths.clear();
        solve(0,0,n,"");
        for(string path : paths)
            cout<<path<<" ";
        cout<<"\n";

    }
    return 0;
}
/*
3
4
1 0 0 0
1 1 0 1
0 1 0 0
0 1 1 1
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
7
1 1 0 1 1 0 1
0 1 0 0 1 1 1
1 1 1 1 0 1 0
0 1 0 1 1 1 1
0 1 0 0 1 0 1
0 1 1 1 1 0 1
0 0 0 0 1 1 1

*/
