/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree.
*/
#include <iostream>
#include <utility>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node * newNode(int data)
{
    node * temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right =NULL;
    return temp;
}
// it returns, (diameter ,height of the subtree at root)
// Height is required to calculate the diameter in some cases
pair <int,int> diameterOfBinaryTree(node* root)
{
    if(root==NULL) // NUll node
        return make_pair(0,0); // height and diameter of empty root is 0
    pair <int,int> l,r;
    l= diameterOfBinaryTree(root->left);
    r= diameterOfBinaryTree(root->right);
    int height = max(l.second,r.second)+1;
    int diameter = max(l.first,max(r.first,l.second+r.second+1));
    return make_pair(diameter,height);
}
int main()
{

    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout<<"Diameter of given tree:"<<diameterOfBinaryTree(root).first<<"\n";
    cout<<"Height of given tree:"<<diameterOfBinaryTree(root).second<<"\n";

    return 0;
}
