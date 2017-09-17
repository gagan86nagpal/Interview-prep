#include <iostream>
#include <vector>
using namespace std;

vector <int> graph [11];
vector <int > path;
int visited[11];

bool allVisited(int n)
{
    int i ;
    for(i=0;i<n;i++)
        if(visited[i]==0)
            return false;
    return true;
}
int endTime[11];
int cnt=0;
bool traversal(int s,int n , int m,int parent)
{
    if(visited[s]==true)
         return false;
    path.push_back(s);
    visited[s]=1;
    endTime[s]=cnt++;
    if(allVisited(n))
    {
        cout<<"Path:";
        int i;
        for(i=0;i<path.size();i++)
            cout<<path[i]<<" ";
        cout<<"\n";
        return true;
    }
    int i;
    for(i=0;i<(int)graph[s].size();i++)
    {
        int node = graph[s][i];
        if(node==parent)
            continue;
        if(traversal(node,n,m,s)==true)
            return true;
        else
        {
            if(endTime[s] < endTime[node])
            {
                path.pop_back();
                visited[node]=0;
                cnt--;
                endTime[node]=0;
            }
        }
    }
    path.pop_back();
    visited[s]=0;
    cnt--;
    endTime[s]=0;
    return false;
}

bool solve(int n,int m)
{

    int i;
    for(i=0;i<n;i++)
    {
        cnt=0;
        if(traversal(i,n,m,-1))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    int i;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool flag = solve(n,m);
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
