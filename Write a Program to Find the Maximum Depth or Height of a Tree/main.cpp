#include <iostream>

using namespace std;
struct node
{
    int data;
    node * left;
    node * right;
};
node* newNode(int data)
{
    node * temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int depth(node * root)
{
    if(!root)
        return 0;
    return max(depth(root->left),depth(root->right))+1;
}
int main()
{
         /*
    * Constructed binary tree is
            1
          /   \
        2      3
      /  \    / \
    4     5  8   9
           \
            6
             \
              7
  */
      node *root = newNode(1);
      root->left        = newNode(2);
      root->right       = newNode(3);
      root->right->left = newNode(8);
      root->right->right= newNode(9);
      root->left->left  = newNode(4);
      root->left->right = newNode(5);
      root->left->right->right = newNode(6);
      root->left->right->right->right=newNode(7);

      cout<<"Depth:"<<depth(root);
    return 0;
}
