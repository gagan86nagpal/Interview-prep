#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;
    node * left;
    node* right;
    int height;
};

void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->data<<","<<root->height<<"   ";
    inorder(root->right);
}
node* getNode(int data)
{
    node* temp = new node;
    temp->height=0;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

node* leftRotate(node* root)
{
    node* new_root = root->left;
    root->left=new_root->right;
    new_root->right=root;
    root->height-=1;
    if(!new_root->left)
        new_root->height++;
    return new_root;
}

node* rightRotate(node* root)
{
    node* new_root = root->right;
    root->right=new_root->left;
    new_root->left=root;
    root->height-=1;
    if(!new_root->right)
        new_root->height++;
    return new_root;
}
node* insertAvl(node* root,int data)
{
    if(root==NULL)
        return getNode(data);
    if(root->data > data)
        root->left = insertAvl(root->left,data);
    else
        root->right = insertAvl(root->right,data);

    int h_left=-1,h_right=-1;
    if(root->left)
        h_left=root->left->height;
    if(root->right)
        h_right=root->right->height;
    int d = abs(h_left-h_right);

    node* ret=root;
    if(d>=2) // rotatition is required
    {
        if(h_left > h_right)
        {
            int l=-1,r=-1;
            if(root->left->left)
                l=root->left->left->height;
            if(root->left->right)
                r=root->left->right->height;

            if(l>r) // ll
            {
                cout<<"LL\n";
                ret =leftRotate(root);
            }
            else // lr
            {
                cout<<"LR\n";
                root->left=rightRotate(root->left);
                ret=leftRotate(root);
            }
        }
        else
        {
            int l=-1,r=-1;
            if(root->right->left)
                l=root->right->left->height;
            if(root->right->right)
                r=root->right->right->height;

            if(r>l) // rr
            {
                cout<<"RR\n";
                ret=rightRotate(root);
            }
            else // rl
            {
                cout<<"RL\n";
                root->right=leftRotate(root->right);
                ret=rightRotate(root);
            }
        }
    }
    else
        root->height= 1+max(h_left,h_right);
    return ret;
}
int main()
{
    int ch;
    node* root=NULL;
    do
    {
        cout<<"1. Insertion\n2. Inorder Traversal\n3. Exit\n";
        cin>>ch;
        if(ch==1)
        {

            int data;
            cout<<"Enter data ";
            cin>>data;
            root=insertAvl(root,data);
        }
        else if(ch==2)
            cout<<"Inorder:",inorder(root),cout<<"\n";


    }while(ch!=3);
    return 0;
}
