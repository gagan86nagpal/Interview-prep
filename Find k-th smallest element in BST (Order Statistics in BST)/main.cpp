#include <iostream>

using namespace std;
struct node
{
    int data;
    int cnt;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->cnt=1;
    temp->right=NULL;
    return temp;
}
int buildCntOfBst(node* root)
{
    if(!root)
        return 0;
    int l= buildCntOfBst(root->left);
    int r= buildCntOfBst(root->right);
    root->cnt=l+r+1;
    return root->cnt;
}
void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node*  kOrderStatistics(node* root,int k)
{
    if(k>root->cnt)
        return NULL;

        // if current root is the answer
        // Either it left child is empty and k=1 OR number of nodes in left child is k-1
    if( (root->left==NULL && k==1 )|| (k-1==root->left->cnt) )
        return root;
        // if k is less than number of nodes in left child, then look in it
    else if(k <= root->left->cnt)
        return kOrderStatistics(root->left,k);
        // if number of nodes are less than k , then look for k -(nodes in left child -1) in right subtree
    else
        return kOrderStatistics(root->right,k - root->left->cnt-1);
}
int main()
{
    node *root               = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int i;
    buildCntOfBst(root);
   // cout<<kOrderStatistics(root,1)->data<<"\n";
    for(i=1;i<=root->cnt ;i++)
    {
        cout<<i<<" smallest element:"<<kOrderStatistics(root,i)->data<<"\n";
    }
    cout<<"Inorder: ";
    inorder(root);
    return 0;
}
