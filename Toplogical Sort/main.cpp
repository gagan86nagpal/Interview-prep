#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> graph[100];
vector <int> top_sort;
int vis[1000];

// Make a dfs , and push the element when dfs is about to end
// Order will be reverse in topological sorting
// Reverse this.
void dfs(int root)
{
    if(vis[root])
        return;
    vis[root]=1;
    int i;
    for(i=0;i<(int)graph[root].size();i++)
    {
        dfs(graph[root][i]);
    }
    top_sort.push_back(root);  // pushing root because dfs is exiting here
}
void topSort(int v)
{
    int i;
    for(i=1;i<=v;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    reverse(top_sort.begin(),top_sort.end());  // Reversing the order of elements will give us dfs
    cout<<"Top Logical Sorting order is:";
    for(auto x : top_sort)
        cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    int v,e,a,b,i;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
    }
    topSort(v);
    return 0;
}
