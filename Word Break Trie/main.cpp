#include <iostream>

using namespace std;

struct trieNode
{
    trieNode* children[26];
    bool isWord;
};

trieNode* getNode()
{
    int i;
    trieNode* temp = new trieNode;
    for(i=0;i<26;i++)
        temp->children[i]=NULL;
    temp->isWord=false;
    return temp;
}

void insertTrie(trieNode* root,string s)
{
    int i;
    for(i=0;i<(int)s.size();i++)
    {
        int c=s[i]-'a';
        if(root->children[c]==NULL)
            root->children[c]=getNode();

        root=root->children[c];
    }
    root->isWord=true;
}
bool searchTrie(trieNode* root,string s)
{
    int i ;
    for(i=0;i<(int)s.size();i++)
    {
        int c=s[i]-'a';
        if(root->children[c]==NULL)
            return false;

        root=root->children[c];
    }
    return root->isWord;
}

int dp[100000];

// Same solution but trie is being used
// as building the dictionay as well as searching is optimal in trie

// Hashing like in Rabin Karp can also be used , giving us a far greater optimized solution
// But in the worst case , it will behave like trie solution only
bool isBreakable(trieNode*  root,string x)
{
    int i,j;
    for(i=0;i<(int)x.size();i++)
    {
        for(j=-1;j<i;j++)
        {
            if(j==-1) // check for x[0....i]
            {
                if(searchTrie(root,x.substr(0,i+1))) // found
                {
                    dp[i]=true;
                    break;
                }
            }
            else if(dp[j]==true) // check for x[j+1....i]
            {
                if(searchTrie(root,x.substr(j+1,i-j)))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
       // cout<<dp[i]<<" ";
    }
    return dp[x.size()-1];
}
int main()
{
    int n,q;
    string x;
    trieNode* root_dict=getNode();
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
       cin>>x;
       insertTrie(root_dict,x);
    }
    while(q--)
    {
        cin>>x;
        if(isBreakable(root_dict,x))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}


/*
12 2
i like sam sung samsung mobile ice cream icecream man go mango
ilike
ilikesamsung



10 1
a b c d e abc abcd bcd cde abcdef
abcdef

2 1
a aa
aaaaabaaaa
*/

