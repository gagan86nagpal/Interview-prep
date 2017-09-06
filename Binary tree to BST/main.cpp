#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
    int data;
    node* left,*right;
};
node* newNode(int data)
{
    node* temp  = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
vector <int> sorted;
int pos=0;
// op=1, traverse binary tree and store inorder in sorted vector
// op = 2, trverse binary tree and push sorted values from vector
// op=3, is to print the inorder traversal
void inorder(node* root , int op)
{
    if(!root)
        return ;
    inorder(root->left,op);
    if(op==1)
        sorted.push_back(root->data);
    if(op==2)
        root->data=sorted[pos++];
    if(op==3)
        cout<<root->data<<" ";
    inorder(root->right,op);
}
void binaryToBst(node* root)
{
    cout<<"Original tree:";
    inorder(root,3);
    inorder(root,1);// initialize the sorted array
    sort(sorted.begin(),sorted.end());
    inorder(root,2); // Change into bst
    cout<<"\nBinary Search tree:";
    inorder(root,3); // print inorder of BST
    cout<<"\n";
}
int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    binaryToBst(root);
    // root now points to a BST
    return 0;
}
