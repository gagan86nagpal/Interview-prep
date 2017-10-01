#include <iostream>
#include <utility>
using namespace std;
int m[26];
string input;
int findOccur(int s,int e,char c)
{
    int i;
    for(i=e;i>s;i--)
        if(input[i]==c)
            return i;

    return -1;
}
pair<int,string> longestPalindromicSubsequence(int s,int e)
{
    if(s>e)
        return make_pair(0,"");
    int i;
    int ma=-1;
    int val;
    string res="";
    pair < int,string> p;
    for(i=s;i<=e;i++)
    {
        int occ=findOccur(i,e,input[i]);

        if(occ==-1)  // not found
            val=1;
        else
        {
            p=longestPalindromicSubsequence(i+1,occ-1);
            val=2+p.first;
        }
        if(val>ma)
        {
            if(val!=1)
                res=input[i]+p.second+input[i];
            else
                res=(char)input[i];

            ma=val;
        }
    }
    return make_pair(ma,res);
}
int main()
{
    cin>>input;
    pair <int,string> ans=longestPalindromicSubsequence(0,input.size()-1);
    cout<<ans.second<<" "<<ans.first<<"\n";
    return 0;
}
