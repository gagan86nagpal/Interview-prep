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
    if(in==st.length() && root->isLeaf==true) // end of string
    {
        if(hasChildren(root))
        {
            root->isLeaf=false;
            return root;
        }
        else
        {
            delete root;
            return NULL;
        }
    }

    root->children[st[in]-'a']=deleteTrie(root->children[st[in]-'a'],st,in+1);
    if(hasChildren(root)||in==0)
        return root;
    else
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
    cout<<searchTrie(root,"a")<<"\n";
    root=deleteTrie(root,"answer");
    cout<<searchTrie(root,"a")<<"\n";
    cout<<searchTrie(root,"answer")<<"\n";
    return 0;
}
