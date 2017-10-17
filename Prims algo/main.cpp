#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector < pair <int,int> > graph[10002]; // weight , vertex
int visited[10002];
int prims(int source,int n)
{
    int ret=0;
    priority_queue < pair<int,int> , vector < pair < int,int> > ,greater < pair <int,int> > > pq;
    visited[source]=1;
    for(int j=0;j<(int)graph[source].size();j++)
        pq.push(graph[source][j]);
    int i=0;
    while(i<n-1)
    {
        pair <int,int> e = pq.top();
        int w = e.first;
        int v = e.second;
        pq.pop();
        if(visited[v])
            continue;
        i++;
        visited[v]=1;
        ret+=w;
        for(int j=0;j<(int)graph[v].size();j++)
            if( visited[ (graph[v][j]) .second] !=1)
                pq.push(graph[v][j]);
    }
    return ret;
}

int main()
{
    int n,m;
    int a,b,w;
    cin>>n>>m;
    int i;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(w,b));
        graph[b].push_back(make_pair(w,a));
    }

    int ans = prims(1,n);
    cout<<ans<<"\n";
    return 0;
}
/*
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
*/
