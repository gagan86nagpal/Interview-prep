#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left,*right,*random;
};
node* newNode(int data)
{
    node* temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->random=NULL;
    return temp;
}
// modify the original tree by inserting an intermediate node at the left child of the original node
node* modify(node* root)
{
    if(root==NULL)
        return NULL;
    node* temp = root->left;
    root->left = newNode(root->data);
    root->left->left=temp;
    root->left->right=modify(root->right);
    modify(temp);
    return root->left;
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
// Checking whether two trees are equal or not by displaying every links.
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
// After modifying the tree , we are here copying the random links
void copyRandom(node * root)
{
    if(root==NULL)
        return ;
    if(root->random)
        root->left->random = root->random->left;
    else
        root->left->random = NULL;
    copyRandom(root->left->left);
    copyRandom(root->right);
}
// After copying the random Links , we have to retrieve our original tree and also the cloned tree
// This returns the root pointer of cloned tree
node* demodify(node* root)
{
    if(root==NULL)
        return NULL;
    node* cnode = root->left;
    node* rn=cnode->left;
    node * cn = NULL;
    if(rn)
        cn = rn->left;
    root->left=rn;
    cnode->left=cn;
    demodify(rn);
    demodify(root->right);
    return cnode;
}
// It calls the procedure in the right order
node * clone(node* root)
{
    modify(root);
    copyRandom(root);
    return demodify(root);
}
int main()
{
    node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;


    tree->left->right->random = tree->right;
    node* cloned = clone(tree);
    print(tree,cloned);
    return 0;

}
