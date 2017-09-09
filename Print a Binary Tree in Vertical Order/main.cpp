#include <iostream>
#include <vector>
using namespace std;
vector <int> v[10]; // maximum width of binary tree
// Also can use a array of linked list
// In vertical order , root, left,right
struct node
{
    int data;
    node* left,*right;
};
node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    return temp;
}
int adjust=0;
int maxIndent=-1;
void setAdjust(node* root)
{
    if(root->left)
    {
        adjust++;
        setAdjust(root->left);
    }
}
void preoder(node* root,int indent)
{
    if(!root)
        return;
    if(indent+adjust > maxIndent)
        maxIndent=indent+adjust;
    v[indent+adjust].push_back(root->data);
    preoder(root->left,indent-1);
    preoder(root->right,indent+1);
}
void printVerticalOrder(node* root)
{
    setAdjust(root);
    preoder(root,0);
    int i;
    for(i=0;i<=maxIndent;i++)
    {
        for(auto x : v[i])
            cout<<x<<" ";
        cout<<"\n";
    }
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
