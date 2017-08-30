#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node *temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(node * root)
{
    cout<<"inorder:";
    node * current = root;
    while(current)
    {
        if(current->left)
        {
            node * ip = current->left;
            while(ip->right!=NULL && ip->right!=current)
            {
                ip=ip->right;
            }
            if(ip->right==NULL)
            {
                ip->right=current;  // making a link
                current=current->left;
            }
            else
            {
                ip->right=NULL;
                cout<<current->data<< " ";
                current=current->right;
            }

        }
        else
        {
            cout<<current->data<<" ";
            current=current->right;
        }
    }
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
      inorder(root);
    return 0;
}
