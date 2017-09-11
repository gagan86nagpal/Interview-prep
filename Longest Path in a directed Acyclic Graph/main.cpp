#include <iostream>
#include <vector>
using namespace std;

// Main problem is to find the vertex from where we should start doing dfs so that we cover the longest path or we can say
// how to find the starting vertex of longest path

// There are two approaches

// 1. Find the toplogical Sorting order, make dfs in the order and find out the maximum depth of dfs
// Maximum Depth is the longest Path

// 2. This approach Uses dynamic Programming, while making dfs save the longest path starting from this vertex
// If this vertex is again called by it's previous node then add the saved path and stop the dfs.
// This solution is equivalent to , start dfs from all points and answer is maximum recursion depth achievable
// Here by saving the saving our result , we making this a linear algorithm



// If we have to print the path , then we will make our dfs return the leaf of the longest path too.
// Now , if we inverse the graph(make the edges in reverse direction) , we can find the actual path too
vector <int> graph[1000];
int path_length[1000];   // will also be using this as visited array

int dfs(int root)
{
    if(path_length[root]!=0)  // we have already computed the path length from this node, just return it
        return path_length[root];

    int i;
    int max_path=0; //  This will hold the maximum path length of the child nodes to the root
    for(i=0;i<(int)graph[root].size();i++)
    {
       int path= dfs(graph[root][i]);
       if(max_path <path)
        max_path=path;
    }
    // save the result
    path_length[root]=max_path+1;// 1 is added as we counting a node itself in the path
    return path_length[root];
}

int maxPathLength(int v)
{
    int max_path=1;
    int i;
    for(i=1;i<=v;i++)
    {
        if(path_length[i]==0) // not yet visited
        {
            int path=dfs(i);
            if(max_path < path)
                max_path=path;
        }
    }
    return max_path;
}
int main()
{
    int a,b,v,e,i;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
    }
    cout<<"Longest Path in a DAG: "<<maxPathLength(v)<<"\n";
    return 0;
}
