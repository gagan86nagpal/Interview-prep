#include <iostream>
#include <string>
using namespace std;
string a,b,c;
int dp[1000][1000];

void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}
bool check(unsigned sa,unsigned sb)
{
    if(sa==a.size() && sb==b.size() && sa+sb==c.size())
        return true;
    if(dp[sa][sb]!=-1)
        return dp[sa][sb];
    if(a[sa]==b[sb] && a[sa]==c[sa+sb]) // both
        dp[sa][sb]= check(sa+1,sb)||check(sa,sb+1);
    else if(a[sa]==c[sa+sb])
        dp[sa][sb]= check(sa+1,sb);
    else if(b[sb]==c[sa+sb])
        dp[sa][sb]= check(sa,sb+1);
    else
        dp[sa][sb]= false;
    return dp[sa][sb];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        init(a.size(),b.size());
        if(check(0,0))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}


/*
15
abcd xyz axybczd
AB CD CADB
AB CD CDAB
AB A AAB
A AB ABA
A AB BAA
ACA DAS DAACSA
ACA DAS DAASCA
ACA DAS ADASAC
A AB AAB
AAB AAC AACAAB
101 01 10011
101 01 11010
A C CA
A C CD
*/
