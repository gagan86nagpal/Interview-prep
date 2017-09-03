#include <iostream>
#include <stack>
using namespace std;
/*
Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form.
The expected time complexity is O(m+n) where m is the number of nodes in first tree and n is the number of nodes in second tree.
Maximum allowed auxiliary space is O(height of the first tree + height of the second tree).
*/
int a1,a2;
struct node
{
    int data;
    node* left;
    node* right;
};

// This template of iterative inorder traversal has been used
// Idea is to keep pushing the left child
// If root is null , then pop  , print the top and pop it again , push the recently popped element's right child

void inorder(node* root)
{
    stack < node*> st;
    st.push(root);
    cout<<"Inorder:";
    while(!st.empty())
    {
        node* temp = st.top();
        if(temp)
        {
            st.push(temp->left);
        }
        else
        {
            st.pop();  // remove NULL
            if(st.empty())
                break;
            temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            st.push(temp->right);
        }
    }
    cout<<"\n";
}

// Here breaking the different states of stack we can think of it as a finite automata
// Now ,After some operations we are altering the state and sometimes we have to go back to previous state
void mergeTwoBsts(node* root1,node* root2)
{
    cout<<"Merged BSTs:";
    stack<node*> st1,st2;
    st1.push(root1);
    st2.push(root2);
    while(!st1.empty() || !st2.empty())
    {
        node * temp1 = st1.top();
        node* temp2  = st2.top();
        if(temp1)
        {
            st1.push(temp1->left);
            continue;
        }
        if(temp2)
        {
            st2.push(temp2->left);
            continue;
        }

        // NULL should be on top of both the stacks
        // We remove the NULL here.
        st1.pop(); // remove NULL
        st2.pop();// remove NULL
        if(st1.empty()&&st2.empty())
            break;
        if(st1.empty())
        {
            cout<<st2.top()->data<<" ";
            st1.push(NULL); // undo the effect
            temp2 = st2.top();
            st2.pop();
            st2.push(temp2->right);
            continue;
        }
        if(st2.empty())
        {
            cout<<st1.top()->data<<" ";
            st2.push(NULL); // undo the effect
            temp1= st1.top();
            st1.pop();
            st1.push(temp1->right);
            continue;
        }
        if(st1.empty()==false && st2.empty()==false)
        {
            temp1=st1.top();
            temp2=st2.top();
            if(temp1->data > temp2->data)
            {
                cout<<temp2->data<<" ";
                st2.pop();
                st2.push(temp2->right);
                st1.push(NULL); // undo the effect
            }
            else
            {
                cout<<temp1->data<<" ";
                st1.pop();
                st1.push(temp1->right);
                st2.push(NULL); // undo the effect;
            }
        }
    }
}
node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main()
{
    node *root1               = newNode(20);
    root1->left               = newNode(8);
    root1->right              = newNode(22);
     root1->left->left         = newNode(4);
    root1->left->right        = newNode(12);
    root1->left->right->left  = newNode(9);
    root1->left->right->right = newNode(14);

    node *root2               = newNode(50);
    root2->left               = newNode(10);
    root2->right              = newNode(75);
    root2->left->left         = newNode(5);
    root2->left->right        = newNode(15);
    root2->left->right->left  = newNode(11);
    root2->left->right->right = newNode(16);
    inorder(root1);
    inorder(root2);
    mergeTwoBsts(root1,root2);
    return 0;
}
