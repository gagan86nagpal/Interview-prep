#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node* getNode(int data=0)
{
    node* temp = new node();
    temp->data=data;
    temp->right=temp->left=NULL;
    return temp;
}

void spiral(node* root)
{
    stack < node* > l,r;
    l.push(root);
    while(!l.empty() || !r.empty())
    {
        while(!l.empty())
        {
            node* temp   = l.top();
            cout<<temp->data<<" ";
            l.pop();
            if(temp->left)
                r.push(temp->left);
            if(temp->right)
                r.push(temp->right);
        }
        while(!r.empty())
        {
            node* temp   = r.top();
            cout<<temp->data<<" ";
            r.pop();
            if(temp->right)
                l.push(temp->right);
            if(temp->left)
                l.push(temp->left);
        }
    }
    cout<<"\n";
}
int main()
{
    node* root=getNode(1);
    root->left=getNode(2);
    root->right=getNode(3);
    root->left->right=getNode(5);
    root->left->left=getNode(4);
    root->right->left=getNode(6);
    root->right->right=getNode(7);
    root->left->left->left=getNode(8);
    root->left->left->right=getNode(9);
    root->left->right->left=getNode(10);
    root->left->right->right=getNode(11);
    root->right->left->left=getNode(12);
    root->right->left->right=getNode(13);
    root->right->right->left=getNode(14);
    root->right->right->right=getNode(15);
    spiral(root);
    return 0;
}
