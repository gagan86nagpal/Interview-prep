#include <iostream>
#include <stack>
#include <set>
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

// using a set to mark visited nodes as to not visit them again
// inorder can also be achieved without using a visited set
// if loop constructs are designed properly
void inorder(node* root)  // left,root,right
{
    set< node *>vis;
    stack <node*> st;
    st.push(root);
    node * top;
    while(!st.empty())
    {
        top=st.top();
        if(top->left  && vis.find(top->left)==vis.end())
            st.push(top->left);
        else  // this node doesn't has a left child , we should print it
        {
            // if there is no right node , or if there is but it is not yet visited , then print it
            if((top->right==NULL || vis.find(top->right)==vis.end()))
                cout<<top->data<<" ";
            if(top->right && vis.find(top->right)==vis.end())  // but it has right child so explore right child
                st.push(top->right);
            else
            {
                vis.insert(top);
                st.pop();
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
  cout<<"inorder: ";
  inorder(root);

    return 0;
}
