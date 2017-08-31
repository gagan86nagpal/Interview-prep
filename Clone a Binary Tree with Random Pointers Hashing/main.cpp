#include <iostream>
#include <map>
using namespace std;
struct node
{
    int data;
    node* left,*right,*random;
};

map <node*, node* > m;
node* newNode(int data)
{
    node* temp = new node();
    temp->data= data;
    temp->left=NULL;
    temp->right=NULL;
    temp->random=NULL;
    return temp;
}
node* cloneLR(node* root)
{
    if(root==NULL)
        return NULL;
    node* temp = newNode(root->data);
    m[root]=temp;
    temp->left=cloneLR(root->left);
    temp->right=cloneLR(root->right);
    return temp;
}
void cloneRandom(node* root,node* cloned)
{
    if(root==NULL)
        return;
    cloned->random=m[root->random];
    cloneRandom(root->left,cloned->left);
    cloneRandom(root->right,cloned->right);
}
void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<"-";
    if(root->random)
        cout<<root->random->data<<"\t";
    else
        cout<<"NULL\t";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"-";
     if(root->random)
        cout<<root->random->data<<"\t";
    else
        cout<<"NULL\t";
    preorder(root->left);
    preorder(root->right);
}
void print(node * root, node* cloned)
{
    cout<<"preorder root: ";
    preorder(root);
    cout<<"\n";
    cout<<"preorder clone:";
    preorder(cloned);
    cout<<"\n";
    cout<<"inorder root: ";
    inorder(root);
    cout<<"\n";
    cout<<"inorder clone:";
    inorder(cloned);
    cout<<"\n";
}
int main()
{
    m[NULL]=NULL;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->random = root->left->right;
    root->left->left->random = root;
    root->left->right->random = root->right;

    node* cloned = cloneLR(root);

    cloneRandom(root,cloned);
    print(root,cloned);


    return 0;
}
