#include <iostream>

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
int longestPalindromicSubsequence(int s,int e)
{
    if(s==e)
        return 1;
    if(s==e+1) // penalty is 0
        return 0;
    if(s>e) // penalty is 1
        return -1;
    int i;
    int ma=-1;
    int val;
    for(i=s;i<=e;i++)
    {
        int occ=findOccur(i,e,input[i]);
        val=2+longestPalindromicSubsequence(i+1,occ-1);

        if(val>ma)
        {
            ma=val;
        }
    }
    return ma;
}
int main()
{
    cin>>input;
    int ans=longestPalindromicSubsequence(0,input.size()-1);
    cout<<ans<<"\n";
    return 0;
}
