#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int id[10002];

vector < pair <int , pair <int,int> > > edges;
void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        id[i]=i;
}

int find_representative(int i)
{
    if(id[i]!=i)
        return id[i]= find_representative(id[i]);
    return i;
}
void unionSet(int i,int j)
{
    int ri = find_representative(i);
    int rj = find_representative(j);
    if(ri!=rj)
        id[ri]=rj;
}

int kruskal(int n,int m)
{
    init(n); // sets
    int i;
    int ret=0;
    for(i=0;i<m;i++)
    {
        int w =edges[i].first;
        int a = edges[i].second.first;
        int b  = edges[i].second.second;
        if(find_representative(a)!=find_representative(b))  // they will not create a cycle
        {
            ret+=w;
            unionSet(a,b);
        }
    }
    return ret;
}
int main()
{
    int n,m;
    int i;
    int w,a,b;
    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        edges.push_back(make_pair(w, make_pair(a,b)));
    }
    sort(edges.begin(),edges.end());

    int minCost = kruskal(n,m);
    cout<<minCost<<"\n";
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
