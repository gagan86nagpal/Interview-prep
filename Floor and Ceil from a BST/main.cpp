#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left,*right;
};


// Following the correct path in BST can easily yield floor and ceil
node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* fl=NULL;  // floor
node* ce=NULL;  //  ceil
void floor(node * root,int key) // it assigns floor to the variable fl
{
    if(root==NULL)
        return;
    if(root->data==key)
    {
        fl=root;
        return ;
    }
    if(root->data < key)
    {
        fl=root;
        floor(root->right,key);
    }
    else
        floor(root->left,key);
}
void ceil(node * root,int key) // it assigns ceil to variable ce
{
    if(root==NULL)
        return ;
    if(root->data==key)
    {
        ce=root;
        return ;
    }
    if(root->data > key)
    {
        ce=root;
        ceil(root->left,key);
    }
    else
        ceil(root->right,key);
}
node* getFloor(node* root,int key)
{
    floor(root,key);
    return fl;
}
node* getCeil(node* root,int key)
{
    ceil(root,key);
    return ce;
}
int main()
{
     /*   6
        /  \
       2    10
      / \   / \
     1   3 7  12
    */

    struct node *root = newNode(6);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
    inorder(root);

    int key=8;
    cout<<"\nFloor of key= "<<key<<" is "<<getFloor(root,key)->data<<"\n";
    cout<<"Ceil of key= "<<key<<" is "<<getCeil(root,key)->data<<"\n";
    return 0;
}
