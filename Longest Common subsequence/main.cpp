#include <iostream>
#include <string>
using namespace std;
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
