#include <iostream>
#include <set>
#include <string>
using namespace std;
set < string> dict;
string to_search;

int dp[100000];
void init(unsigned l)
{
    for(unsigned i =0;i<=l;i++)
        dp[i]=-1;
}
bool isBreakable(unsigned index=0)
{
    if(to_search.size()==index)
    {
        dp[index]=true;
        return true;
    }

    bool flag=false;
    unsigned effective_length = to_search.size()-index;
    for(unsigned i=1;i<=effective_length;i++)
    {
        if(dp[index+i]!=-1) // use value
            flag=flag|| dp[index+i];
        else
        {
            cout<<index+i<<" ";
            if(dict.find( to_search.substr(index,i) )!=dict.end()) // found
               {
                   flag=flag|| isBreakable(index+i);
               }
        }
       if(flag)
        break;
    }
    dp[index]=flag;
    return flag;
}
int main()
{
    int n,q;
    string x;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
       cin>>x;
       dict.insert(x);
    }
    while(q--)
    {
        cin>>to_search;
        init(to_search.size());
        if(isBreakable(0))
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
*/

