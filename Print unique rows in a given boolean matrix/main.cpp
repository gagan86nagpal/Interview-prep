#include <iostream>

using namespace std;

struct trieNode
{
    bool isleaf;
    trieNode* children[2];
};
trieNode* getNode()
{
    trieNode * temp = new trieNode;
    temp->isleaf=false;
    for(int i=0;i<2;i++)
        temp->children[i]=NULL;
    return temp;
}
bool insertTrie(trieNode* root,int m[4][5],int r,int c)
{
    int i;
    for(i=0;i<c;i++)
    {
        if(root->children[ m[r][i] ]==NULL)
            root->children[ m[r][i] ]=getNode();
        root=root->children[ m[r][i] ];
    }
    if(root->isleaf==false)
    {
        root->isleaf=true;
        return true;
    }
    return false;
}
void print(int **m,int r,int c)
{
    int i;
    for(i=0;i<c;i++)
        cout<<m[r][i]<<" ";
    cout<<"\n";
}
int main()
{
    int r=4,c=5;
     int m[4][5] = {{0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };

    int i;
    trieNode * root= getNode();
    for(i=0;i<r;i++)
    {
        if(insertTrie(root,m,i,c))
            print(m,i,c);
    }
    return 0;
}
