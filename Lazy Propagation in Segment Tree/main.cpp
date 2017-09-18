#include <iostream>

using namespace std;
int segTree[100];
int lazyTree[100];
int a[50];
void print(int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    for(i=0;i<3*n-1;i++)
        cout<<segTree[i]<<" ";
    cout<<"\n";
     for(i=0;i<3*n-1;i++)
        cout<<lazyTree[i]<<" ";
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
    if(lazyTree[node]!=0) // if node is lazy , then update it and make it's child as lazy
    {
        segTree[node] += (r-l+1)*lazyTree[node];
        int add=lazyTree[node];
        lazyTree[node]=0;
        if(l!=r)
        {
            lazyTree[2*node+1]+=add;
            lazyTree[2*node+2]+=add;
        }
        if(l==r)
            a[l]+=add;
    }
    if(ql<=l && qr >=r)
        return segTree[node];
    int m = (l+r)/2;
    int a= query(2*node+1,l  ,m,ql,qr);
    int b= query(2*node+2,m+1,r,ql,qr);
    // Here we don't need to recurse to parents as here we are only updating out lazy nodes
    // whose parents are already fine.
    //In fact by doing segTree[2*node] = segTree[2*node+1] +segTree[2*node+2] would be wrong
    // Say , a node has two lazy children , out of which 1 gets rectified above (it's parent would be fine already)
    // Another sibling of this node is still lazy, node doing the above operation will make parent node inconsistent
    return a+b;
}

// Increase all elements int the range [x..y] by add
void updateRange(int node,int l,int r,int x,int y,int add)
{
    if(lazyTree[node]!=0) // if node is lazy , then update it and make it's child as lazy
    {
        segTree[node] += (r-l+1)*lazyTree[node];
        int val=lazyTree[node];
        lazyTree[node]=0;
        if(l!=r)
        {
            lazyTree[2*node+1]+=val;
            lazyTree[2*node+2]+=val;
        }
    }
    if(r<x || l> y)
        return ;
    if(l==r)
    {
        a[l]+=add;
        segTree[node]+=add;
        return;
    }
    if(x<=l && y>=r) // completely inside
    {
        segTree[node]+=(r-l+1)*add; // update the node
        lazyTree[node]=0;
        if(l!=r)
        {

            lazyTree[2*node+1]+=add;  // mark left child as lazy
            lazyTree[2*node+2]+=add;  // mark right child as lazy
        }
        return;
    }
    int m;
    m=(l+r)/2;
    updateRange(2*node+1,l  ,m,x,y,add);
    updateRange(2*node+2,m+1,r,x,y,add);
    segTree[node]=segTree[2*node+1]+segTree[2*node+2];  // Here are making a range node(sometines a lead node too)
    // It's above should be consistent , and we are making it by this
}
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    buildTree(0,0,n-1);
  //  print(n);
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
      //  print(n);
    }
    return 0;
}
