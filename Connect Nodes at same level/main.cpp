#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node * link; // link to connect to nodes at same level.
    bool isStart;  // if it is the leftmost node at a level in the tree
};
node* getNewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=temp->right=temp->link=NULL;
    temp->isStart=false;
    return temp;
}
void levelOrderTraversal(node* root)
{
    queue < pair<node* , int> > q;
    pair < node*,int> p;
    q.push(make_pair(root,0));
    root->isStart=true;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.first->left)
            q.push(make_pair(p.first->left,p.second+1) );
        if(p.first->right)
            q.push(make_pair(p.first->right,p.second+1) );
        if(!q.empty()&&p.second==q.front().second)// belongs to same level
        {
            p.first->link = q.front().first;
        }
        else if(!q.empty() && q.front().first) // belongs to different levels
        {
            p.first->link=NULL; // last node
            q.front().first->isStart=true;
        }
    }
}
void printList(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->link)
            cout<<" -> ";
        head=head->link;
    }
    cout<<"\n";
}
void printAllLevels(node* root)
{
    if(root==NULL)
        return ;
    if(root->isStart)
    {
        printList(root);
    }
    printAllLevels(root->left);
    printAllLevels(root->right);
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


    levelOrderTraversal(root);
    cout<<"Nodes at different Levels:\n";
    printAllLevels(root);
    return 0;
}
