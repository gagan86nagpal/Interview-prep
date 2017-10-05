#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int dp[1000][1000];
char gen[1000][1000];
set<string> all_lcs;
void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}

void print(string a,int n,int m,string ans="")
{
    if(n<0 || m<0)
    {
        all_lcs.insert(ans);
        return;
    }
    if(gen[n][m]==0) // stop here
        return;
    if(gen[n][m]=='u')
        print(a,n-1,m,ans);
    else if(gen[n][m]=='l')
        print(a,n,m-1,ans);
    else if(gen[n][m]=='d')
    {
       // gen[n][m]=0;// don't visit it again
        print(a,n-1,m-1,a[n]+ans);
    }
    else  // both
    {
        print(a,n-1,m,ans);
        print(a,n,m-1,ans);
    }
}
int lcs(string a,string b,int n,int m)
{
    if(n==-1 || m==-1)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(a[n]==b[m])
    {
        gen[n][m]='d';
        dp[n][m]=1+lcs(a,b,n-1,m-1);
        return dp[n][m];
    }
    int s1=lcs(a,b,n-1,m);
    int s2=lcs(a,b,n,m-1);

    if(s1>s2)
        gen[n][m]='u';
    else if(s2>s1)
        gen[n][m]='l';
    else // equal , two lcs here
        gen[n][m]='b';
    return dp[n][m]=max(s1,s2);
}
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    init(n,m);
    lcs(a,b,n-1,m-1);
    print(a,n-1,m-1);
    for(string x:all_lcs)
        cout<<x<<"\n";
    return 0;
}
