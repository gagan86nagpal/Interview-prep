#include <iostream>
#include <vector>
using namespace std;
// using adjacency matrix approach
int graph[11][11];
vector <int> path;
int vis[11];
bool isHamiltonianPath(int source,int cnt,int start,int v)
{
    if(cnt==v)
    {
        if(graph[source][start])
        {
            path.push_back(start);
            cout<<"Path:";
            for(int i : path)
                cout<<i<<" ";
            cout<<"\n";
            path.pop_back();
            return true;  // covered all vertices
        }
        return false;
    }

    int i;
    bool ret = false;
    for(i=0;i<v;i++)
    {
        if(graph[source][i] && vis[i]==0)
        {
            vis[i]=1;
            path.push_back(i);
            ret  = ret ||isHamiltonianPath(i,cnt+1,start,v);  // short circuit if it finds even a single path
            path.pop_back();
            vis[i]=0;
        }
    }
    return ret;
}
int main()
{
    int n,m;
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>graph[i][j];
    }
    vis[0]=1;
    path.push_back(0);
    bool isPath = isHamiltonianPath(0,1,0,n);
    path.pop_back();
    vis[0]=0;  // unnecessary but to maintain the recursion invariant
    if(!isPath)
        cout<<"-1\n";
    return 0;
}


/*
5 7
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

5 6
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0
*/
