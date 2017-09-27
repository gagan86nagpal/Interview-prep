#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct trieNode // General Trie node Structure
{
    bool isLeaf;  // to keep track of actual words in a trie
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
        if(root->children[st[i]-'a' ]==NULL)  // if node is not present
            root->children[ st[i]-'a' ] = getNode();    // create node
        root=root->children[ st[i]-'a' ];   // traverse the trie
    }
    root->isLeaf=true; // marking actual words
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
