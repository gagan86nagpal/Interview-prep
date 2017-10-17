#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
    string name;
    node* left,*right;
};

node* getNode(string name)
{
    node * temp = new node();
    temp->name=name;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
vector < pair <int,string >  > sym ; // frequency , string
node* createHuffmanTree(int n)
{
     priority_queue < pair< int , node* >, vector< pair< int , node* > >, greater< pair< int , node* > > > pq;
    pair< int , node* > p1,p2;
    int i;
    for(i=0;i<n;i++)
        pq.push(make_pair(sym[i].first,getNode(sym[i].second)));

    while(pq.size()>1)
    {
        p1 = pq.top();
        pq.pop();
        p2 = pq.top();
        pq.pop();
        node* internal_node = getNode("-1");  // to represent internal nodes
        internal_node->left= p1.second;
        internal_node->right = p2.second;
        pq.push(make_pair(p1.first+p2.first,internal_node));
    }
    return pq.top().second;
}

void inorder(node* root, string path)
{
    if(root==NULL)
        return ;
    inorder(root->left,path+"0");
    if(root->name!="-1")  // donot print internal nodes
        cout<<root->name<<" "<<path<<"\n";
    inorder(root->right,path+"1");
}
int main()
{
   int n;
   string name;
   int freq;
   int i;
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>name>>freq;
       sym.push_back(make_pair(freq,name));
   }
   sort(sym.begin(),sym.end());
   node* root=createHuffmanTree(n);
   inorder(root,"");
    return 0;
}


/*
6
a 5
b 9
c 12
d 13
e 16
f 45

*/
