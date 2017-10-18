#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
# define inf 1000000000

vector <pair <int,int> > graph[10005];
vector <int> dist;
multiset < pair <int,int> > s;  // weight , vertex
void init(int source,int n)
{
    dist = vector<int> (n+3,inf);
    dist[source]=0;
}

void dijkstra(int n,int source)
{
    int i;
    s.insert(make_pair(0,source));
    while(!s.empty())
    {
        pair <int,int> p = *s.begin();
        s.erase(s.begin());
        int v = p.second;
        for(i=0;i<(int)graph[v].size();i++)
        {
            int u = graph[v][i].second;
            int w = graph[v][i].first;
            if(dist[u] > dist[v]+w)
            {
                s.erase(make_pair(dist[u],u));
                dist[u]=dist[v]+w;
                s.insert(make_pair(dist[u],u));
            }
        }
    }
}
void display(int n,int source)
{
    int i;
    for(i=1;i<=n;i++)
        if(i!=source)
            cout<<dist[i]<<" ";
}
int main()
{
    int n,m,i;
    int a,b,w;
    int source;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(w,b));
        graph[b].push_back(make_pair(w,a));
    }
    source=1;
    init(source,n);
    dijkstra(n,source);
    display(n,source);
    return 0;
}
/*
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
8 9 7
8 7 1
9 7 6
7 6 2
3 6 4
4 5 9
4 6 14
5 6 10
*/
