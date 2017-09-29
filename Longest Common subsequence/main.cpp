#include <iostream>
#include <string>
using namespace std;
// if index are qeual , then recurse to subproblem of 1 index ahead
// else take two possibilities
// 1. ignore index at a string
// 2. ignore index at b string
int lcs(string a,string b,unsigned sa,unsigned sb)
{
    if(a.size()==sa || b.size()==sb)
        return 0;
    if(a[sa]==b[sb])
        return 1+lcs(a,b,sa+1,sb+1);
    else
        return max(  lcs(a,b,sa+1,sb),lcs(a,b,sa,sb+1) );
}
int main()
{
    string a,b;
    cin>>a>>b;
    int ans = lcs(a,b,0,0);
    cout<<"Length of LCS:"<<ans<<"\n";
    return 0;
}
