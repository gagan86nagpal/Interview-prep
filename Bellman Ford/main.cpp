#include <iostream>
#include <vector>
using namespace std;
#define inf 10000000

vector <pair <int,int> > graph[1000];

int dist[1000];

void bellman_ford(int s,int v,int e)
{
    int i,j,k;
    for(i=0;i<v;i++)
        dist[i]=inf;
    dist[s]=0;

    for(i=0;i<v-1;i++)
    {
        for(j=0;j<v;j++)
        {
            for(k=0;k<(int)graph[j].size();k++)  // u->v
            {
                int u=j;
                int v=graph[j][k].first;
                int w=graph[j][k].second;
                if(dist[v]>dist[u]+w)
                    dist[v]=dist[u]+w;
            }
        }
    }
}
int main()
{
    int v,e;
    int a,b,w;
    int i;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(b,w));
    }
    int s;
    cin>>s;
    bellman_ford(s,v,e);
    for(i=0;i<v;i++)
    {
        cout<<"distance["<<i<<"]:"<<dist[i]<<"\n";
    }
    return 0;
}


/*
5 8
0 1 -1
0 2 4
1 2 3
1 4 2
1 3 2
3 1 1
3 2 5
4 3 -3
0



*/
