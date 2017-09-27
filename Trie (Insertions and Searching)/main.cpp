#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct trieNode
{
    bool isLeaf;
    trieNode* children[26];
};
trieNode* getNode()
{
    trieNode * temp = new trieNode();
    int i;
    for(i=0;i<26;i++)
        temp->children[i]=NULL;
    return temp;
}
void insertTrie(trieNode* root,string st)
{
    int i;
    for(i=0;i<(int)st.length();i++)
    {
        if(root->children[st[i]-'a' ]==NULL)
            root->children[ st[i]-'a' ] = getNode();
        root=root->children[ st[i]-'a' ];
    }
    root->isLeaf=true;
}

bool searchTrie(trieNode* root,string st)
{
    int i;
    for(i=0;i<(int)st.length();i++)
    {
        if(root->children[ st[i]-'a' ]==NULL)
            return false;
        root=root->children[ st[i]-'a' ];
    }
    return root->isLeaf;
}
int main()
{
    vector<string> in={"the", "a", "there","answer", "any", "by","bye", "their" };
    int i;

    trieNode * root= getNode();
    for(i=0;i<(int)in.size();i++)
        insertTrie(root,in[i]);
    cout<<searchTrie(root,"byee")<<"\n";
    cout<<searchTrie(root,"bye")<<"\n";
    return 0;
}
