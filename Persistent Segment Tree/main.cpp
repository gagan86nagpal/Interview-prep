#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Every updaye query makes a new version of Segtree
// While keeping track of previous versions
struct node
{
    int data;
    node* left;
    node* right;
};
int a[100];
node* getNewNode(int data=0)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* seg_tree[100]; // 100 version of Segtree

node* buildFirstVersion(int l,int r)
{
    node* root=getNewNode();
    if(l==r)
    {
        root->data=a[l];
        return root;
    }
    int m=(l+r)/2;
    root->left=buildFirstVersion(l,m);
    root->right=buildFirstVersion(m+1,r);
    root->data = root->left->data + root->right->data;
    return root;
}

void leverlOrderTraversal(node* root)
{
    queue< node* > q;
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
    cout<<"\n";
}
int query(node* root,int l,int r,int ql,int qr)
{
    if(qr <l || ql > r) // outside
        return 0;
    if(ql<=l && qr >=r) // completely inside
        return root->data;

    // Partially inside,outside
    int m=(l+r)/2;
    int a=query(root->left,l,m,ql,qr);
    int b=query(root->right,m+1,r,ql,qr);
    return a+b;
}
// it returns a new segtree that has a[in]=ele changed in prev version of segtree
// Time and space is logn
node* update(node* prev,int l,int r,int in,int ele)
{
    node *curr=getNewNode();
    if(l==r)// we have reached the required leaf
    {
        curr->data=ele;
        return curr;
    }
    int m  = (l+r)/2;
    if(in<=m)
    {
        curr->right=prev->right;
        curr->left=update(prev->left,l,m,in,ele);
    }
    else
    {
        curr->left=prev->left;
        curr->right=update(prev->right,m+1,r,in,ele);
    }
    curr->data=curr->left->data+ curr->right->data;
    return curr;
}
int main()
{
    int n,i,version=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    seg_tree[version++]=buildFirstVersion(0,n-1);
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,c,v;
        cin>>c>>v>>a>>b;
        if(c==0)
            cout<<query(seg_tree[v],0,n-1,a,b)<<"\n";
        else  // change at index a to value = b , for version v
            seg_tree[version++]= update(seg_tree[v],0,n-1,a,b);
     //   cout<<"Version:"<<v<<" :";
      //  leverlOrderTraversal(seg_tree[v]);
    }
    return 0;
}
