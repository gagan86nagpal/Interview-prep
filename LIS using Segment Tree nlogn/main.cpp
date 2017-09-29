#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int segtree[4000000];
vector <pair <int,int> > a;
int query(int node,int l ,int r,int ql,int qr)
{
    if(l>r)
        return 0;
    if(qr < l || ql > r)  // query is out of range
        return 0;
    if(ql<=l && qr >=r)
        return segtree[node];
    int m=(l+r)/2;
    return max (query(2*node+1,l,m,ql,qr) , query(2*node+2,m+1,r,ql,qr) );
}
bool comp(pair < int,int> p1,pair < int,int > p2)
{
    if(p1.first!=p2.first)
        return p1.first < p2.first;
    else
        return p2.second<p1.second;
}
void update(int node,int l,int r,int in,int ele)
{
    if(l==r)
    {
        segtree[node]=ele;
        return;
    }
    int m = (l+r)/2;
    if(in<=m) // left subtree
        update(2*node+1,l,m,in,ele);
    else
        update(2*node+2,m+1,r,in,ele);
    segtree[node]= max(segtree[2*node+1],segtree[2*node+2]);
}
int main()
{
    int n,x;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(),a.end(),comp);
    for(int i=0;i<n;i++)
    {
        int q=1+query(0,0,n-1,0,a[i].second-1);
        update(0,0,n-1,a[i].second,q);
    }
    cout<<segtree[0]<<"\n";
    return 0;
}
