#include <iostream>
#include <stack>
using namespace std;
// Idea is to do a inorder and reverse inorder traversals using stacks
// Now , initialize two pointers at the inorder and other at reverse inorder.
// If sum , is greater than sum of pointers , fetch next element in reverse inorder
// If sum is less , then fetch the next element in inorder
// Else found

// Since , we are using stacks to do an inorder and reverse inorder and Tree is balanced , so
// Space is O(logn)
// TIme is O(n) and space is O(logn)


// This may not work , if tree has duplicates!!
struct node
{
    int data;
    node* left,*right;
};
node* NewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
bool isPairExists(node* root,int target)
{
    int sum;
    stack < node* > st1,st2;
    node* top1,*top2;
    st1.push(root); // inorder
    st2.push(root);// reverse inorder
    while(!st1.empty() || !st2.empty())
    {
        top1=st1.top();
        top2=st2.top();
        if(top1!=NULL)
        {
            st1.push(top1->left);
            continue;
        }
        if(top2!=NULL)
        {
            st2.push(top2->right);
            continue;
        }

        else  // Both the stacks have an element
        {
            st1.pop(); // remove NULL
            st2.pop(); // remove NULL
            top1=st1.top(); // get the parent
            top2=st2.top(); // get the parent
            sum=top1->data + top2->data;
            if(top1->data!=top2->data &&sum == target)
            {
                cout<<"Pair Found"<<top1->data<<" , "<<top2->data<<"\n";
                return true;
            }
            else if(sum > target) // fetch next in reverse inorder
            {
                st2.pop();// remove the parent
                st2.push(top2->left); // push left subtree
                // make the stack 1 back to it's initial state
                st1.push(NULL);
            }
            else
            {
                st1.pop();
                st1.push(top1->right); // push right subtree
                // make the stack 2 back to it's initial state
                st2.push(NULL);
            }
            if(top1->data > top2->data) // we have crossed the pointers
            {
                cout<<"Pair doesn't exists\n";
                return false;
            }
        }
    }
    cout<<"Pair doesn't exists\n";
    return false;
}

int main()
{
   /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    struct node *root =  NewNode(15);
    root->left = NewNode(10);
    root->right = NewNode(20);
    root->left->left = NewNode(8);
    root->left->right = NewNode(12);
    root->right->left = NewNode(16);
    root->right->right = NewNode(25);

    int target = 20;
    cout<<isPairExists(root,target)<<"\n";

    target=22;
    cout<<isPairExists(root,target)<<"\n";

    return 0;
}
