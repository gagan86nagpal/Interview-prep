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
// double pointer as we will be using it in deleteBST function
node** getMinimum(node* &root)
{
    if(root->left)
        return getMinimum(root->left);
    return &root;
}
// Usage of pointers at extreme
void deleteBST(node* &root,int data)
{
    if(root==NULL)
    {
        cout<<"Key="<<data<< " not found\n";
        return;
    }
    if(root->data==data)
    {
        cout<<"Deleting "<<data<<"\n";
        if(root->left ==NULL&&root->right==NULL) // both are empty
        {
            node* temp = root;
            delete temp;
            root=NULL;
        }
        else if(root->left==NULL) // It has only right child
        {
            cout<<"Only right \n";
            node* temp = root;
            root=root->right;
            delete temp;
        }
        else if (root->right==NULL)  // It has only left child
        {
            node* temp = root;
            root=root->left;
            delete temp;
        }
        else   // it has both children
        {
            node** getMi=getMinimum(root->right);
            root->data = (*getMi)->data;
            node * temp = *getMi;     // we need to convert it into single pointer as to delete it.
            (*getMi) =(*getMi)->right;  // we have used double pointer only because of this step
            delete temp;
        }
        return;
    }
    if(root->data<data)
        deleteBST(root->right,data);
    else
        deleteBST(root->left,data);
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
    insertBST(root,3);
    insertBST(root,7);
    insertBST(root,4);
    insertBST(root,6);
    insertBST(root,1);
    insertBST(root,0);
    insertBST(root,2);
    insertBST(root,5);
    print(root);
    if(temp=searchBST(root,2))
        cout<<"found:"<<temp->data<<"\n";
    else
        cout<<"Not Found\n";

   // insertBST(root,4);
    print(root);
    deleteBST(root,20);
    print(root);
    return 0;
}
