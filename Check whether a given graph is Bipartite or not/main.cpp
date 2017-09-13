#include <iostream>
#include <queue>
using namespace std;
// Color the graph using two colors only
// Start from source , and do a bfs

int color[1000];   // -1 not colored yet , 0 is a color , 1 is a color
int vis[1000];
vector <int > graph[1000];
bool bfs(int s)
{
    color[s]=0;
    vis[s]=1;
    queue < int> q;
    q.push(s);
    while(!q.empty())
    {
        int v= q.front();
        q.pop();
        int i;
        for(i=0;i<(int)graph[v].size();i++)
        {
            if(vis[graph[v][i]])
            {
                if(color[graph[v][i]]==color[v])
                    return false;
            }
            else
            {
                q.push(graph[v][i]);
                vis[graph[v][i]]=1;
                color[graph[v][i]] = 1^color[v];
            }
        }
    }
    return true;
}

bool BipartiteMatching(int v)
{
    int i;

    for(i=0;i<v;i++)
    {
        if(!vis[i])
            if(!bfs(i))
                return false;
    }
    return true;
}
int main()
{
    int v,e;
    cin>>v>>e;
    int i;
    int a,b;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
     //   graph[b].push_back(a);
    }

    if(BipartiteMatching(v))
        cout<<"Given Graph is Bipartite\n";
    else
        cout<<"Given Graph is not Bipartite\n";
    return 0;
}

// Test cases

/*

4 4
0 1
1 2
2 3
3 0
*/

/*
3 3
0 1
1 2
2 0
*/
