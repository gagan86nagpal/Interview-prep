#include <iostream>
#include <vector>
using namespace std;
vector < int> freq;
struct node
{
    int data;
    node *left,*right;
};
node* getNewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void buildVector(node * root,int level)
{
    if(root==NULL)
        return ;
    if(freq.size()==level)
        freq.push_back(0);
    freq[level]++;
    buildVector(root->left,level+1);
    buildVector(root->right,level+1);
}
int getMaximumWidth(node * root)
{
    buildVector(root,0);
    int i;
    int ret=0;
    for(i=0;i<freq.size();i++)
    {
        if(freq[i]>ret)
            ret=freq[i];
    }
    return ret;
}
void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=NULL;
    root=getNewNode(1);
    root->left=getNewNode(2);
    root->left->left=getNewNode(3);
    root->left->left->left=getNewNode(5);
    root->left->left->left->left=getNewNode(7);
    root->left->left->left->right=getNewNode(8);

    root->left->right=getNewNode(4);
    root->left->right->right=getNewNode(6);
    root->left->right->right->left=getNewNode(9);
    root->left->right->right->right=getNewNode(10);
    cout<<"inorder:";
    inorder(root);
    cout<<"\n";
    cout<<"Maximum Width:"<<getMaximumWidth(root)<<"\n";
    return 0;
}
