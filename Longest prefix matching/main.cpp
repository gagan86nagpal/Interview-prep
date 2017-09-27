#include <iostream>
#include <vector>
using namespace std;

// Trie NOde
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
// ret holds the index upto which a prefix is found in dictionary
int longestPrefix(trieNode* root,string st,unsigned int in=0,int ret=-1)
{
    if(root==NULL)
        return ret;
    if(in==st.length()) // end of string
    {
        if(root->isLeaf)
            return in;
        else
            return ret;
    }
    if(root->isLeaf)
        ret=in;
    return longestPrefix(root->children[st[in]-'a'],st,in+1,ret);
}
// actual method
string ans(trieNode* root,string st)
{
    int i = longestPrefix(root,st);
    if(i==-1)
        return "";
    return st.substr(0,i);
}
int main()
{
    vector < string > in = {"are", "area", "base", "cat", "cater", "children", "basement","ch"};
    unsigned int i;
    trieNode * root = getNode();
    for(i=0;i<in.size();i++)
        insertTrie(root,in[i]);
    cout<<ans(root,"cater")<<"\n";
    cout<<ans(root,"basemexy")<<"\n";
    cout<<ans(root,"child")<<"\n";
    return 0;
}
