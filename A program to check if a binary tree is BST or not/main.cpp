#include <bits/stdc++.h>
using namespace std;
// Initial value of previous element
int previ=INT_MIN;
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

// do an inorder traversal and resulting numbers should come in ascending order
// Instead of storing the full array ,we can keep track of previous element and
// check new element is greater than prev and update this prev variable.

// It checks for strict ascending order , no repetition is allowed
bool checkBst(node* root)
{
    bool a,b;
    if(!root)
        return true;

    a = checkBst(root->left);
    if(root->data  >  previ)
        previ=root->data;
    else
        return false;
    if(a)
        b = checkBst(root->right);
    return a&&b;
}
void insertBST(node* &root,int data)
{
    if(root==NULL)
    {
        root=newNode(data);
        return ;
    }
    if(root->data > data)
        insertBST(root->left,data);
    else
        insertBST(root->right,data);
}
int main()
{
    struct node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);

    /*
                      3
                2          5
            1      4
    */
    if(checkBst(root))
        cout<<"Is a BST\n";
    else
        cout<<"Is not a BST\n";
    return 0;
}
