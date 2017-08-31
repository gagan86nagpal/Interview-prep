#include <iostream>
#include <vector>
using namespace std;
struct node
{
    char data;
    node* left,*right;
};
vector < char> pre;
vector <char > in;
node* newNode(char data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void printVector(vector <char > v,int l,int r)
{
    cout<<l<<":"<<r<<"\n";
    int i=l;
    while(i<=r)
        cout<<v[i++]<<" ";
    cout<<"\n";
}
node* buildTree(int ps,int pe,int is,int ie)
{
    if(pe==ps  && ie==is && pre[ps]==in[is])  // 1 node
        return newNode(pre[pe]);
    char root = pre[ps];
    int temp;
    for(temp=is;temp<=ie;temp++)
        if(in[temp]==root)
            break;
    if(temp==ie+1)
    {
        cout<<"Root not found in inorder\n";
        return NULL;
    }
    else
    {
        node* rootNode = newNode(root);
        int val= temp-is+ps;
        rootNode->left=buildTree(ps+1,val,is,temp-1);
        if(val+1<=pe)
            rootNode->right = buildTree(val+1,pe,temp+1,ie);
        return rootNode;
    }
}

void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void print(node* root)
{
    cout<<"Inorder of constructed tree:\n";
    inorder(root);
    cout<<"\n";
    cout<<"Preorder of constructed tree:\n";
    preorder(root);
    cout<<"\n";
}
int main()
{
    int n;
    in= {'D', 'B', 'E', 'A', 'F', 'C'};
    pre= {'A', 'B', 'D', 'E', 'C', 'F'};
    n=in.size();
    node* root = buildTree(0,n-1,0,n-1);
    print(root);
    return 0;
}
