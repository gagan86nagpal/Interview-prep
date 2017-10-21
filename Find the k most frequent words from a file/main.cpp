#include <iostream>
#include <queue>
#include <fstream>
#include <utility>
using namespace std;

struct trieNode
{
    trieNode* child[26];
    int cnt;
};
trieNode * getNode()
{
    trieNode* temp = new trieNode();
    int i;
    for(i=0;i<26;i++)
        temp->child[i]=NULL;
    temp->cnt=0;
    return temp;
}
void insertInTrie(trieNode * root,string st)
{
    int i;
    for(i=0;i<(int)st.size();i++)
    {
        int c = st[i]-'a';
        if(root->child[c]==NULL)
            root->child[c]=getNode();
        root= root->child[c];
    }
    root->cnt++;
}
string to_lower(string st)
{
    string ret="";
    int i;
    for(i=0;i<(int)st.size();i++)
        if(st[i]>='a'&& st[i]<='z')
            ret.push_back(st[i]);
        else
            ret.push_back(st[i]-'A'+'a');
    return ret;
}
priority_queue < pair <int,string> , vector < pair <int,string> > , greater < pair <int,string> > > pq;

void dfs(trieNode * root,string word,int k)
{
    if(root->cnt > 0)
    {
        if((int)pq.size() <k)
            pq.push(make_pair(root->cnt,word));
        else
            if(root->cnt > pq.top().first)
                pq.push(make_pair(root->cnt,word)), pq.pop();
    }
    int i;
    for(i=0;i<26;i++)
        if(root->child[i]!=NULL)
            dfs(root->child[i],word+ (char)('a'+i),k );
}
void print()
{
    while(!pq.empty())
    {
        pair <int,string > p = pq.top();
        pq.pop();
        cout<<p.second <<" : "<<p.first<<"\n";
    }
}
int main()
{
    int k;
    cin>>k;
    ifstream iff;
    string st;
    iff.open("File.txt");
    trieNode* root =getNode();
    while(iff >> st)
    {
       st = to_lower(st);
       insertInTrie(root,st);
    }
    dfs(root,"",k);
    print();
    return 0;
}
