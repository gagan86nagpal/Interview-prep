#include <iostream>
#include <vector>
using namespace std;
struct trieNode
{
    int index;
    trieNode *children[11];
};
vector <string > domain_names; // to hold the names of domains
trieNode* getNode()
{
    trieNode* temp = new trieNode;
    temp->index=-1;
    for(int i=0;i<11;i++)
        temp->children[i]=NULL;
    return temp;
}
void insertTrie(trieNode* root,string st)
{
    for(unsigned int i=0;i<st.size();i++)
    {
        int node=st[i]-'0';
        if(st[i]=='.')
            node =10;
        if(root->children[node]==NULL)
            root->children[node]=getNode();
        root=root->children[node];
    }
    root->index=domain_names.size()-1;  // leaf node has an index to domain_names vector
}
string searchTrie(trieNode* root,string ip)
{
    for(unsigned int i=0;i<ip.size();i++)
    {
        int node=ip[i]-'0';
        if(ip[i]=='.')
            node =10;

        if(root->children[node]==NULL)
            return "";
        root=root->children[node];
    }
    if(root->index==-1)
        return "";
    return domain_names[root->index];
}
int main()
{
    int n,q,i;
    string ip,dn;
    trieNode* root = getNode();
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>ip>>dn;
        domain_names.push_back(dn);
        insertTrie(root,ip);
    }
    for(i=0;i<q;i++)
    {
        cin>>ip;
        cout<<searchTrie(root,ip)<<"\n";
    }
    return 0;
}

/*
5 4
192.168.0.1 Home
192.168.124.1  http://www.microsoft.com
8.8.8.8 Google
18.127.255.255 MIT
15.15.21.14 UK
192.168.0.1
192.168.0.0
15.15.21.14
18.127.255.255
*/
