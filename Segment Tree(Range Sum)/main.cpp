#include <iostream>

using namespace std;
int segTree[100];
int a[100];
void buildTree(int node,int l,int r)
{
    if(l==r)
    {
        segTree[node]=a[l];
        return ;
    }
    int m=(l+r)/2;
    buildTree(2*node+1,l,m);
    buildTree(2*node+2,m+1,r);
    segTree[node]=segTree[2*node+1]+segTree[2*node+2];
}
void update(int node,int l,int r,int in,int ele)
{
    if(l==r &&r==in)
    {
        segTree[node]=a[in]=ele;
        return;
    }
    int m = (l+r)/2;
    if(in<=m)
        update(2*node+1,l,m,in,ele);
    else
        update(2*node+2,m+1,r,in,ele);
    segTree[node]=segTree[2*node+1]+segTree[2*node+2];
}
int query(int node,int l,int r , int ql,int qr)
{
    if(qr <l  || ql > r)
        return 0 ;  // out of the range query
    if(ql<=l && qr >=r) // COmpletely inside the node
        return segTree[node] ;
    // else
    int m = (l+r)/2;
    return query(2*node+1,l,m,ql,qr) + query(2*node+2,m+1,r,ql,qr);
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    buildTree(0,0,n-1);


    int q;
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>c>>a>>b;
        if(c==0)
            cout<<query(0,0,n-1,a,b)<<"\n";
        if(c==1)
            update(0,0,n-1,a,b);
    }
    return 0;
}
