#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left,*right;
};
node* getNewNode(int data)
{
    node * temp = new node();
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
// isrecurse is 1 initially
void printAncestors(node* root,int data,int &isrecurse)
{
    if(root==NULL)
        return ;
    if(root->data==data) // if we have reached the node with given data , stop recursion
    {
        isrecurse=0;
        return;
    }
    if(isrecurse==1)
        printAncestors(root->left,data,isrecurse);
    if(isrecurse==1)
        printAncestors(root->right,data,isrecurse);
    if(isrecurse==0)    // Print all the elements in the stack as ancestors
        cout<<root->data<<" ";
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


    int ele=10;
    int isrecurse=1;
    cout<<"Ancestors of "<<ele<<" are:";
    printAncestors(root,ele,isrecurse);
    cout<<"\n";
    return 0;
}
