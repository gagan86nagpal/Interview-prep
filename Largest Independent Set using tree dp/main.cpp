#include <iostream>
#include <map>
using namespace std;



struct node
{
    int data;
    node* left;
    node* right;
};

node* getNode(int data)
{
    node* temp = new node();
    temp->left=temp->right=NULL;
    temp->data=data;
    return temp;
}

int largestIndependentSet(node* root,node* dp)
{
    if(root==NULL)
        return 0;

    if(dp->data!=-1) // found
        return dp->data;
    // without taking root
    int sub_Problem1 = largestIndependentSet(root->left,dp->left) + largestIndependentSet(root->right,dp->right);

    // with root
    int l=0,r=0;
    if(root->left)
        l= largestIndependentSet(root->left->left,dp->left->left) + largestIndependentSet(root->left->right,dp->left->right);
    if(root->right)
        r= largestIndependentSet(root->right->left,dp->right->left) + largestIndependentSet(root->right->right,dp->right->right);
    int sub_Problem2= 1+l+r;

    return  dp->data=max(sub_Problem1,sub_Problem2);
}

node* inorder(node* root,node* dp) // initialize dp tree having same structure as initial binary tree
{
    if(!root)
        return NULL;
    if(!dp)
        dp=getNode(-1);
   dp->left= inorder(root->left,dp->left);
    dp->right=inorder(root->right,dp->right);
    return dp;
}
int main()
{
    node* root;
    node* dp=NULL;
    root=getNode(10);
    root->left=getNode(20);
    root->left->left=getNode(40);
    root->left->right=getNode(50);
    root->left->right->left=getNode(70);
    root->left->right->right=getNode(80);
    root->right=getNode(30);
    root->right->right=getNode(60);
    dp=inorder(root,dp);
    int length = largestIndependentSet(root,dp);
    cout<<length<<"\n";
    return 0;
}
