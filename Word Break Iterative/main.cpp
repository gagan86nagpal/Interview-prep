#include <iostream>
#include <set>
#include <string>
using namespace std;
set < string> dict;


int dp[100000];

bool isBreakable(string x)
{
    int i,j;
    for(i=0;i<(int)x.size();i++)
    {
        for(j=-1;j<i;j++)
        {
            if(j==-1) // check for x[0....i]
            {
                if(dict.find(x.substr(0,i+1))!=dict.end()) // found
                {
                    dp[i]=true;
                    break;
                }
            }
            else if(dp[j]==true) // check for x[j+1....i]
            {
                if(dict.find(x.substr(j+1,i-j))!=dict.end())
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
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
       cin>>x;
       dict.insert(x);
    }
    while(q--)
    {
        cin>>x;
        if(isBreakable(x))
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

