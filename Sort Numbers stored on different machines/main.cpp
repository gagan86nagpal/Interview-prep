#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector  < vector <int > > machine;
vector <int> sorted;

void sortDistributive(int m)
{
    int i;
    priority_queue < pair <int,int>  , vector < pair <int,int>  > ,greater < pair <int,int> > > pq;
    vector <int> pos(m,0);
    for(i=0;i<m;i++)
    {
        if(pos[i]!=(int)machine[i].size())
        {
            pq.push( make_pair( machine[i][pos[i]] ,i) );
            pos[i]++;
        }
    }
    while(!pq.empty())
    {
        pair <int,int> p = pq.top();
        pq.pop();
        sorted.push_back(p.first);
        int mn = p.second;
        if(pos[mn]!=(int)machine[mn].size())
        {
            pq.push(make_pair(machine[mn][pos[mn]],mn));
            pos[mn]++;
        }
    }
}
int main()
{
    vector < int> a;
    int x,n,m;
    cin>>m;
    int i,j;
    for(i=0;i<m;i++)
    {
        cin>>n;
        a.clear();
        for(j=0;j<n;j++)
        {
            cin>>x;
            a.push_back(x);
        }
        machine.push_back(a);
    }
    sortDistributive(m);
    for(int x: sorted)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}
3
3
30 40 50
2
35 45
5
10 60 70 80 100
