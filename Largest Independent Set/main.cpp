#include <iostream>
#include <map>
using namespace std;



struct node
{
    int data;
    node* left;
    node* right;
};

map <node*,int > dp;
node* getNode(int data)
{
    node* temp = new node();
    temp->left=temp->right=NULL;
    temp->data=data;
    return temp;
}

int largestIndependentSet(node* root)
{
    if(root==NULL)
        return 0;

    if(dp.find(root)!=dp.end()) // found
        return dp[root];
    // without taking root
    int sub_Problem1 = largestIndependentSet(root->left) + largestIndependentSet(root->right);

    // with root
    int l=0,r=0;
    if(root->left)
        l= largestIndependentSet(root->left->left) + largestIndependentSet(root->left->right);
    if(root->right)
         r= largestIndependentSet(root->right->left) + largestIndependentSet(root->right->right);
    int sub_Problem2= 1+l+r;

    return dp[root]=max(sub_Problem1,sub_Problem2);

}

void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node* root;
    root=getNode(10);
    root->left=getNode(20);
    root->left->left=getNode(40);
    root->left->right=getNode(50);
    root->left->right->left=getNode(70);
    root->left->right->right=getNode(80);
    root->right=getNode(30);
    root->right->right=getNode(60);

    int length = largestIndependentSet(root);
    cout<<length<<"\n";
    return 0;
}
