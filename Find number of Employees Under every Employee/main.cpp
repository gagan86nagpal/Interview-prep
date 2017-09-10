#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector <int> tree[30];

// WIll work ,if employees are given as string of length 1 only
// If They are not given , then we should create a map that maps each employee to an integer
// Idea is to build a tree
// Now make a dfs and count number of nodes in subtree including the node
// For every node , ans is count -1 as we are excluding the fact that a employee is not a manager to itself


// Since each manager is represented by a string , we have to make each employee corresponding to an index
int index[150];

int subtreeCount[30]; // Counts the subtree count for very node

void dfs(int root)
{
    int i;
    for(i=0;i<(int)tree[root].size();i++)
    {
        dfs(tree[root][i]);
        subtreeCount[root]+=subtreeCount[tree[root][i]];
    }
}
int main()
{
    map <string,string> m;
    m.insert(make_pair("A","C"));
    m.insert(make_pair("B","C"));
    m.insert(make_pair("C","F"));
    m.insert(make_pair("D","E"));
    m.insert(make_pair("E","F"));
    m.insert(make_pair("F","F"));
    int root;
    int cnt=0;
    // indexing
    for(auto p:m)
    {
        index[(int)p.first[0]]=cnt;
        subtreeCount[cnt]=1; // all nodes are initialized as 1 subtreecount
        cnt++;
    }

    // Creating our tree
    for(auto p :m)
    {
        int a=index[(int)p.second[0]];
        int b=index[(int)p.first[0]];
        if(a!=b) // if edge between distinct nodes
            tree[a].push_back(b);
        if(a==b) // root of tree
            root=a;
    }
    dfs(root);

    // Printing answer
    cnt=0;
    for(auto p :m)
        cout<<p.first<<":"<<subtreeCount[cnt++]-1<<"\n";
    return 0;
}
