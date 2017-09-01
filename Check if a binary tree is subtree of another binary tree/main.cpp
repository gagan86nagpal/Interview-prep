#include <iostream>

using namespace std;
// brute force
// for every node as a root, check if this tree exists in other binary tree or not
struct node
{
    int data;
    node *left,*right;
};
node* getNewNode(int data)
{
    node* temp  = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

// checks from root , and returns true if they match
bool subpart(node * big,node* small)
{
    if(small==NULL)
        return true;
    if(big==NULL)
        return false;
    if(small->data!=big->data)
        return false;
    return subpart(big->left,small->left) && subpart(big->right,small->right);
}


// returns True if small is a subtree of big , else false
bool subtree(node* big,node* small)
{
    if(big==NULL)
        return false;
    if(subpart(big,small))
        return true;
    return subtree(big->left,small)||subtree(big->right,small);
}
int main()
{

    /*
                1
              2
            3   4
          5       6
        7   8    9  8

    */
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

    /*
             2
           3   4
    */
    node * small = NULL;
    small= getNewNode(2);
    small->left=getNewNode(3);
    small->right=getNewNode(4);
    cout<<subtree(root,small);
    return 0;
}
