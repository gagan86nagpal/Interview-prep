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

// Idea is to explore left child left first  and pushing into stack also
// THen before exploring right child, we have to pop the root always
// Now , keep on popping root , if there is no right child,
// if there is a right child , then push it into stack and visit its subtree
void inorder(node* root)  // left,root,right
{
    stack <node*> st;
    st.push(root);
    node * top;
     while(!st.empty())
    {
        top=st.top();
        if(top->left)  // keep on pushing left child
            st.push(top->left);
        else
        {

            cout<<top->data<<" ";   // now this node's left child has been explored , so print it
            st.pop();               // pop the root before exploring its right chuld
            if(top->right )         // if it has right child , then visit it's subtree by starting the lopp
                st.push(top->right);
            else                    // if no right child
            {
                if(!st.empty())
                    top=st.top();
                while(!st.empty()&&top->right==NULL)  // then keep on popping till there is no right child or stack is empty
                {
                    cout<<top->data<<" ";
                    st.pop();
                    top=st.top();
                }
                if(top->right)   // while popping , if you find a node having right child, then push and visit its subtree
                {
                    cout<<top->data<<" ";
                    st.pop();       // remember , before visiting a right child , we have to pop it's root always
                    st.push(top->right);
                }
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
