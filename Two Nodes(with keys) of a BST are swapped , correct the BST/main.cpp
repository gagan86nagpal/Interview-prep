#include <iostream>

using namespace std;


/*
Two Nodes with data are swapped only , their subtrees are not swapped.
So , we will save the two adjacent nodes where inorder traversal is not giving ascending order
These will be the answer if in Original BST two adjacent nodes were swapped.
For another case , we will find another violation in inorder and answer would be
left node in first violation and second in second violation.
*/
struct node
{
    int data;
    node* left,*right;
};
int cnt=0;          // cnt get incremented on every violation of inorder traversal
node* prevNode=NULL;  // It stores the previous Node to root in inorder traversal
node* first=NULL,*second=NULL;  // these will store the our final two nodes to be swapped

node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
// should be called by swapTwoNodes
void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);

    if( prevNode && (root->data )< (prevNode->data)&& cnt==0) // first time violation happened
    {
        first=prevNode;
        second=root;
        cnt++;
    }
    else if(prevNode && (root->data) < (prevNode->data)  && cnt==1) // second time violation happened
    {
        second = root;                                  // since first is pointing to left node in first violation , we will change
                                                        // second to right node in second violation
    }
    prevNode=root;
    inorder(root->right);
}

void swapTwoNodes(node* root)
{
    inorder(root);
    cout<<"\n"<<first->data<<" and "<<second->data<<" are swapped\n";
    // swapping of data
    int temp = first->data;
    first->data=second->data;
    second->data=temp;

}

// prints inorder of tree
void print(node* root)
{
    if(!root)
        return ;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
     /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);

    print(root);
    swapTwoNodes(root);
    print(root);

    return 0;
}
