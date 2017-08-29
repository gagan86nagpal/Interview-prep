#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct node
{
    char data;
    vector<node*> child;  // children of a node is vector as we don't the size of the number of children a node has
};
node* newNode(char data)
{
    node * temp=new node();
    temp->child.empty();
    temp->data=data;
    return temp;
}

// returns (diameter,height)
pair <int,int> diameter(node* root)
{
    if(root==NULL)
        return make_pair(0,0);
        // h1 is maximum height among all children
        // h2 is second-maximum height among all children
    int h1=0,h2=0,d=0,i;
    pair <int,int> p;
    for(i=0;i<(int)root->child.size();i++)
    {
        p=diameter(root->child[i]);
        if(p.second>=h1)
        {
            h2=h1;
            h1=p.second;
        }
        else if(p.second>=h2)
        {
            h2=p.second;
        }
        d=max(p.first,d);
    }
    return make_pair(max(d,h1+h2+1),h1+1);
}
int main()
{
    /*   Let us create below tree
    *             A
    *         / /  \  \
    *       B  F   D    E
    *      / \     |   /|\
    *     K  J     G  C H I
    *    /\               \
    *   N  M               L
    */

    node *root = newNode('A');
    (root->child).push_back(newNode('B'));

    (root->child).push_back(newNode('F'));
    (root->child).push_back(newNode('D'));
    (root->child).push_back(newNode('E'));
    (root->child[0]->child).push_back(newNode('K'));
    (root->child[0]->child).push_back(newNode('J'));
    (root->child[2]->child).push_back(newNode('G'));
    (root->child[3]->child).push_back(newNode('C'));
    (root->child[3]->child).push_back(newNode('H'));
    (root->child[3]->child).push_back(newNode('I'));
    (root->child[0]->child[0]->child).push_back(newNode('N'));
    (root->child[0]->child[0]->child).push_back(newNode('M'));
    (root->child[3]->child[2]->child).push_back(newNode('L'));
    pair <int,int> d = diameter(root);
    cout<<"Diameter:"<<d.first<<"\n";
    cout<<"Height:"<<d.second<<"\n";
    return 0;
}
