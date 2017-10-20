#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[100];
int color_assign[100];


void print(int v)
{
    cout<<"Solution: ";
    int i;
    for(i=0;i<v;i++)
        cout<<color_assign[i]<<" ";
    cout<<"\n";
}
bool canColor(int node ,int j)
{
    for(int adj_node : graph[node])
        if(color_assign[adj_node]==j)
            return false;
    return true;
}

bool color(int s,int cnt,int m,int v)
{
    if(cnt == v) // base case
    {
        int j;
        for(j=1;j<=m;j++) // try every color
            if(canColor(s,j))
            {
                print(v);
                return true;
            }
        return false;
    }
    int i,j;
    bool ret = false;
    for(i=0;i<(int)graph[s].size();i++)
    {
        int node =graph[s][i];
        if(color_assign[node]!=0) // already colored
            continue;

        for(j=1;j<=m;j++)
        {
            if(canColor(node,j))
            {
                color_assign[node]=j; // assign color
                ret = ret || color(node,cnt+1,m,v);
                color_assign[node]=0; // decolor it
            }
        }
    }
    return ret;
}
int main()
{
    int v,e,m,a,b;
    cin>>v>>e;
    int i;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin>>m ; // m colours
    color_assign[0]=1; // color with this 1
    bool isColoringPossible = color(0,1,m,v);
    color_assign[0]=0; // maintain loop invariant
    if(false == isColoringPossible)
        cout<<" Not Possible\n";
    return 0;
}
/*
4 5
0 1
0 3
0 2
2 3
2 1
3

10 15
0 1
0 5
0 4
1 6
1 2
2 3
2 7
3 8
3 4
4 9
5 7
5 8
6 8
6 9
7 9
3
*/
