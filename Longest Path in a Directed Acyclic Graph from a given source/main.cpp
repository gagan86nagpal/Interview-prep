#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Idea is to visit the vertex in top sort first and calculate their longest path from source
// THen proceed to their adjacent vertex


vector <int> top_sort;
vector < pair <int,int> > graph[10000];

// we don't need an visited array since there is no cycle and dfs will never run in infinite loop
// we are using a visited array , to cover the vertex
int vis[10000];
int is_reachable[10000];
int longest_distance[10000];

void print(int,int);
void dfs(int s)
{
    vis[s]=1;
    int i;
    for(i=0;i<(int)graph[s].size();i++)
        dfs(graph[s][i].first);
    top_sort.push_back(s);
}
// 0 based indexing
void topologicalSort(int v)
{
    int i;
    for(i=0;i<v;i++)
        if(!vis[i])
            dfs(i);

    reverse(top_sort.begin(),top_sort.end());
}

void longestDistance(int s,int v)
{
    int i;
    for(i=0;i<v;i++)
        longest_distance[i]=-2147483647;
    longest_distance[s]=0;
    is_reachable[s]=1;
    topologicalSort(v);

    for(int node1 : top_sort)
    {
        for(i=0;i<(int)graph[node1].size();i++)
        {

            int w=graph[node1][i].second;
            int node2 = graph[node1][i].first;
            if(longest_distance[node2] <  longest_distance[node1]+w)
                longest_distance[node2]=longest_distance[node1]+w;
            if(is_reachable[node1])
                is_reachable[node2]=1;
        }
    }
    print(s,v);
}

void print(int s,int v)
{
    int i;
    cout<<"Longest Distance from source:"<<s<<" :\n";
    for(i=0;i<v;i++)
    {
        if(!is_reachable[i])
            cout<<"NR ";
        else
            cout<<longest_distance[i]<<" ";
    }
    cout<<"\n";
}
int main()
{

    /*
6 10
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 5 1
3 4 -1
4 5 -2
1

INPUT

    */
    int v,e;
    int a,b,w;
    cin>>v>>e;
    int i;
    for(i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(b,w));
    }
    int s;
    cin>>s;
    longestDistance(s,v);
    return 0;
}
