#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node * getNewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
class Queue
{
private:
    static const int capacity=100;
    int r=-1;
    int f=-1;
    node* a[capacity];  // Queue will store pointer to actual Tree nodes
public:
    node* rear()
    {
        if(r!=-1)
            return a[r];
        else
            cout<<"Queue is Empty\n";
        return NULL;
    }
    bool isEmpty()
    {
        return r==-1;
    }
    node* front()
    {
        if(f!=-1)
            return a[f];
        else
            cout<<"Queue is Empty\n";
        return NULL;
    }
    void enqueue(node* x)
    {
        if(f==r+1 ||(f==0 && r==capacity-1) )
            cout<<"Queue is full\n";
        else
        {
            r++;
            if(r==capacity)
                r=0;
            a[r]=x;
            if(f==-1)
                f=0;
        }
    }
    node* dequeue()
    {
        if(f==r&&f==-1)
            cout<<"Queue is empty\n";
        node* ret;
        ret=a[f];
        if(f==r)
        {
            f=-1;
            r=-1;
            return ret;
        }
        f++;
        if(f==capacity)
            f=0;
        return ret;
    }
    void print()
    {
        cout<<"front:"<<f<<", rear:"<<r<<"\n";
        if(f==r &&(f==-1 ) )
        {
            cout<<"Queue is empty";
        }
        else
        {
            int temp=f;
            while(temp!=r)
            {
                cout<<a[temp]<<" ";
                temp++;
                if(temp==capacity)
                    temp=0;
            }
            cout<<a[temp]<<" ";
        }
        cout<<"\n";
    }
};

void levelOrderTraversal(node* root)
{
    Queue q;
    cout<<"Level Order Traversal: ";
    if(root)
    q.enqueue(root);
    while(!q.isEmpty())
    {
        node* temp = q.dequeue();
        cout<<temp->data<<" ";
        if(temp->left)
            q.enqueue(temp->left);
        if(temp->right)
            q.enqueue(temp->right);
    }
}
int main()
{
    node * root = getNewNode(1);
     root->left             = getNewNode(2);
     root->right           = getNewNode(3);
     root->left->left     = getNewNode(4);
     root->left->right   = getNewNode(5);
     levelOrderTraversal(root);
    return 0;
}
