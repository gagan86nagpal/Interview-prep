#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* getNewChild(int data)
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
void print(node* root)
{
    cout<<"Inorder Traversal:";
    inorder(root);
    cout<<"\n";
}

void insertBST(node* &root,int data)
{
    if(root==NULL)
    {
        root=getNewChild(data);
        return ;
    }
    if(root->data > data)
        insertBST(root->left,data);
    else
        insertBST(root->right,data);
}
node* successor(node* root, int key)
{
    node* ret=NULL;
    while(root!=NULL  && root->data !=key)
    {
        if(root->data > key)
        {
            ret=root;
            root=root->left;
        }
        else if(root->data < key)
            root=root->right;
    }
    if(root==NULL)
        return ret;
    // key found;
    if(root->right==NULL)
        return ret;
    root=root->right;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
node* predecessor(node* root,int key)
{
    node* ret=NULL;
    while(root!=NULL  && root->data !=key)
    {
        if(root->data < key)
        {
            ret=root;
            root=root->right;
        }
        else if(root->data > key)
            root=root->left;
    }
    if(root==NULL)
        return ret;
    // key found;
    if(root->left==NULL)
        return ret;
    root=root->left;
    while(root->right!=NULL)
        root=root->right;
    return root;
}
void printPredSucc(node* root,int key)
{
    node* pred =predecessor(root,key);
    node* succ =successor(root,key);
    if(pred)
        cout<<pred->data;
    else
        cout<<"-";
    cout<<" "<<key<<" ";
    if(succ)
        cout<<succ->data;
    else
        cout<<"-\n";

}
int main()
{
    node* root=NULL;
    insertBST(root,20);
    insertBST(root,2);
    insertBST(root,30);
    insertBST(root,7);
    insertBST(root,1);
    insertBST(root,6);
    insertBST(root,8);
    print(root);
    printPredSucc(root,1);
    return 0;
}
