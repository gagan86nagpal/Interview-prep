#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int mat[101][101];

bool check(int i,int j,int n,int m ,int sent)
{
    if(mat[i][j]!=sent && i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}
void solve(int n,int m)
{
    int cnt = n*m;
    priority_queue < pair <int,pair <int,int> >   , vector <pair <int,pair <int,int> > > , greater < pair <int,pair <int,int> > > >pq;
    int sent = mat[0][0]-1;
    pq.push(make_pair(mat[0][0] , make_pair(0,0)));
    mat[0][0]=sent;
    while(cnt--)
    {
        pair <int,pair <int,int> > p = pq.top();
        pq.pop();
        cout<<p.first <<" ";
        int i = p.second.first;
        int j =p.second.second;
        if(check(i,j+1,n,m,sent))
            pq.push(make_pair(mat[i][j+1],make_pair(i,j+1))),mat[i][j+1]=sent;
        if(check(i+1,j,n,m,sent))
            pq.push(make_pair(mat[i+1][j],make_pair(i+1,j))),mat[i+1][j]=sent;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];

    solve(n,m);
    return 0;
}
/*
4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
*/
