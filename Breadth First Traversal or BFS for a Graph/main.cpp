#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool vis[100];
vector <int> graph[100];
void bfs(int root)
{
    queue <int> q;
    q.push(root);
    while(!q.empty())
    {
        int node=q.front();
        vis[node]=1;
        q.pop();
        cout<<node<<" ";
        int i;
        for(i=0;i<graph[node].size();i++)
            if(!vis[graph[node][i]])
                q.push(graph[node][i]);
    }
}

int main()
{
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);
    bfs(2);
    return 0;
}
