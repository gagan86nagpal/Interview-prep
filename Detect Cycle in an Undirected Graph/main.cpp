#include <iostream>
#include <vector>
using namespace std;

// In undirected graph, we don't need a recurseStack array because if an already visited element is visited in a dfs
// Then it will contribute to a cycle

vector <int> graph[100];
int vis[1000];
// We are checking whether we are making a call to a node that is already visited
// Parent that makes a call to it's unvisited child can be called again by the same child as graph is undirected
// So , we have to keep track of parent that makes this dfs call , such that we don't make another dfs call to the parent
// Hence, parent parameter. If it is the first of DFS , parent is -1;
bool dfs(int root,int parent=-1)
{
    if(vis[root])
        return true;  // if root is already visited , then it is a cycle
    vis[root]=1;
    int i,flag=false;
    for(i=0;i<(int)graph[root].size();i++)
    {
        int node=graph[root][i];
        if(node==parent)        // It makes dfs to just its parent , and can go into infinite recursion
            continue;
       flag=dfs(node,root)||flag;
    }
    return flag;
}

bool isCyclic(int n)  // Nodes are numbered as 1.2.....n
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i))   // if at any point dfs returns true, then it has cycle
                return true;
        }
    }
    return false;
}
int main()
{
    int v,e,i,a,b;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(isCyclic(v))
        cout<<"Graph has cycles\n";
    else
        cout<<"Graph does not have cycles\n";
    return 0;
}
