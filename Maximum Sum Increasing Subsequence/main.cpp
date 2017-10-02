#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int segTree[4000];
vector < pair <int,int> > a;
int query(int node,int l,int r,int ql,int qr)
{
    if(r<ql ||  l> qr)// out of range
        return 0;
    if(ql<=l && qr >=r) // compleely inside
        return segTree[node];
    int m= (l+r)/2;
    return max(query(2*node+1,l,m,ql,qr),query(2*node+2,m+1,r,ql,qr));
}
void update(int node,int l,int r,int i,int ele)
{
    if(l==r && i==l)
    {
        segTree[node]=ele;
        return;
    }

    int m = (l+r)/2;
    if(i<=m) // left tree
        update(2*node+1,l,m,i,ele);
    else
        update(2*node+2,m+1,r,i,ele);
    segTree[node]=max(segTree[2*node+1],segTree[2*node+2]);
}

int sum[1000];

int comp1(pair <int,int> p1,pair<int,int> p2)
{
    if(p1.first!=p2.first)
        return p1.first<p2.first;
    return p1.second>p2.second;
}
int main()
{
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
   {
       cin>>x;
       a.push_back(make_pair(x,i));
   }
   sort(a.begin(),a.end(),comp1);
   for(i=0;i<n;i++)
   {
       int val=a[i].first;
       int index=a[i].second;
       int ma= query(0,0,n-1,0,index-1);
       update(0,0,n-1,index,ma+val);
       sum[index]=ma+val;
   }
   cout<<segTree[0]<<"\n";
    return 0;
}
