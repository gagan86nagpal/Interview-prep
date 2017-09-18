#include <iostream>

using namespace std;
int segTree[100];
int a[50];
void print(int n)
{
    int i;
    for(i=0;i<3*n-1;i++)
        cout<<segTree[i]<<" ";
    cout<<"\n";
}
void buildTree(int node,int l,int r)
{
    if(l==r)
    {
        segTree[node]=a[l];
        return;
    }
    int m=(l+r)/2;
    buildTree(2*node+1,l,m);
    buildTree(2*node+2,m+1,r);
    segTree[node]=segTree[2*node+1]+segTree[2*node+2];
}

int query(int node,int l,int r,int ql,int qr)
{
    if(r<ql || l>qr)
        return 0;
    if(ql<=l && qr >=r)
        return segTree[node];
    int m = (l+r)/2;
    int a= query(2*node+1,l  ,m,ql,qr);
    int b= query(2*node+2,m+1,r,ql,qr);
    return a+b;
}

// Increase all elements int the range [x..y] by add
void updateRange(int node,int l,int r,int x,int y,int add)
{
    if(r<x || l> y)
        return ;
    if(l==r)
    {
        a[l]+=add;
        segTree[node]+=add;
        return;
    }
    int m;
    m=(l+r)/2;
    updateRange(2*node+1,l  ,m,x,y,add);
    updateRange(2*node+2,m+1,r,x,y,add);
    segTree[node]=segTree[2*node+1]+segTree[2*node+2];
}
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    buildTree(0,0,n-1);
    int q;
    cin>>q;
    while(q--)
    {
        int c,l,r,add;
        cin>>c;
        if(c==0)
        {
            cin>>l>>r;
            cout<<query(0,0,n-1,l,r)<<"\n";
        }
        else
        {
            cin>>l>>r>>add;
            updateRange(0,0,n-1,l,r,add);
        }
    }
    return 0;
}
