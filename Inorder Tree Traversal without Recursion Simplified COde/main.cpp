#include <iostream>
#include <stack>
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


void inorder(node* root)  // left,root,right
{
    cout<<"Inorder Traversal:";
    stack <node*> st;
    st.push(root);
    while(!st.empty())
    {
        // Keep on going to the left child
        if(root!=NULL)
        {
            st.push(root->left);
            root=root->left;
        }
        else // If no left child , then print the node , keep on going to the right child
        {
            // No left child , pop parent and print it
            st.pop();  // This is always null, as we are pushing it , so the first time , it is always null here
            if(!st.empty())
            {
                root=st.top();
                cout<<root->data<<" ";
                st.pop();
                st.push(root->right);
                root=root->right;
            }
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
