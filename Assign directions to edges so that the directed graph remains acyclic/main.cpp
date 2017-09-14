#include <iostream>
#include <vector>
using namespace std;


// Given a graph with both directed and undirected edges. It is given that the only directed edges don’t form cycle.
//How to assign directions to undirected edges so that the new graph
//(with all directed edges) remains acyclic even after the assignment?


/*
Idea is to find topological sort only with directed edges and then for every undirected edge
 assign direction in accordance to topological sorting
Implementation idea is not to find a topological sorting , rather node's finish time in dfs
Since, their finish time is a way to check their positioning in topological sorting
*/
vector < pair <int,int> >graph[1000];
int finish[1000];
int vis[1000];
// entry in a graph is (node,0 or 1)   0 means edge is undirected , while 1 means it is directed
int t=0; // finish time

void dfs(int s)
{
    vis[s]=1;
    int i;
    for(i=0;i<(int)graph[s].size();i++)
        if(graph[s][i].second==1) // pnly directed edges
            dfs(graph[s][i].first);

    finish[s]=t++;
}
void assignDirection(int v)
{
    int i,j;
    for(i=0;i<v;i++)
        for(j=0;j<(int)graph[i].size();j++)
            if(graph[i][j].second==0)  // undirected
            {
                int node=graph[i][j].first;
                if(finish[i] < finish [node])   // j comes first in top sort
                    cout<<node<<" should direct to "<<i<<"\n";
                else
                    cout<<i<<" should direct to "<<node<<"\n";


            }
}
void callDfs(int v)
{
    int i;
    for(i=0;i<v;i++)  // 0 based indexing
        if(!vis[i])
            dfs(i);  // make dfs calls to every vertex
    assignDirection(v);
}


int main()
{
   int v,e;
   int a,b,f;
   cin>>v>>e;
   int i;
   for(i=0;i<e;i++)
   {
       cin>>a>>b>>f;
       graph[a].push_back(make_pair(b,f));
    }
    callDfs(v);
    return 0;
}

/*
6 13
0 3 0
0 2 0
4 5 0
0 1 1
0 5 1
1 3 1
1 2 1
1 4 1
2 3 1
2 4 1
3 4 1
5 1 1
5 2 1
 */
