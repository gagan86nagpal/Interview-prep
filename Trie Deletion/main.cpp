#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct trieNode // trie node
{
    bool isLeaf;
    trieNode* children[26];
};
trieNode* getNode() // return an empty node
{
    trieNode * temp = new trieNode();
    int i;
    for(i=0;i<26;i++)
        temp->children[i]=NULL;
    return temp;
}
// returns true if current node has any children , else false
bool hasChildren(trieNode* node)
{
    int i;
    for(i=0;i<26;i++)
        if(node->children[i])
            return true;
    return false;
}
trieNode* deleteTrie(trieNode* root,string st,int in=0)
{
    if(root==NULL)
        return NULL;
    if(in==st.length() && root->isLeaf==true) // end of string and word also exists
    {
        if(hasChildren(root))  // if it has children then just mark it as not a leaf
        {
            root->isLeaf=false;
            return root;
        }
        else  // else delete this and also make its parent pointer to NULL by recursion
        {
            delete root;
            return NULL;
        }
    }

    root->children[st[in]-'a']=deleteTrie(root->children[st[in]-'a'],st,in+1);
    if(hasChildren(root)||in==0)   // if it is the first node then do not delete it , even it doesn't have children
        return root;
    else                 // If not a first node and doesn't have any children , then delete it and make its parent pointer to NULL
    {
        delete root;
        return NULL;
    }
}
void insertTrie(trieNode* root,string st)
{
    int i;
    for(i=0;i<(int)st.length();i++)
    {
        if(root->children[st[i]-'a' ]==NULL)  // if path is not present
            root->children[ st[i]-'a' ] = getNode();        // create
        root=root->children[ st[i]-'a' ];       // traverse the trie
    }
    root->isLeaf=true;
}
// return true if st is present in trie else false
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
    cout<<searchTrie(root,"a")<<"\n";
    root=deleteTrie(root,"answer");
    cout<<searchTrie(root,"a")<<"\n";
    cout<<searchTrie(root,"answer")<<"\n";
    return 0;
}
