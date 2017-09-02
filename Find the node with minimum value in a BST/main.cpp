#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* getNewChild(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void print(node* root)
{
    cout<<"Inorder Traversal:";
    inorder(root);
    cout<<"\n";
}
node* searchBST(node* root,int data)
{
    if(root==NULL || root->data==data)
        return root;
    if(root->data<data)
        return searchBST(root->right,data);
    return searchBST(root->left,data);
}
node* getMinimum(node* root)
{
    if(!root)
    {
        cout<<"BST is empty\m";
        return NULL;
    }
    if(root->left)
        return getMinimum(root->left);
    return root;
}
void insertBST(node* &root,int data)
{
    if(root==NULL)
    {
        root=getNewChild(data);
        return ;
    }
    if(root->data > data)
        insertBST(root->left,data);
    else
        insertBST(root->right,data);
}
int main()
{
    node* root=NULL;
    node* temp;
    insertBST(root,20);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,4);
    insertBST(root,6);
    print(root);
    cout<<getMinimum(root)->data<<"\n";
    insertBST(root,1);
     cout<<getMinimum(root)->data<<"\n";
    return 0;
}
