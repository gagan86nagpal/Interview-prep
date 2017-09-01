#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node* getNewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void kDistanceNodes(node* root,int dist,int k)
{
    if(root==NULL)
        return;
    if(dist==k)
    {
        cout<<root->data<<" ";
        return;
    }
    kDistanceNodes(root->left,dist+1,k);
    kDistanceNodes(root->right,dist+1,k);
}
void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=NULL;
    root=getNewNode(1);
    root->left=getNewNode(2);
    root->left->left=getNewNode(3);
    root->left->left->left=getNewNode(5);
    root->left->left->left->left=getNewNode(7);
    root->left->left->left->right=getNewNode(8);

    root->left->right=getNewNode(4);
    root->left->right->right=getNewNode(6);
    root->left->right->right->left=getNewNode(9);
    root->left->right->right->right=getNewNode(10);
    cout<<"Inorder Traversal of the tree is:";
    inorder(root);
    cout<<"\n";
    int k=4;
    cout<<"At distance k="<<k<<" from root,Nodes are:";
    kDistanceNodes(root,0,k);
    cout<<"\n";
    return 0;
}
