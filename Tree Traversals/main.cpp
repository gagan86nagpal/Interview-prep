#include <iostream>

using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

node * getNewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(node * root)   // Left , root , right
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node * root)   // root , left, right
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node * root)   //  , left, right,root
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node * root = getNewNode(1);
     root->left             = getNewNode(2);
     root->right           = getNewNode(3);
     root->left->left     = getNewNode(4);
     root->left->right   = getNewNode(5);

     cout<<"PreOrder: ";
     preorder(root);
     cout<<"\n";

    cout<<"inOrder: ";
     inorder(root);
     cout<<"\n";
     cout<<"PostOrder: ";
     postorder(root);
     cout<<"\n";
    return 0;
}
