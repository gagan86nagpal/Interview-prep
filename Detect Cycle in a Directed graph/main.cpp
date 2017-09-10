#include <iostream>
#include <vector>
using namespace std;


// Make dfs from each unvisited nodes
// If in a dfs call , we encounter a node that has been visited in the same dfs call , then there is a cycle
// Vis array makes dfs calls for unvisited vertices
// In a dfs call , we are maintaining recurseStack that keep tracks of nodes in the dfs call
int recurseStack[100];
int vis[100];
vector <int> graph[100];
bool dfs(int root)
{
    vis[root]=1;  // since it is visited now
    if(recurseStack[root]) // if given root is already present in the same dfs call, report a cycle
        return true;
    recurseStack[root]=1;  // make this root in the dfs call
    int i;
    bool flag=false;
    for(i=0;i<(int)graph[root].size();i++)
    {
        flag|=dfs(graph[root][i]);  // flag will be true if there is atleast 1 cycle
    }
    recurseStack[root]=0;   // after the dfs call , root should be removed
    return flag;
}
bool isCyclic(int n)  // n is number of nodes , should be numbered as 0...n-1
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!vis[i])  // if for any unvisited root , dfs has cycles implies graph has cycles
        {
            if(dfs(i))
                return true;
        }
    }
    return false;  // if for each dfs call , no cycle , then graph doesn't have cycles
}
int main()
{
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(5);

    if(isCyclic(6))
        cout<<"Graph is cyclic\n";
    else
        cout<<"Graph does not have cycles\n";
    return 0;
}
