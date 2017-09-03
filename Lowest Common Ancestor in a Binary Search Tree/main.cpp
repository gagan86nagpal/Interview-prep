#include <iostream>
#include <stdio.h>
using namespace std;
/*
Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA).
You may assume that both the values exist in the tree.
*/
struct node
{
    int data;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* lca(node* root,int a,int b)
{
    node* ret=root;
    while(root!=NULL)
    {
        if((root->data >a )&& (root->data >b) )
        {
            root=root->left;
            ret=root;
        }
        else if( (root->data <a) && (root->data<b ))
        {
            root=root->right;
            ret=root;
        }
        else
            break;
    }
    return ret;
}
int main()
{

    /*
                      20
             8                22
       4         12
               10  14
    */
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}
